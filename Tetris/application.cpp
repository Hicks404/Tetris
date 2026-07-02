#include "application.h"

#include <ctime>
#include <iostream>
#include <random>
#include <string>

using std::function;
using std::string;
using std::rand;

namespace MathLibrary
{
	Application::Application(int _w, int _h, const char* _title) 
		: m_title{ _title }, m_width{ _w }, m_height{ _h }, closed{ false }, m_slotsize{ _h/20 },
		curBlock{ nullptr }, moveCountDown{ 0.f }, totalWeight{ 0 }
	{
		
	}

	MathLibrary::Application::~Application() {}

	int Application::Run(float runTime, const function<void()>& testStart, const function<void()>& testCompleted)
	{
		srand(static_cast<uint32_t>(time(nullptr)));

		SetConfigFlags(FLAG_WINDOW_RESIZABLE);
		InitWindow(m_width, m_height, m_title);

		if (!IsWindowReady())
		{
			return EXIT_FAILURE;
		}

		BeginPlay();

		while (!closed)
		{
			Tick(GetFrameTime());

			BeginDrawing();
			ClearBackground(RAYWHITE);

			Render();

			DrawFPS(10, 10);

			EndDrawing();

			if (WindowShouldClose())
			{
				closed = true;
			}
		}

		EndPlay();

		CloseWindow();

		return EXIT_SUCCESS;
	}

	void Application::DrawGrid()
	{
		for (int i = 0; i < gridX; ++i)
		{
			for (int j = 0; j < gridY; ++j)
			{
				if (m_grid[i][j] == 2)
				{
					DrawRectangle(i * m_slotsize, j * m_slotsize, m_slotsize, m_slotsize, GRAY);
				}

				if (m_grid[i][j] == 1)
				{
					DrawRectangle(i * m_slotsize, j * m_slotsize, m_slotsize, m_slotsize, BLUE);
				}

				DrawRectangleLines(i * m_slotsize, j * m_slotsize, m_slotsize, m_slotsize, BLACK);
			}
		}
	}

	void Application::CheckForFreeze()
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (curBlock->GetSpecShape(i, j))
				{
					int x = curBlock->GetX();
					int y = curBlock->GetY();

					if (y+i+1 >= gridY+1 || m_grid[j + x][i + y] == 1 && m_grid[j + x][i + y + 1] == 2)
					{
						curBlock->SetFreeze(true);
						return;
					}
				}
			}
		}
	}

	void Application::UpdateGrid()
	{
		if (!curBlock->GetFreeze())
		{
			SetOneGrid(0);
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (curBlock->GetSpecShape(i, j))
					{
						int x = curBlock->GetX();
						int y = curBlock->GetY();

						m_grid[j + x][i + y] = 1;
					}
				}
			}
		}
	}

	void Application::TetrisCheck()
	{
		for (int j = 0; j < gridY; ++j)
		{
			bool check = true;
			for (int i = 0; i < gridX; ++i)
			{
				if (m_grid[i][j] != 2)
				{
					check = false;
				}
			}

			if (check)
			{
				Tetris(j);
			}
		}
	}

	void Application::Tetris(int y)
	{
		// Make rows go down
		for (int j = y; j > 0; --j)
		{
			for (int i = 0; i < gridX; ++i)
			{
				m_grid[i][j] = m_grid[i][j - 1];
			}
		}

		// Make top row clear
		for (int i = 0; i < gridX; ++i)
		{
			m_grid[i][0] = 0;
		}
	}

	void Application::SetOneGrid(int set)
	{
		for (int i = 0; i < gridX; ++i)
		{
			for (int j = 0; j < gridY; ++j)
			{
				if (m_grid[i][j] == 1)
				{
					m_grid[i][j] = set;
				}
			}
		}
	}

	void Application::QueueAdd(int amount)
	{
		int totalBlocks = blockMap.size();

		for (int i = 0; i < amount; ++i)
		{
			int randomNum = rand() % totalWeight + 1;
			int choice = 0;

			for (int i = 0; i <= totalBlocks; ++i)
			{
				randomNum -= blockMap[i].weight;

				if (randomNum <= 0)
				{
					choice = i;
					break;
				}
			}

			BlockQueue.emplace_back(new Block(blockMap[choice], 5, 0));
		}
	}

	void Application::BlockSpawn()
	{
		// Get block from queue
		curBlock = new Block(BlockQueue.front()->data, 5, 0);

		// Removes from vector
		BlockQueue.erase(BlockQueue.begin());

		QueueAdd(1);
	}

	void Application::RotateBlock()
	{
		int pX = curBlock->data.pivot.x;
		int pY = curBlock->data.pivot.y;

		// store old shape
		int og[4][4];
		for (int i = 0; i < pX; ++i)
		{
			for (int j = 0; j < pY; ++j)
			{
				og[i][j] = curBlock->data.shape[i][j];
			}
		}

		// check if blocked by preexisting blocks
		for (int i = 0; i < pX; ++i)
		{
			for (int j = 0; j < pY; ++j)
			{
				if (m_grid[curBlock->GetX() + i][curBlock->GetY() + j] == 2)
				{
					return;
				}
			}
		}

		// set shape to rotated
		for (int i = 0; i < pX; ++i)
		{
			for (int j = 0; j < pY; ++j)
			{
				curBlock->data.shape[pX-1 - j][i] = og[i][j];
			}
		}

		// swaps the width and height
		curBlock->SwapDim();
	}

	void Application::xMove(int num)
	{
		for (int i = 0; i < curBlock->data.pivot.x; ++i)
		{
			for (int j = 0; j < curBlock->data.pivot.y; ++j)
			{
				int curX = curBlock->GetX() + j;
				int curY = curBlock->GetY() + i;

				if (m_grid[curX+num][curY] == 2)
				{
					return;
				}
			}
		}

		curBlock->Move(num, 0);
	}

	bool Application::IsBlockXBlocked(int x)
	{
		return false;
	}

	void Application::Controls()
	{
		//Controls
		if (IsKeyDown(KEY_DOWN) && plummetCountDown > 0.05f)
		{
			curBlock->Move(0, 1);
			plummetCountDown = 0.f;
		}

		if (IsKeyDown(KEY_LEFT) && controlCountDown > 0.1f)
		{
			xMove(-1);
			controlCountDown = 0.f;
		}

		if (IsKeyDown(KEY_RIGHT) && controlCountDown > 0.1f)
		{
			xMove(1);
			controlCountDown = 0.f;
		}
		
		if (IsKeyPressed(KEY_UP))
		{
			RotateBlock();
		}
	}

	void Application::BeginPlay()
	{
		// Set total weight of blocks
		for (std::pair<int, blockStruct> block : blockMap)
		{
			totalWeight += block.second.weight;
		}

		// Add blocks to queue
		QueueAdd(3);

		// Set grid num
		SetOneGrid(0);
	}

	void Application::Tick(float dt)
	{
		moveCountDown += dt;
		controlCountDown += dt;
		plummetCountDown += dt;

		if (curBlock == nullptr)
		{
			BlockSpawn();
		}

		if (moveCountDown > 0.5f)
		{
			curBlock->Move(0, 1);
			moveCountDown = 0.f;
		}

		Controls();

		CheckForFreeze();
		UpdateGrid();

		if (curBlock->GetFreeze())
		{
			SetOneGrid(2);
			DeletionQueue.emplace_back(curBlock);
			curBlock = nullptr;
		}

		TetrisCheck();
	}

	void Application::Render()
	{
		DrawGrid();
	}

	void Application::EndPlay()
	{
		if (curBlock)
		{
			delete curBlock;
			curBlock = nullptr;
		}

		for (Block* block : DeletionQueue)
		{
			delete block;
			block = nullptr;
		}
		
		for (Block* block : BlockQueue)
		{
			delete block;
			block = nullptr;
		}
	}
}
#include "application.h"

#include <ctime>
#include <iostream>
#include <string>

using std::function;
using std::string;
using std::rand;

namespace MathLibrary
{
	Application::Application(int _w, int _h, const char* _title) 
		: m_title{ _title }, m_width{ _w }, m_height{ _h }, closed{ false }, m_slotsize{ _h/20 },
		curBlock{ nullptr }, moveCountDown{ 0.f }
	{}

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
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
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

	void Application::UpdateGrid()
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

					if (y <= 18 && !curBlock->GetFreeze() && m_grid[i + x][j + y] != 2)
					{
						m_grid[i + x][j + y] = 1;
					}
					else
					{
						m_grid[i + x][j + y - 1] = 1;
						curBlock->SetFreeze(true);
					}
				}
			}
		}
	}

	void Application::SetOneGrid(int set)
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				if (m_grid[i][j] == 1)
				{
					m_grid[i][j] = set;
				}
			}
		}
	}

	void Application::BlockSpawn()
	{
		curBlock = new Block(blockMap[rand() % 6 + 1], 5, 0);
	}

	void Application::Controls()
	{
		//Controls
		if (IsKeyDown(KEY_S) && controlCountDown > 0.1f)
		{
			curBlock->Move(0, 1);
			controlCountDown = 0.f;
		}

		if (IsKeyDown(KEY_A) && controlCountDown > 0.1f)
		{
			curBlock->Move(-1, 0);
			controlCountDown = 0.f;
		}

		if (IsKeyDown(KEY_D) && controlCountDown > 0.1f)
		{
			curBlock->Move(1, 0);
			controlCountDown = 0.f;
		}
	}

	void Application::BeginPlay()
	{
		SetOneGrid(0);
	}

	void Application::Tick(float dt)
	{
		moveCountDown += dt;
		controlCountDown += dt;

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

		UpdateGrid();

		if (curBlock->GetFreeze())
		{
			SetOneGrid(2);
			DeletionQueue.emplace_back(curBlock);
			curBlock = nullptr;
		}
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
	}
}
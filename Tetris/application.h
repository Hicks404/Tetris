#pragma once

#include <vector>
#include <functional>
#include <unordered_map>
#include <string>
#include <raylib/raylib.h>

#include "blockdata.h"
#include "block.h"

using std::vector;
using std::function;
using std::unordered_map;
using std::string;

namespace MathLibrary
{
	class Application
	{
#pragma region FOUNDATION DO NOT MODIFY
	public:
		explicit Application(int _w, int _h, const char* _title);
		~Application();

	public:
		int Run(float runTime = 0.f, const function<void()>& testStart = nullptr, const function<void()>& testCompleted = nullptr);

	private:
		const char* m_title;
		int m_width;
		int m_height;

#pragma endregion

	private:
		void DrawGrid();

		void CheckForFreeze();
		void UpdateGrid();

		/** Detect when to tetris */
		void TetrisCheck();

		/** Clear blocks in full line */
		void Tetris(int y);

		void SetOneGrid(int set);

		/** Add block to queue */
		void QueueAdd(int amount);

		/** Spawn tetris block */
		void BlockSpawn();

		void RotateBlock();

		void xMove(int num);

		bool IsBlockXBlocked(int x);

	private:
		static const int gridX = 10;
		static const int gridY = 20;

		int m_grid[gridX][gridY];

		int m_slotsize;

		int totalWeight;

		bool closed;

		float moveCountDown;
		float plummetCountDown;
		float controlCountDown;

	private:
		vector<Block*> BlockQueue;
		vector<Block*> DeletionQueue;

		Block* curBlock;

	private:
		void Controls();

	private:
		/** Activates once at beginning. Sets up game */
		void BeginPlay();

		/** function that activates every frame */
		void Tick(float dt);

		/** Renders every tick */
		void Render();

		/** Ends game and handle deletion */
		void EndPlay();
	};
}

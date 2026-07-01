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
		void UpdateGrid();

		void SetOneGrid(int set);

		void BlockSpawn();

	private:
		int m_grid[10][20];

		int m_slotsize;

		bool closed;

		float moveCountDown;
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

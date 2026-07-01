#pragma once

#include <vector>
#include <functional>

using std::vector;

namespace MathLibrary
{
	class Application
	{
#pragma region FOUNDATION DO NOT MODIFY
	public:
		explicit Application(int _w, int _h, const char* _title);
		~Application();

	public:
		int Run(float runTime = 0.f, const std::function<void()>& testStart = nullptr, const std::function<void()>& testCompleted = nullptr);

	private:
		const char* m_title;
		int m_width;
		int m_height;

#pragma endregion

	private:
		/** Activates once at beginning. Sets up game */
		void BeginPlay();

		/** function that activates every frame */
		void Tick(float _dt);

		/** Renders every tick */
		void Render();

		/** Ends game and handle deletion */
		void EndPlay();
	};
}

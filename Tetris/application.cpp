#include "application.h"

#include <raylib/raylib.h>

#include <ctime>
#include <string>

using std::function;
using std::string;

namespace MathLibrary
{
	Application::Application(int _w, int _h, const char* _title) 
		: m_title{ _title }, m_width{ _w }, m_height{ _h }
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

			Tick(GetFrameTime());

			BeginDrawing();
			ClearBackground(RAYWHITE);

			Render();

			DrawFPS(10, 10);

			EndDrawing();
		}

	void Application::BeginPlay()
	{
		
	}

	void Application::Tick(float _dt)
	{
		
	}

	void Application::Render()
	{
		
	}

	void Application::EndPlay()
	{
		
	}

}
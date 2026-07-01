#include "application.h"

int main()
{
#if _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //enables leak detection
    _CrtSetBreakAlloc(185); //Will automatically cause break point on allocationm with matching Id
#endif

    MathLibrary::Application* app = new MathLibrary::Application(1280, 720, "Tetris");

    const int state = app->Run();

    delete app;

    return state;
}

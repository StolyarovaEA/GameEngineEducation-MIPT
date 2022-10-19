// GameEngine.cpp : Defines the entry point for the application.
//

#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include "GameEngine.h"
#include "RenderEngine.h"
#include "RenderThread.h"
#include "CubeGameObject.h"
#include "GameTimer.h"
#include "..\inih\include\INIReader.h"
#include <map>


bool is_key_pressed(int key_code)
{
    if (GetAsyncKeyState(key_code) & 0x8000)
        return true;
    else
        return false;
}

std::map<std::string, std::string> commands;
std::map<std::string, int> key_code = { {"left", VK_LEFT}, {"right", VK_RIGHT}, {"up", VK_UP}, {"down", VK_DOWN} };

void load()
{
    INIReader reader("keyconfig.ini");
    auto data = reader.GetFields("Keyboard");
    for (auto& i : data)
    {
        commands[i] = reader.Get("Keyboard", i, "");
    }
}



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    // Enable run-time memory check for debug builds.
#if defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    GameTimer timer;

    RenderEngine* renderEngine = new RenderEngine(hInstance);
    RenderThread* renderThread = renderEngine->GetRT();

    GameObject* cube = new CubeGameObject();
    renderThread->EnqueueCommand(RC_CreateCubeRenderObject, cube->GetRenderProxy());

    MSG msg = { 0 };

    timer.Start();
    timer.Reset();
    float posx = 0.0f, posy = 0.0f;
    load();
    // Main message loop:
    while (msg.message != (WM_QUIT | WM_CLOSE))
    {
        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            float t = 0;
            timer.Tick();
            t = sin(timer.TotalTime()) * 2;
            float speedx = 0.0f, speedy = 0.0f;
            for (auto& it : commands)
                if (it.second == "left" || it.second == "right" || it.second == "up" || it.second == "down")
                {
                    if (is_key_pressed(key_code[it.second]))
                    {
                        if (it.first == "Left")
                            speedx -= 0.5;
                        if (it.first == "Right")
                            speedx += 0.5;
                        if (it.first == "Up")
                            speedy += 0.5;
                        if (it.first == "Down")
                            speedy -= 0.5;
                    }
                }
                else
                {
                    char key = *it.second.c_str();
                    if (is_key_pressed(key))
                    {
                        if (it.first == "Left")
                            speedx -= 0.5;
                        if (it.first == "Right")
                            speedx += 0.5;
                        if (it.first == "Up")
                            speedy += 0.5;
                        if (it.first == "Down")
                            speedy -= 0.5;
                    }
                }
            posx += speedx * timer.DeltaTime();
            posy += speedy * timer.DeltaTime();
            cube->SetPosition(posx, 0.0f, posy);

            renderThread->OnEndFrame();
        }
    }

    return (int) msg.wParam;
}

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
#include "InputHandler.h"
#include <cstdlib>


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
    InputHandler* inputHandler = new InputHandler();


    auto cubes = std::vector<std::unique_ptr<CubeGameObject>>();
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            cubes.emplace_back(std::make_unique<CubeGameObject>());
            auto& cube = cubes.back();
            renderThread->EnqueueCommand(RC_CreateCubeRenderObject, cube->GetRenderProxy());
            int type = rand() % 3;
            cube->SetPosition(3.5f * (j - 5), 0.0f, 3.5f * i);
            cube->settype(type);
        }

    MSG msg = { 0 };

    timer.Start();
    timer.Reset();

    float newPositionX = 0.0f;
    float velocityy = 2.0f;
    float newRositionY = 0.0f;
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
            inputHandler->Update();

            float t = 0;
            timer.Tick();
            t = sin(timer.TotalTime())*2;

            float velocityx = 0.0f;
            
            for (auto& cube : cubes)
            {
                std::vector<float> pos = cube->GetPosition();
                    switch (cube->gettype())
                    {
                    case(0):
                        cube->SetPosition(pos[0] + t, pos[1], pos[2]);
                        break;
                    case(1):
                        if (inputHandler->GetInputState().test(eIC_GoLeft))
                            velocityx -= 0.01f;
                        if (inputHandler->GetInputState().test(eIC_GoRight))
                            velocityx += 0.01f;
                        newPositionX += velocityx * timer.DeltaTime();
                        cube->SetPosition(pos[0] + newPositionX, pos[1], pos[2]);
                        break;
                    case(2):
                        newRositionY += velocityy * timer.DeltaTime();
                        velocityy += -9.81f * timer.DeltaTime();
                        
                        if (pos[1] + newRositionY > 0)
                        {
                            cube->SetPosition(pos[0], pos[1] + newRositionY, pos[2]);
                        }
                        else
                        {
                            cube->SetPosition(pos[0], pos[1], pos[2]);
                            velocityy = 2.0f;
                        }
                        break;
                    default:
                        break;
                    }
             }

            renderThread->OnEndFrame();
        }
    }

    return (int) msg.wParam;
}

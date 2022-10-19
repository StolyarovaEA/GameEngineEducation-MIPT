#pragma once
#include <vector>
#include <string>
#include <memory>
#include "flecs.h"
#include "ecsSystems.h"
#include "ecsPhys.h"
#include "ecsControl.h"
#include "ecsMesh.h"
#include "../ScriptSystem/ScriptSystem.h"
#include "../ScriptSystem/ScriptProxy.h"
#include "../GameEngine/Input.h"
#include "../GameEngine/InputHandler.h"

class CScriptProxy;

struct Scripts
{
    template<typename... Args>
    Scripts(Args... args) : names{ args... } {}
    std::vector<std::string> names;
};

void init_script_state(flecs::world& ecs, std::shared_ptr<CScriptProxy> scriptProxy);
void register_ecs_script_systems(flecs::world& ecs);

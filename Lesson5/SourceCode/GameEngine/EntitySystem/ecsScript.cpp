#include "ecsScripts.h"


void register_ecs_script_systems(flecs::world& ecs)
{
    static auto scriptSystemQuery = ecs.query<ScriptSystemPtr>();
    static auto inputHandlerQuery = ecs.query<InputHandlerPtr>();
    ecs.system<Scripts>()
        .each([&](flecs::entity e, Scripts& scripts)
            {
                inputHandlerQuery.each([&](InputHandlerPtr& inputHandler) {
                    scriptSystemQuery.each([&](ScriptSystemPtr& scriptSystem)
                        {
                            for (const auto& script : scripts.names)
                            {
                                auto scriptProxy = scriptSystem.ptr->CreateProxy(script.c_str());
                                init_script_state(ecs, scriptProxy);
                                scriptProxy->BindValue("input_handler", std::ref(*inputHandler.ptr));
                                scriptProxy->BindValue("entity_id", e.id());
                            }
                        }); });
                e.remove<Scripts>();
            });
}


void init_script_state(flecs::world& ecs, std::shared_ptr<CScriptProxy> scriptProxy)
{
    sol::state& state = scriptProxy->GetState();
    state.new_usertype<Position>("Position",
        "x", &Position::x,
        "y", &Position::y,
        "z", &Position::z);
    state.new_usertype<Velocity>("Velocity",
        "x", &Velocity::x,
        "y", &Velocity::y,
        "z", &Velocity::z);
    state.new_usertype<Gravity>("Gravity",
        "x", &Gravity::x,
        "y", &Gravity::y,
        "z", &Gravity::z);
    state.new_usertype<std::bitset<eIC_Max>>("Bitset",
        "test", &std::bitset<eIC_Max>::test);
    state.new_usertype<InputHandler>("InputHandler",
        "getInputState", &InputHandler::GetInputState);
    state.new_usertype<flecs::world>("World",
        "getEntityByName", [](flecs::world& world, char* name) {return world.lookup(name); },
        "getEntity", [](flecs::world& world, flecs::entity_t id) { return world.entity(id); });
    state.new_usertype<flecs::entity>("Entity",
        "getVelocity", [](flecs::entity e) { return e.get<Velocity>(); },
        "setVelocity", [](flecs::entity e, float x, float y, float z) { e.set(Velocity{ x, y, z }); },
        "setGravity", [](flecs::entity e, float g_x, float g_y, float g_z) { e.set(Gravity{ g_x, g_y, g_z }); },
        "getPosition", [](flecs::entity e) { return e.get<Position>(); },
        "setPosition", [](flecs::entity e, float x, float y, float z) { e.set(Position{ x, y, z }); },
        "getReloadTimer", [](flecs::entity e) { return e.get<recharge>(); }),
        "getAmmo", [](flecs::entity e) {return e.get<Ammo>(); };
    state["eIC_GoLeft"] = eIC_GoLeft;
    state["eIC_GoRight"] = eIC_GoRight;
    state["eIC_GoForward"] = eIC_GoUp;
    state["eIC_GoBackward"] = eIC_GoDown;
    state["eIC_Shoot"] = eIC_Shoot;
    state["world"] = std::ref(ecs);
}
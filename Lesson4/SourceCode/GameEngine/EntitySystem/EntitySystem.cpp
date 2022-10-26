#include "EntitySystem.h"
#include "ecsSystems.h"
#include "ecsMesh.h"
#include "ecsControl.h"
#include "ecsPhys.h"
#include "xmlreader.h"
#include <functional>

EntitySystem::EntitySystem(RenderEngine* renderEngine, InputHandler* inputHandler)
{
    ecs.entity("inputHandler")
        .set(InputHandlerPtr{ inputHandler });
    ecs.entity("renderEngine")
        .set(RenderEnginePtr{ renderEngine });

    register_ecs_mesh_systems(ecs);
    register_ecs_control_systems(ecs);
    register_ecs_phys_systems(ecs);


    auto reader = XmlReader();
    reader.LoadFile("../../../Assets/xml/entity.xml");
    auto entities = reader.ParseFile();

    for (auto& entity : entities)
    {
        auto e = ecs.entity();
        for (auto component : entity)
        {
            if (component.first == "position")
            {
                auto xyz = XmlReader::ParseLine<3>(component.second);
                e.set(Position{ xyz[0], xyz[1], xyz[2] });
            }
            if (component.first == "velocity")
            {
                auto xyz = XmlReader::ParseLine<3>(component.second);
                e.set(Velocity{ xyz[0], xyz[1], xyz[2] });
            }
            if (component.first == "ammo")
            {
                auto value = std::stoi(component.second);
                e.set(Ammo{ value });
            }
            if (component.first == "friction")
            {
                auto value = std::stof(component.second);
                e.set(FrictionAmount{ value });
            }
            if (component.first == "speed")
            {
                auto value = std::stof(component.second);
                e.set(Speed{ value });
            }
            if (component.first == "recharge")
            {
                auto value = std::stof(component.second);
                e.set(recharge{ value });
            }
            if (component.first == "control")
                e.add <Controllable>();
            if (component.first == "cube_mesh")
                e.add<CubeMesh>();
        }
    }
    
    auto cubetarget = ecs.entity()
        .set(Position{ 0.f, 0.f, 0.f })
        .set(hit{ false })
        .add<CubeMesh>()
        .add<Collision>();

    auto cubetargetbonus = ecs.entity()
        .set(Position{ -3.f, 1.f, 0.f })
        .set(hit{ false })
        .set(bonus{ 4 })
        .add<CubeMesh>()
        .add<Collision>();

    auto cubeshoot = ecs.entity()
        .set(Position{ 0.f, 30.f, -15.f })
        .set(Gravity{ 0.f, 0.f, 0.f })
        .set(Velocity{ 0.f, 0.0f, 0.0f })
        .set(FrictionAmount{ 0.9f })
        .set(time_alive{ 0.f })
        .set(BouncePlane{ 0.f, 1.f, 0.f, 0.f })
        .set(Bounciness{ 0.01f })
        .set(Shoot{ true })
        .add<CubeMesh>()
        .add<Collision>();

}

void EntitySystem::Update()
{
    ecs.progress();
}
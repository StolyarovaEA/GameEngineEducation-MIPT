#include "EntitySystem.h"
#include "ecsSystems.h"
#include "ecsMesh.h"
#include "ecsControl.h"
#include "ecsPhys.h"

EntitySystem::EntitySystem(RenderEngine* renderEngine, InputHandler* inputHandler)
{
    ecs.entity("inputHandler")
        .set(InputHandlerPtr{ inputHandler });
    ecs.entity("renderEngine")
        .set(RenderEnginePtr{ renderEngine });

    register_ecs_mesh_systems(ecs);
    register_ecs_control_systems(ecs);
    register_ecs_phys_systems(ecs);

    auto shooter = ecs.entity()
        .set(Ammo{ 6 })
        .set(Position{ 0.f, 1.f, -15.f })
        .set(recharge{ 0.f })
        .set(FrictionAmount{ 0.9f })
        .set(Speed{ 1.f })
        .set(Velocity{ 0.f, 0.f,0.f })
        .add<Controllable>()
        .add<CubeMesh>();

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
        .set(Shoot{true})
        .add<CubeMesh>()
        .add<Collision>();
    
}



void EntitySystem::Update()
{
    ecs.progress();
}
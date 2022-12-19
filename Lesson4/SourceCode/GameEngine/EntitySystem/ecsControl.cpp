#include "ecsControl.h"
#include "ecsSystems.h"
#include "ecsPhys.h"
#include "ecsMesh.h"
#include "flecs.h"
#include "../InputHandler.h"
#include "soundsystem.h"

void register_ecs_control_systems(flecs::world& ecs)
{
    static auto inputQuery = ecs.query<InputHandlerPtr>();
    static auto sound = ecs.query<SoundSystemPtr>();
    ecs.system<Velocity, const Speed, const Controllable>()
        .each([&](flecs::entity e, Velocity& vel, const Speed& spd, const Controllable&)
            {
                inputQuery.each([&](InputHandlerPtr input)
                    {
                        float deltaVel = 0.f;
                        float deltaVel1 = 0.f;
                        if (input.ptr->GetInputState().test(eIC_GoLeft))
                            deltaVel -= spd;
                        if (input.ptr->GetInputState().test(eIC_GoRight))
                            deltaVel += spd;
                        if (input.ptr->GetInputState().test(eIC_GoUp))
                            deltaVel1 += spd;
                        if (input.ptr->GetInputState().test(eIC_GoDown))
                            deltaVel1 -= spd;
                        vel.x += deltaVel * e.delta_time();
                        vel.y += deltaVel1 * e.delta_time();
                    });
            });

    ecs.system<const Position, const Controllable, Ammo, recharge>()
        .each([&](const Position& pos, const Controllable&, Ammo& a, recharge& r)
            {
                inputQuery.each([&](InputHandlerPtr input)
                    {
                        if (input.ptr->GetInputState().test(eIC_Shoot) && r.val != 10.f && a.val > 0)
                        {
                            ecs.query< Shoot, Position, Velocity, Gravity >().each([&](flecs::entity e, Shoot& sh, Position& pos1, Velocity& vel, Gravity& g)
                                {
                                    if (sh.val)
                                    {
                                        pos1.x = pos.x;
                                        pos1.y = pos.y;
                                        pos1.z = pos.z;
                                        g.y = -9.81;
                                        vel.z = 50;
                                        sh.val = false;
                                        a.val -= 1;
                                    }
                                    sound.each([&](SoundSystemPtr snd)
                                        {
                                            snd.ptr->playsound("shoot");
                                        }
                                    );
                                });

                        }

                    });
            });
}
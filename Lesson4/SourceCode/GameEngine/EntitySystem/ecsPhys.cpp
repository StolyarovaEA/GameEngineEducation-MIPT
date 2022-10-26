#include "ecsPhys.h"
#include <stdlib.h>
#include <ctime>

static float rand_flt(float from, float to)
{
    return from + (float(rand()) / RAND_MAX) * (to - from);
}

void register_ecs_phys_systems(flecs::world& ecs)
{
    ecs.system<Velocity, const Gravity, BouncePlane*, Position*>()
        .each([&](flecs::entity e, Velocity& vel, const Gravity& grav, BouncePlane* plane, Position* pos)
            {
                if (plane && pos)
                {
                    constexpr float planeEpsilon = 0.1f;
                    if (plane->x * pos->x + plane->y * pos->y + plane->z * pos->z < plane->w + planeEpsilon)
                        return;
                }
                vel.x += grav.x * e.delta_time();
                vel.y += grav.y * e.delta_time();
                vel.z += grav.z * e.delta_time();
            });


    ecs.system<Velocity, Position, const BouncePlane, const Bounciness>()
        .each([&](Velocity& vel, Position& pos, const BouncePlane& plane, const Bounciness& bounciness)
            {
                float dotPos = plane.x * pos.x + plane.y * pos.y + plane.z * pos.z;
                float dotVel = plane.x * vel.x + plane.y * vel.y + plane.z * vel.z;
                if (dotPos < plane.w)
                {
                    pos.x -= (dotPos - plane.w) * plane.x;
                    pos.y -= (dotPos - plane.w) * plane.y;
                    pos.z -= (dotPos - plane.w) * plane.z;

                    vel.x -= (1.f + bounciness.val) * plane.x * dotVel;
                    vel.y -= (1.f + bounciness.val) * plane.y * dotVel;
                    vel.z -= (1.f + bounciness.val) * plane.z * dotVel;
                }
            });

    ecs.system<Velocity, const FrictionAmount>()
        .each([&](flecs::entity e, Velocity& vel, const FrictionAmount& friction)
            {
                vel.x -= vel.x * friction.val * e.delta_time();
                vel.y -= vel.y * friction.val * e.delta_time();
                vel.z -= vel.z * friction.val * e.delta_time();
            });


    ecs.system<Position, const Velocity>()
        .each([&](flecs::entity e, Position& pos, const Velocity& vel)
            {
                pos.x += vel.x * e.delta_time();
                pos.y += vel.y * e.delta_time();
                pos.z += vel.z * e.delta_time();
            });

    ecs.system<Ammo, recharge>()
        .each([&](flecs::entity e, Ammo& a, recharge& r)
            {
                if (a.val == 0 && r.val != 10.f)
                    r.val += e.delta_time();
                if (r.val >= 10.f)
                {
                    a.val = 6;
                    r.val = 0.f;
                }
            });

    ecs.system<Position, time_alive, BouncePlane, Shoot, Gravity>()
        .each([&](flecs::entity e, Position& pos, time_alive& t, BouncePlane& plane, Shoot& sh, Gravity& g)
            {
                constexpr float planeEpsilon = 1.f;
                if (abs(pos.y - plane.y) <= planeEpsilon)
                {
                    if (t.val < 2.)
                        t.val += e.delta_time();
                    if (t.val >= 2.)
                    {
                        pos.x = 0.f;
                        pos.y = 30.f;
                        pos.z = -15.f;
                        g.y = 0.f;
                        sh.val = true;
                        t.val = 0.f;
                    }
                }
            });


    ecs.system<Position, Shoot, Gravity>()
        .each([&](flecs::entity e, Position& pos, Shoot& sh, Gravity& g)
            {
                ecs.query<Position, hit>().each([&](flecs::entity e1, Position& pos1, hit& h)
                    {
                        srand(time(NULL));
                        if (abs(pos.x - pos1.x) < 2.f && abs(pos.y - pos1.y) < 2.f && abs(pos.z - pos1.z) < 2.f)
                        {
                            pos.x = 0.f;
                            pos.y = 30.f;
                            pos.z = -15.f;
                            g.y = 0.f;
                            sh.val = true;
                            pos1.x = rand() % 10;
                            pos1.y = rand() % 10;
                            pos1.z = rand() % 10;
                            if (e1.get<bonus>())
                                h.val = true;
                        }
                    });
            });

    ecs.system<Ammo>()
        .each([&](flecs::entity e, Ammo& a)
            {
                ecs.query<bonus, hit>().each([&](flecs::entity e1, bonus& b, hit& h)
                    {
                        if (h.val)
                        {
                            a.val += b.val;
                            h.val = false;
                            b.val = rand() % 10 + 1;
                        }
                    });
            });
}



#pragma once
#include "flecs.h"

struct Position
{
	float x, y, z;
};

struct Velocity
{
	float x, y, z;
};

struct Gravity
{
	float x, y, z;
};

struct BouncePlane
{
  float x,y,z,w;
};

struct Bounciness
{
  float val;
};

struct FrictionAmount
{
	float val;
};


struct Ammo
{
	int val;
};

struct time_alive
{
	float val;
};

struct recharge
{
	float val;
};

struct hit
{
	bool val;
};

struct bonus
{
	int val;
};

struct Shoot {
	bool val;
};

struct Collision {};
struct ready {};

struct ifhit {
	bool val;
};
typedef float Speed;

void register_ecs_phys_systems(flecs::world &ecs);


#pragma once
#include "flecs.h"

struct CubeMesh {};
struct Mesh1 {};
struct RenderProxyPtr
{
	class RenderProxy* ptr;
};

void register_ecs_mesh_systems(flecs::world &ecs);


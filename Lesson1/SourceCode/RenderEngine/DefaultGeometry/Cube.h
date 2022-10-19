#pragma once

#include "../RenderObject.h"

namespace
{
	struct PosColorVertex
	{
		float m_x;
		float m_y;
		float m_z;
		uint32_t m_abgr;
	};
};

class Cube : public RenderObject
{
public:
	Cube();

private:
	inline static const PosColorVertex s_cubeVertices[] =
	{
		{-0.5f,  -0.5f,  0.0f, 0xff000000}, //0
		{ 0.5f,  0.5f,  0.0f, 0xff0000ff },//1
		{ -0.5f,  0.5f,  0.0f, 0xff00ffff },//2
		{ 0.5f, -0.5f, 0.0f, 0xffffffff}, //3
		{ 0.0f, 0.0f, static_cast<float>(sqrt(2) / 2), 0xffff0000},//4
		{ 0.0f, 0.0f, static_cast<float>(-sqrt(2) / 2), 0xffffff00},//5
	};

	inline static const uint16_t s_cubeTriList[] =
	{
		0, 4, 2,
		2, 4, 1,
		1, 4, 3,
		3, 4, 0,
		2, 5, 0,
		1, 5, 2,
		3, 5, 1,
		0, 5, 3
		
	};

};


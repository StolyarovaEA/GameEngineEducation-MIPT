#pragma once

#include "Common.h"
#include "RenderProxy.h"
#include <vector>

class GameObject
{
public:
	GameObject() = default;

	~GameObject()
	{
		delete m_pRenderProxy;
	}

	void SetPosition(float x, float y, float z);
	std::vector<float> GetPosition();


	RenderProxy* const GetRenderProxy() { return m_pRenderProxy; }
protected:
	RenderProxy* m_pRenderProxy;
	
	float m_vPosition[3];
	
};


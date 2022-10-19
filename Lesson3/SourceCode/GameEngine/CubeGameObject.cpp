#include "CubeGameObject.h"
#include "../RenderEngine/CubeRenderProxy.h"

CubeGameObject::CubeGameObject()
{
	m_pRenderProxy = new CubeRenderProxy();
}

int CubeGameObject::gettype()
{
	return c_type;
}

void CubeGameObject::settype(int type)
{
	c_type = type;
}
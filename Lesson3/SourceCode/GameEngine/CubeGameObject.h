#pragma once

#include "GameObject.h"

class CubeGameObject final : public GameObject
{
public:
	CubeGameObject();
	int gettype();
	void settype(int type);
private:
	int c_type;
};


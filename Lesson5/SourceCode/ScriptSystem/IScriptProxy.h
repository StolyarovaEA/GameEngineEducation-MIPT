#pragma once
#include "Common.h"



class SCRIPTSYSTEM_API IScriptProxy
{
public:
    virtual void Execute() = 0;
};
#pragma once
#include "../GameObject/IStart.h"

class IAction : public IStart
{
public:
	virtual void DoAction() = 0;
};
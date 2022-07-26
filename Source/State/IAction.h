#pragma once
#include "../Component/IStart.h"

class IAction : public IStart
{
public:
	virtual void DoAction() = 0;
};
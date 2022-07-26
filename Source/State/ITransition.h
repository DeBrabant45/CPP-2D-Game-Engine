#pragma once
#include "../Component/IStart.h"

class ITransition : public IStart
{
public:
	virtual void PerformTransition() = 0;
	virtual bool IsAbleToTransition() = 0;
};
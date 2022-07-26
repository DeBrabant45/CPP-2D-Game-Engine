#pragma once
#include "../Component/IStart.h"
#include "../Component/IUpdate.h"

class Scene : public IStart, public IUpdate
{
public:
	virtual void ProcessInput() = 0;
};


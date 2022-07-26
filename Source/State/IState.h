#pragma once
#ifndef ISTATE_H
#define ISTATE_H
#include "../Component/IStart.h"

class IState : public IStart
{
public:
	virtual void OnEnter() = 0;
	virtual void OnUpdate() = 0;
};
#endif
#pragma once
#ifndef ISTATE_H
#define ISTATE_H
#include "StateController.h"
#include "../GameObject/IStart.h"

class StateController;

class IState : public IStart
{
public:
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
	virtual void OnUpdate() = 0;
};
#endif
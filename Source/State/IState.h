#pragma once
#ifndef ISTATE_H
#define ISTATE_H
#include "../GameObject/GameObject.h"
#include "StateController.h"

class StateController;

class IState
{
public:
	virtual void OnEnter(std::shared_ptr<GameObject> owner, StateController* controller) = 0;
	virtual void OnExit() = 0;
	virtual void OnUpdate() = 0;
};
#endif
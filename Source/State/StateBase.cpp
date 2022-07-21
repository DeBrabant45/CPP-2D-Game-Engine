#include "StateBase.h"
#include "IAction.h"
#include "ITransition.h"
#include "StateController.h"
#include "../GameObject/GameObject.h"


StateBase::StateBase(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	Owner{ owner },
	Controller{ controller }
{

}

void StateBase::Start()
{
	for (auto& action : _actions)
	{
		action->Start();
	}
	for (auto& transition : _transitions)
	{
		transition->Start();
	}
}

void StateBase::OnUpdate()
{
	DoActions();
	CheckTransitions();
}

void StateBase::DoActions()
{
	for (auto& action : _actions)
	{
		action->DoAction();
	}
}

void StateBase::CheckTransitions()
{
	for (auto& transition : _transitions)
	{
		if (transition->IsAbleToTransition())
		{
			transition->PerformTransition();
		}
	}
}

void StateBase::AddAction(std::shared_ptr<IAction> action)
{
	_actions.push_back(action);
}

void StateBase::AddTransition(std::shared_ptr<ITransition> transition)
{
	_transitions.push_back(transition);
}
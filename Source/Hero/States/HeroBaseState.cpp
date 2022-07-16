#include "HeroBaseState.h"
#include "../../State/ITransition.h"
#include "../../GameObject/GameObject.h"
#include "../../State/StateController.h"
#include "../../State/IAction.h"

HeroBaseState::HeroBaseState(std::shared_ptr<GameObject> owner, std::shared_ptr<StateController> controller) :
	Owner { owner },
	Controller { controller }
{

}

void HeroBaseState::Start()
{
	for (auto action : _actions)
	{
		action->Start();
	}
	for (auto transition : _transitions)
	{
		transition->Start();
	}
}

void HeroBaseState::OnUpdate()
{
	for (auto action : _actions)
	{
		action->DoAction();
	}
	for (auto transition : _transitions)
	{
		if (transition->IsAbleToTransition())
		{
			transition->PerformTransition();
		}
	}
}

void HeroBaseState::AddTransition(std::shared_ptr<ITransition> transition)
{
	_transitions.push_back(transition);
}

void HeroBaseState::AddAction(std::shared_ptr<IAction> action)
{
	_actions.push_back(action);
}
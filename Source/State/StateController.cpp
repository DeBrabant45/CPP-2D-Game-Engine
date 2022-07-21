#include "StateController.h"
#include "IState.h"

StateController::StateController(std::shared_ptr<GameObject> owner) :
	_owner{ owner }
{

}

void StateController::DefaultState(std::shared_ptr<IState> state)
{
	_currentState = state;
}

void StateController::Start()
{
	for (auto state : _states)
	{
		state->Start();
	}
	_currentState->OnEnter();
}

void StateController::TransitionToState(std::shared_ptr<IState> state)
{
	_currentState = state;
	_currentState->OnEnter();
}

void StateController::Update(const float& deltaTime)
{
	_currentState->OnUpdate();
}
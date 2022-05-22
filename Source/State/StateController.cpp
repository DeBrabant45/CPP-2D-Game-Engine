#include "StateController.h"
#include "IState.h"

StateController::StateController(std::shared_ptr<GameObject> owner, std::shared_ptr<IState> startState) :
	_owner{ owner },
	_currentState{ startState }
{

}

void StateController::Start()
{
	_currentState->OnEnter(_owner, this);
}

void StateController::TransitionToState(std::shared_ptr<IState> state)
{
	_currentState->OnExit();
	_currentState = state;
	_currentState->OnEnter(_owner, this);
}

void StateController::Update(const float& deltaTime)
{
	_currentState->OnUpdate();
}
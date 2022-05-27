#pragma once
#include <memory>
#include "IState.h"
#include "../Component/IComponent.h"
#include "../GameObject/GameObject.h"

class IState;

class StateController : public IComponent
{
private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<IState> _currentState{};
	std::vector<std::shared_ptr<IState>> _states{};

public:
	StateController(std::shared_ptr<GameObject> owner);
	void DefaultState(std::shared_ptr<IState> state);
	void TransitionToState(std::shared_ptr<IState> state);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
	template <typename T> void AddState(std::shared_ptr<T> newState);
	template <typename T> std::shared_ptr<T> GetState();
};

template<typename T>
inline void StateController::AddState(std::shared_ptr<T> newState)
{
	static_assert(std::is_base_of<IState, T>::value, "T must derive from State");
	_states.push_back(newState);
}

template<typename T>
inline std::shared_ptr<T> StateController::GetState()
{
	static_assert(std::is_base_of<IState, T>::value, "T must derive from State");
	for (auto& exisitingState : _states)
	{
		if (std::dynamic_pointer_cast<T>(exisitingState))
		{
			return std::dynamic_pointer_cast<T>(exisitingState);
		}
	}
	std::cout << "state does not exist!";
	return nullptr;
}
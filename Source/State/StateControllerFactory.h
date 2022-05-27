#pragma once
#include <memory>
#include "../Character/CharacterType.h"

class StateController;
class GameObject;

class StateControllerFactory
{

public:
	std::shared_ptr<StateController> CreateController(std::shared_ptr<GameObject> owner, CharacterType character);

private:
	std::shared_ptr<StateController> CreateHeroStateController(std::shared_ptr<GameObject> owner);
};
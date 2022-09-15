#pragma once
#include <vector>
#include <memory>
#include <string>
#include "../Component/IUpdate.h"
#include "../Component/IStart.h"

class GameObject;

class GameObjectRegistry : public IStart, public IUpdate
{
private:
	std::vector<std::shared_ptr<GameObject>> _gameobjects;

public:
	GameObjectRegistry() = default;
	void AddToRegistry(std::shared_ptr<GameObject> gameobject);
	void AddToRegistry(std::vector<std::shared_ptr<GameObject>> gameobjects);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
	std::shared_ptr<GameObject> GetGameObjectByTag(std::string tag);
};
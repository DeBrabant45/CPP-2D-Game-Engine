#include "GameObjectRegistry.h"
#include "GameObject.h"

void GameObjectRegistry::Start()
{
	for (auto& gameobject : _gameobjects)
	{
		gameobject->Start();
	}
}

void GameObjectRegistry::AddToRegistry(std::shared_ptr<GameObject> gameobject)
{
	_gameobjects.push_back(gameobject);
}

void GameObjectRegistry::AddToRegistry(std::vector<std::shared_ptr<GameObject>> gameobjects)
{
	for (auto& gameobject : gameobjects)
	{
		_gameobjects.push_back(gameobject);
	}
}

void GameObjectRegistry::Update(const float& deltaTime)
{
	for (auto& gameobject : _gameobjects)
	{
		if (gameobject->IsActive() != false)
		{
			gameobject->Update(deltaTime);
		}
	}
}

std::shared_ptr<GameObject> GameObjectRegistry::GetGameObjectByTag(std::string tag)
{
	for (auto& gameobject : _gameobjects)
	{
		if (gameobject->GetTag() == tag)
		{
			return gameobject;
		}
	}
}
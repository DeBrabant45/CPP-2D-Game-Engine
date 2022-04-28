#pragma once
#ifndef HEROGRAPHICSCOMPONENT_H
#define HEROGRAPHICSCOMPONENT_H
#include "../Sprite/Sprite.h"
#include "../Component/IComponent.h"
#include "HeroStateComponent.h"
#include <memory>

class Transformation;
class GameObject;
class HeroInputComponent;

class HeroGraphicsComponent : public IComponent
{

private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<HeroStateComponent> _state{};
	std::shared_ptr<Transformation> _transform{};
	std::shared_ptr<HeroInputComponent> _input{};
	int _flashTimer{};
	Sprite _idle{ LoadTexture("./Assets/Hero/hero-idle-sheet.png"), 4, 9 };
	Sprite _run{ LoadTexture("./Assets/Hero/hero-run-sheet.png"), 6, 16 };
	Sprite _fall{ LoadTexture("./Assets/Hero/hero-fall.png"), 2, 10 };
	Sprite _attack{ LoadTexture("./Assets/Hero/hero-attack-sheet.png"), 5, 16 };
	Sprite _hurt{ LoadTexture("./Assets/Hero/hero-hurt.png"), 1, 10 };

public:
	HeroGraphicsComponent(std::shared_ptr<GameObject> owner);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
};
#endif
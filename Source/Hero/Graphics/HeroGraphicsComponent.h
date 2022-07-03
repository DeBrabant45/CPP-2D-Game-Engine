#pragma once
#ifndef HEROGRAPHICSCOMPONENT_H
#define HEROGRAPHICSCOMPONENT_H
#include "../../Sprite/Sprite.h"
#include "../../Component/IComponent.h"
#include "AnimationAction.h"
#include <memory>

class Transformation;
class GameObject;

class HeroGraphicsComponent : public IComponent
{

private:
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<Transformation> _transform{};
	std::shared_ptr<Sprite> _current{};
	std::shared_ptr<Sprite> _idle = std::make_shared<Sprite>(LoadTexture("./Assets/Hero/hero-idle-sheet.png"), 4, 9 );
	std::shared_ptr<Sprite> _run = std::make_shared<Sprite>( LoadTexture("./Assets/Hero/hero-run-sheet.png"), 6, 16 );
	std::shared_ptr<Sprite> _fall = std::make_shared<Sprite>( LoadTexture("./Assets/Hero/hero-fall.png"), 2, 10 );
	std::shared_ptr<Sprite> _attack = std::make_shared<Sprite>( LoadTexture("./Assets/Hero/hero-attack-sheet.png"), 5, 16 );
	std::shared_ptr<Sprite> _hurt = std::make_shared<Sprite>( LoadTexture("./Assets/Hero/hero-hurt.png"), 1, 10 );
	std::shared_ptr<Sprite> _jump = std::make_shared<Sprite>(LoadTexture("./Assets/Hero/hero-j.png"), 2, 10);

public:
	HeroGraphicsComponent(std::shared_ptr<GameObject> owner);
	void SetGraphics(AnimationAction action);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;

};
#endif
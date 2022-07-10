#pragma once
#include <memory>
#include "../../Combat/IDamage.h"
#include "../../Component/IComponent.h"

class GameObject;
class b2World;
class Rigidbody;
class Transformation;

class HeroAttackComponent : public IComponent, public IDamage
{

private:
	float _attackDamage{};
	std::shared_ptr<GameObject> _owner{};
	std::shared_ptr<b2World> _world{};
	std::shared_ptr<Rigidbody> _rigidbody{};
	std::shared_ptr<Transformation> _transform{};

public:
	HeroAttackComponent(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;
	virtual void Inflict() override;

};


#pragma once
#include "../../../Rigidbody/Rigidbody.h"

class HellhoundRigidbody : public Rigidbody
{
public:
	HellhoundRigidbody(std::shared_ptr<GameObject> owner, std::shared_ptr<b2World> world);
	virtual void Start() override;
	virtual void Update(const float& deltaTime) override;

protected:
	virtual void CreateDefinition(Vector2 position) override;
	virtual void CreateShape(Vector2 size) override;
	virtual void CreateFixtureDefinition(uintptr_t userData) override;
};


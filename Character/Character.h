#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <memory>
#include <vector>
#include "CharacterState.h"
#include "../GameObject/IGameObject.h"
#include "../Component/IComponent.h"
#include "../Observer/ISender.h"

class Character : public IGameObject, ISender
{

private:
	std::vector<std::shared_ptr<IComponent<Character>>> _components{};
	CharacterState _currentState{ CharacterState::Idle };
	Vector2 _worldPosition{ 0.f, 0.f };
	float _lookDirection{ 1.f };
	std::vector<int> _messages;

public:
	Vector2 Velocity{ 0.f, 0.f };
	bool IsGrounded{ false };
	float AttackTimer{ 0 };
	float HurtTimer{ 0 };
	bool IsAttacking{ false };

private:
	void SetState();
	void SetLookDirection();

public:
	Character(std::vector<std::shared_ptr<IComponent<Character>>> components);
	virtual void Update(const float& deltaTime) override;
	virtual void SetPosition(Vector2& position) override;
	virtual const Vector2& GetPosition() override { return _worldPosition; }
	const float& GetLookDirection() { return _lookDirection; }
	const CharacterState& GetCurrentState() { return _currentState; }
	virtual void Send(int message) override;
};
#endif
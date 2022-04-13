#include "HeroGraphicsComponent.h"
#include "../Character/Character.h"
#include <iostream>

HeroGraphicsComponent::HeroGraphicsComponent()
{

}

void HeroGraphicsComponent::Update(Character& character, const float& deltaTime)
{
	switch (character.GetCurrentState())
	{
		case CharacterState::Run:
			_run.Draw(deltaTime, character.GetPosition(), character.GetLookDirection());
			break;
		case CharacterState::Jump:
			_fall.Draw(deltaTime, character.GetPosition(), character.GetLookDirection());
			break;
		case CharacterState::Attack:
			_attack.Draw(deltaTime, character.GetPosition(), character.GetLookDirection());
			break;
		case CharacterState::Hurt:
			_hurt.Draw(deltaTime, character.GetPosition(), character.GetLookDirection());
			break;
		case CharacterState::Idle:
			_idle.Draw(deltaTime, character.GetPosition(), character.GetLookDirection());
			break;
	}
}

void HeroGraphicsComponent::Receive(int message)
{
}

#pragma once
#ifndef IUPDATE_H
#define IUPDATE_H

class IUpdate 
{
public:
	virtual void Update(const float& deltaTime) = 0;
};
#endif
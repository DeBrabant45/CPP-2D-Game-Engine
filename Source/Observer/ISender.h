#pragma once
class ISender
{
public:
	virtual void Send(int message) = 0;
};
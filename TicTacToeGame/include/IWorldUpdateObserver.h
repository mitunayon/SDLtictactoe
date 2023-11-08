#pragma once
class IWorldUpdateObserver
{
public:
	virtual ~IWorldUpdateObserver() {};
	virtual void OnWorldUpdate() = 0;
};
#pragma once
class IImageRendererObserver
{
public:
	virtual ~IImageRendererObserver() {};
	virtual void OnRenderUpdate() = 0;
};
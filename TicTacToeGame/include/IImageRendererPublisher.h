#pragma once
#include "IImageRendererObserver.h"
class IImageRendererPublisher
{
public:
	virtual ~IImageRendererPublisher() {};
	virtual void Attach(IImageRendererObserver* observer) = 0;
	virtual void Detach(IImageRendererObserver* observer) = 0;
	virtual void Notify() = 0;
};
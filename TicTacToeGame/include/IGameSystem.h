#pragma once
class IGameSystem
{
public:
    IGameSystem() {}
    virtual ~IGameSystem() {}

    // "= 0" part makes this method pure virtual, and also makes this class abstract.
    virtual void PreUpdate() = 0;
    virtual void Update() = 0;    
    virtual void PostUpdate() = 0;
};




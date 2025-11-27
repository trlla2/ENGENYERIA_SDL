#pragma once
#include <vector>
#include "Object.h"

class Scene
{
protected:
	std::vector<Object*> _objects;
	std::vector<Object*> _ui;
public:
	virtual void OnEnter() = 0;
	virtual void OnExit();
	virtual void Update(float dt);
	virtual void Render();
};


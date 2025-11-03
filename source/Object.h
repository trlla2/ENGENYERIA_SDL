#pragma once
#include "Transform.h"
#include "Renderer.h"
#include <SDL3/SDL.h>
#include <string>

class Object
{
private:
	bool _isPendingDestroy = false;
protected:
	Transform* _transform;
	Renderer* _renderer = nullptr;

public:
	Object() { _transform = new Transform(); }
	~Object() 
	{ 
		delete _transform;
		_transform = nullptr;

		delete _renderer;
		_renderer = nullptr;
	}

	bool IsPendingDestroy() const { return _isPendingDestroy; }
	virtual void Destroy() { _isPendingDestroy = true; }
	Transform* GetTransform() { return _transform; }
	virtual void Update() { _renderer->Update(0.02f); } // 50 fps
	virtual void Render() { _renderer->Render(); }
};

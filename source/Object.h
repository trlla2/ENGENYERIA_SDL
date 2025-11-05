#pragma once
#include "Transform.h"
#include "Renderer.h"
#include "RigidBody.h"
#include <SDL3/SDL.h>
#include <string>

class Object
{
private:
	bool _isPendingDestroy = false;
protected:
	Transform* _transform;
	Renderer* _renderer = nullptr;
	RigidBody* _physics;

public:
	Object() 
	{ 
		_transform = new Transform(); 
		_physics = new RigidBody(_transform);
	}
	~Object() 
	{ 
		delete _transform;
		_transform = nullptr;

		delete _renderer;
		_renderer = nullptr;

		delete _physics;
		_physics = nullptr;
	}

	bool IsPendingDestroy() const { return _isPendingDestroy; }
	virtual void Destroy() { _isPendingDestroy = true; }

	Transform* GetTransform() { return _transform; }
	RigidBody* GetRigidBody() { return _physics; }

	virtual void Update() 
	{ 
		if (_physics != nullptr)
			_physics->Update(0.02f);

		_renderer->Update(0.02f); 
	} // 50 fps
	virtual void Render() { _renderer->Render(); }
};

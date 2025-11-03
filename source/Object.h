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

	void SetPosition(Vector2 position) { // ----------- ? en el manual3 no sale
		_transform->_position = position;
		_renderer->SetDestinationRect({ _transform->_position.x, _transform->_position.y, 100.f, 100.f });
	}
	bool IsPendingDestroy() const { return _isPendingDestroy; }
	virtual void Destroy() { _isPendingDestroy = true; }
	Transform* GetTransform() { return _transform; }
	virtual void Update() { _renderer->Update(/* FPS????? */); }
	virtual void Render(SDL_Renderer* renderer) { _renderer->Render(renderer); } // pq le passas un renderer (manual no?)
};

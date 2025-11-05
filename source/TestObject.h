#pragma once
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"

class TestObject : public ImageObject
{
public:
	TestObject()
		: ImageObject("resources/Richard_Hebert.jpg", Vector2(0.f, 0.f), Vector2(306.f, 562.f))
	{
		// Posició random en tota la finestra
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->_position = randomPosition;
		_transform->_scale = Vector2(0.5f, 0.5f);
		_transform->_rotation = 30.f;

		_physics->SetLinearDrag(0.1f);
		_physics->SetAngularDrag(0.1f);
	}

	void Update() {
		if (IM->GetEvent(SDLK_S, DOWN))
			_physics->AddForce(Vector2(0.f, 20.f));

		else if (IM->GetEvent(SDLK_R, DOWN))
			_physics->AddTorque(20.f);

		Object::Update();
	}
};
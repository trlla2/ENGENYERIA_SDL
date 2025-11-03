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
	}

	void Update() {
		if (IM->GetEvent(SDLK_S, DOWN))
			_transform->_position.y += 0.05;
		Object::Update();
	}
};
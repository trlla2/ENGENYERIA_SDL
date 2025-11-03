#pragma once
#include "ImageObject.h"
#include "RenderManager.h "
class TestObject : public ImageObject
{
public:
	TestObject()
		: ImageObject("source/Richard_Hebert.png", Vector2(0.f, 0.f), Vector2(306.f, 562.f))
	{
		// Posició random en tota la finestra
		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->_position = randomPosition;
		_transform->_scale = Vector2(0.5f, 0.5f);
		_transform->_rotation = 30.f;
	}
};
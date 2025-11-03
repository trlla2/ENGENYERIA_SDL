#pragma once
#include "Vector2.h"

class Transform
{
public:
	Vector2 _position;
	float _rotation;
	Vector2 _scale;
	Vector2 _size;

	Transform()
		: _position(Vector2(0.f, 0.f)), _rotation(0.f), _scale(Vector2(1.f, 1.f)), _size(Vector2(100.f, 100.f)) {}

	Transform(Vector2 position, float rotation, Vector2 scale, Vector2 size)
		: _position(position), _rotation(rotation), _scale(scale), _size(size) {}
};


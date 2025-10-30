#pragma once
#include "Vector2.h"

class Transform
{
public:
	Vector2 _posititon;
	float _rotation;
	Vector2 _scale;

	Transform()
		: _posititon(Vector2(0.f, 0.f)), _rotation(0.f), _scale(Vector2(0.f, 0.f)) {}
	Transform(Vector2 position, float rotation, Vector2 scale)
		: _posititon(position), _rotation(rotation), _scale(scale) {}
};


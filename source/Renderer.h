#pragma once
#include "Transform.h"

#include <SDL3/SDL.h>
#include <string>


class Renderer
{
protected:
	Transform* _transform;
	SDL_Color _color;
	SDL_FRect _sourceRect;
	SDL_FRect _destinationRect;
	std::string _resourcePath;

public:
	Renderer(Transform* transform, std::string resourcePath)
		: _transform(transform), _resourcePath(resourcePath) {}
	virtual void LoadTexture(std::string path, SDL_Renderer* renderer) = 0 ;
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;
	virtual void SetDestinationRect(SDL_FRect rect) {
		_destinationRect = rect;
	}

	void SetColor(SDL_Color color) { _color = color; }
	SDL_Color GetColor() { return _color; }


};
#include "ImageRenderer.h"
#include "RenderManager.h"

#include <cassert>
#include <SDL3_image/SDL_Image.h>

ImageRenderer::ImageRenderer(Transform* transform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize)
	: Renderer(transform, resourcePath)
{
	RM->GetTexture(resourcePath);

	_sourceRect = SDL_FRect
	{
		sourceOffset.x,
		sourceOffset.y,
		sourceSize.x,
		sourceSize.y
	};
	
	_destinationRect = SDL_FRect
	{
		transform->_position.x,
		transform->_position.y,
		transform->_scale.x,
		transform->_scale.y
	};
}

void ImageRenderer::Update()
{
	Vector2 offset = (Vector2(-_transform->_size.x, -_transform->_size.y) / 2.0f) * _transform->_scale;
	
	_destinationRect.x = _transform->_position.x + offset.x;
	_destinationRect.y = _transform->_position.y + offset.y;
	
	_destinationRect.w = _transform->_size.x * _transform->_scale.x;
	_destinationRect.h = _transform->_size.y * _transform->_scale.y;
}

void ImageRenderer::Render(SDL_Renderer* renderer)
{
	SDL_RenderTextureRotated(RM->GetRenderer(), RM->GetTexture(_resourcePath), &_sourceRect, &_destinationRect
		, _transform->_rotation, NULL, SDL_FLIP_NONE);
}

void ImageRenderer::LoadTexture(std::string path, SDL_Renderer* renderer) // ... ????
{
	//_texture = IMG_LoadTexture(renderer, path.c_str());
	//assert(_texture);

	//_sourceRect = { 0.f, 0.f, (float)_texture->w,(float)_texture->h };

}

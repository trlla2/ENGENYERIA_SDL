#include "TextRenderer.h"
#include "RenderManager.h"

void TextRenderer::Update(float dt)
{
	Vector2 offset = (Vector2(-_transform->_size.x, -_transform->_size.y) / 2.0f) * _transform->_scale;

	_destinationRect.x = _transform->_position.x + offset.x;
	_destinationRect.y = _transform->_position.y + offset.y;

	if (_autoSize)
	{
		_destinationRect.w = _sourceRect.w * _transform->_scale.x;
		_destinationRect.h = _sourceRect.h * _transform->_scale.y;
	}
	else
	{
		_destinationRect.w = _transform->_size.x * _transform->_scale.x;
		_destinationRect.h = _transform->_size.y * _transform->_scale.y;
	}
}

void TextRenderer::Render()
{
	SDL_RenderTextureRotated(RM->GetRenderer(), _texture, &_sourceRect, &_destinationRect
		, _transform->_rotation, NULL, SDL_FLIP_NONE);
}

void TextRenderer::SetText(std::string text)
{
	if(_texture != nullptr)
		SDL_DestroyTexture(_texture);
	
	SDL_Surface* surf = TTF_RenderText_Solid(
		RM->GetFont(_resourcePath),
		text.c_str(),
		text.length(),
		_color
	);
	assert(surf);

	_texture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surf);
	assert(_texture);

	_sourceRect = SDL_FRect { 0.f, 0.f, (float)surf->w, (float)surf->h };

	_text = text;
}

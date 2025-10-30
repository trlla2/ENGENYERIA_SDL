#include "ImageRenderer.h"


#include <cassert>
#include <SDL3_image/SDL_Image.h>

void ImageRenderer::Update()
{
}

void ImageRenderer::Render(SDL_Renderer* renderer)
{
	SDL_RenderTexture(renderer, _texture, &_sourceRect, &_destinationRect);
}

void ImageRenderer::LoadTexture(std::string path, SDL_Renderer* renderer)
{
	_texture = IMG_LoadTexture(renderer, path.c_str());
	assert(_texture);

	_sourceRect = { 0.f, 0.f, (float)_texture->w,(float)_texture->h };

}

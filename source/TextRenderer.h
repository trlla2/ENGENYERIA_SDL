#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <cassert>
#include "Renderer.h"

#define FONT_PATH "resources/fonts/hyperspace.ttf"

class TextRenderer : public Renderer
{
public:
	
	TextRenderer(Transform* transform, std::string text = "")
		: Renderer(transform, FONT_PATH)
	{
		SetText(text);	
	}
	~TextRenderer()
	{
		SDL_DestroyTexture(_texture);
		_texture = nullptr;
	}

	virtual void Update(float dt) override;
	
	virtual void Render() override;

	void SetColor(SDL_Color color) override
	{
		Renderer::SetColor(color);
		SetText(_text);
	}

	void SetText(std::string text);
	
protected:
	std::string _text;
	SDL_Texture* _texture;
	bool _autoSize = true;
};


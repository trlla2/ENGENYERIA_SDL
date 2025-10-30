#pragma once
#include "Renderer.h"
#include "Vector2.h"

class ImageRenderer : public Renderer
{
public:
	void Update() override;

	void Render(SDL_Renderer* renderer) override;


	void LoadTexture(std::string path, SDL_Renderer* renderer) override;

};


#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <map>
#include <string>

#define RM RenderManager::GetInstance()

class RenderManager
{
public:
	static RenderManager* GetInstance() 
	{
		static RenderManager instance;
		return &instance;
	}


	const unsigned int WINDOW_WIDTH = 512;
	const unsigned int WINDOW_HEIGHT = 512;

	void Init();
	void Release();
	void CLearScreen();
	void RenderScreen();

	SDL_Renderer* GetRenderer() { return _renderer; }
	void LoadTexture(std::string path);
	SDL_Texture* GetTexture(std::string path);

	void LoadFont(std::string path);
	TTF_Font* GetFont(std::string path);


private:
	RenderManager() = default;
	RenderManager(RenderManager&) = default;
	~RenderManager();

	SDL_Window* _window;
	SDL_Renderer* _renderer;
	std::map<std::string, SDL_Texture*> _textures;
	std::map<std::string, TTF_Font*> _fonts;

	void InitSDL();
	void CreateWindowAndRenderer();
};


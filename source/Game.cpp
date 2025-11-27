#include "Game.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "Gameplay.h"
#include <cassert>

void Game::Init()
{
	RM->Init();
	SDL_SetRenderDrawColor(RM->GetRenderer(), 254, 0, 0, 0xFF);

	RM->LoadTexture("resources/Richard_Hebert.jpg");
	RM->LoadFont("resources/fonts/hyperspace.ttf");

	assert(SM.AddScene("Gameplay", new Gameplay()));

	assert(SM.InitFirstScene("Gameplay"));


	_isRunning = true;
}
void Game::HandleEvents()
{
	_isRunning = !IM->Listen();
}
void Game::Update()
{
	SM.UpdateCurrentScene(TIME.GetDeltaTime());
}
void Game::Render()
{
	RM->CLearScreen();

	SM.GetCurrentScene()->Render();

	RM->RenderScreen();
}

void Game::Release()
{
	RM->Release();
	SDL_Quit();
}

bool Game::IsRunning() const
{
	return _isRunning;
}

void Game::InitSDL()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		throw SDL_GetError();
}

void Game::CreateWindowAndRenderer()
{
	if (!SDL_CreateWindowAndRenderer(
		"Test",
		512, 512,
		SDL_WINDOW_RESIZABLE,
		&_window,
		&_renderer
	))
		throw SDL_GetError();
}

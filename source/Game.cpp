#include "Game.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "TestObject.h "
#include "InputManager.h"

void Game::Init()
{
	RM->Init();
	SDL_SetRenderDrawColor(RM->GetRenderer(), 254, 0, 0, 0xFF);

	RM->LoadTexture("resources/Richard_Hebert.jpg");

	TestObject* test1 = new TestObject();
	_gameObjects.push_back(test1);
	TestObject* test2 = new TestObject();
	_gameObjects.push_back(test2);

	_isRunning = true;
}
void Game::HandleEvents()
{
	_isRunning = !IM->Listen();
}
void Game::Update()
{
	for (Object* go : _gameObjects)
		go->Update();
}
void Game::Render()
{
	RM->CLearScreen();

	for (Object* go : _gameObjects)
		go->Render();

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

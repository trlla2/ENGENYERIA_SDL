#include "Game.h"
#include "ImageObject.h"
#include "RenderManager.h"
#include "TestObject.h "

void Game::Init()
{
	RM->Init();
	CreateWindowAndRenderer();

	RM->LoadTexture("source/Richard_Herbert.png");

	TestObject test1 = TestObject();
	_gameObjects.push_back(&test1);
	TestObject test2 = TestObject();
	_gameObjects.push_back(&test2);

	_isRunning = true;
}
void Game::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
		if (event.type == SDL_EVENT_QUIT)
			_isRunning = false;
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
		go->Render(_renderer);

	RM->RenderScreen();
}

void Game::Release()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
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

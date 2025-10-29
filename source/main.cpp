#include <SDL3/SDL.h>
#include <exception>
#include <iostream>

int main() {

	bool _isRunning;
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;


	try 
	{
		if (!SDL_Init(SDL_INIT_VIDEO))
			throw SDL_GetError();

		if (!SDL_CreateWindowAndRenderer(
			"Test",
			512, 512,
			SDL_WINDOW_RESIZABLE,
			&_window,
			&_renderer
		))
			throw SDL_GetError();

		SDL_SetRenderDrawColor(_renderer, 254,0,0,0xFF);

		_isRunning = true;
	}
	catch (std::exception& e)
	{
		SDL_DestroyRenderer(_renderer);
		SDL_DestroyWindow(_window);
		SDL_Quit();
		return -1;
	}
	
	while (_isRunning) 
	{
		SDL_Event event;

		while (SDL_PollEvent(&event)) 
			if(event.type == SDL_EVENT_QUIT)
				_isRunning = false;

		SDL_RenderClear(_renderer);
		SDL_RenderPresent(_renderer);
	}
	
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();

	return 0;
}
#include "Game.h"
#include "RenderManager.h"

#include <SDL3/SDL.h>
#include <exception>
#include <iostream>

int main() 
{


	RM->SayHi();




	Game game;


	try 
	{
		game.Init();
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what();
		game.Release();
		return -1;
	}
	
	while (game.IsRunning()) 
	{
		game.HandleEvents();
		game.Update();
		game.Render();
	}
	
	game.Release();

	return 0;
}
#include "TimeManager.h"
#include "Game.h"
#include "RenderManager.h"


#include <SDL3/SDL.h>
#include <exception>
#include <iostream>

int main() 
{
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
	
	bool playing = true;

	while (playing) 
	{
		TIME.Update();
		std::cout << "Delta Time: " << TIME.GetDeltaTime()  << std::endl;
		if (TIME.ShouldUpdateGame())
		{
			game.HandleEvents();
			game.Update();
			game.Render();
			TIME.ResetDeltaTime();
		}
	}
	
	game.Release();

	return 0;
}
#include "GameFacade.hpp"

int main()
{
	GameFacade game;
	game.InitializeGame();

	while (game.IsWindowOpen())
	{
		game.PollEvents();
		game.UpdateGame();
		game.Render();
	}
	return 0;
}

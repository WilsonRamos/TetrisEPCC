#include "GameFacade.hpp"

#include "Board.hpp"
#include "UI/UIFrame.hpp"
#include "SoundManager.hpp"

#include <fstream>
#include <SFML/Graphics.hpp>

GameFacade::GameFacade()
	: board(Board::GetInstance()), // Inicializar la instancia única aquí
	  soundManager(SoundManager::GetInstance()), // Inicializar con la instancia única
	  uiFrame(new UIFrame()), score(0), maxScore(0), isAlive(true),
	  window(new sf::RenderWindow(sf::VideoMode(400, 400), "Tetris")),
	  right(false), left(false), up(false)
{
	window->setFramerateLimit(60);
}

GameFacade::~GameFacade()
{
	board.Cleanup();
	soundManager.Cleanup();
	delete window;
	delete uiFrame;
}

void GameFacade::InitializeGame()
{
	board.SpawnShape();

	std::ifstream in("maxScore.txt");
	in >> maxScore;
	uiFrame->SetMaxScore(maxScore);
	uiFrame->SetScore(score);

	soundManager.PlayMusic();
}

void GameFacade::PollEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}

void GameFacade::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !up)
	{
		board.RotatePart();
		up = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		up = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		board.UpdateLimitTimer(5);
	}
	else
	{
		board.UpdateLimitTimer(30);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !right)
	{
		board.Right();
		right = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		right = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !left)
	{
		board.Left();
		left = true;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		left = false;
	}
}

void GameFacade::UpdateGame()
{
	if (!isAlive)
	{
		return;
	}

	HandleInput();
	if (board.UpdateBoard())
	{
		if (!board.SpawnShape())
		{
			isAlive = false;
			board.ClearBoard();
			soundManager.PauseMusic();
			if (score > maxScore)
			{
				uiFrame->NewScore();
				std::ofstream out("maxScore.txt");
				out << score;
				soundManager.PlayNewScore();
			}
			else
			{
				uiFrame->GameOver();
				soundManager.PlayGameOver();
			}
		}
	}
	board.UpdateBoardColors();
	int newScore = board.CheckLine() * 5;
	score += newScore;
	uiFrame->SetScore(score);
	if (newScore > 0)
		soundManager.PlayLine();
}

void GameFacade::Render()
{
	window->clear(sf::Color(20, 20, 20));
	window->draw(board);
	window->draw(*uiFrame);
	window->display();
}

bool GameFacade::IsWindowOpen() const
{
	return window->isOpen();
}

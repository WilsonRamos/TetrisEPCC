#include "UIFrame.hpp"

#include <iostream>

UIFrame::UIFrame()
{
	if (!font.loadFromFile("res/font/ka1.ttf"))
	{
		std::cerr << "Error al cargar fuente de texto" << std::endl;
	}

	scoreTextTitle.setFont(font);
	scoreTextTitle.setFillColor(sf::Color::White);
	scoreTextTitle.setPosition(sf::Vector2f(235, 25));
	scoreTextTitle.setString("Score");

	maxScoreTextTitle.setFont(font);
	maxScoreTextTitle.setFillColor(sf::Color::White);
	maxScoreTextTitle.setPosition(sf::Vector2f(225, 200));
	maxScoreTextTitle.setString("Max Score");
	maxScoreTextTitle.setCharacterSize(18);

	scoreText.setFont(font);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(sf::Vector2f(250, 70));

	maxScoreText.setFont(font);
	maxScoreText.setFillColor(sf::Color::White);
	maxScoreText.setPosition(sf::Vector2f(250, 245));

	byText.setFont(font);
	byText.setFillColor(sf::Color::White);
	byText.setPosition(sf::Vector2f(260, 370));
	byText.setString("EPCC.UNSA");
	byText.setCharacterSize(15);

	gameOverText.setFont(font);
	gameOverText.setFillColor(sf::Color::White);
	gameOverText.setPosition(sf::Vector2f(8, 150));
	gameOverText.setString("Game Over");
	gameOverText.setCharacterSize(25);

	newScoreText.setFont(font);
	newScoreText.setFillColor(sf::Color::White);
	newScoreText.setPosition(sf::Vector2f(8, 150));
	newScoreText.setString("New Score");
	newScoreText.setCharacterSize(25);
}

void UIFrame::SetScore(int x)
{
	if (x <= 9)
		scoreText.setString("000" + std::to_string(x));
	else if (x <= 99)
		scoreText.setString("00" + std::to_string(x));
	else if (x <= 999)
		scoreText.setString("000" + std::to_string(x));
	else if (x <= 9999)
		scoreText.setString(std::to_string(x));
	else
		scoreText.setString("9999");
}

void UIFrame::SetMaxScore(int x)
{
	if (x <= 9)
		maxScoreText.setString("000" + std::to_string(x));
	else if (x <= 99)
		maxScoreText.setString("00" + std::to_string(x));
	else if (x <= 999)
		maxScoreText.setString("000" + std::to_string(x));
	else if (x <= 9999)
		maxScoreText.setString(std::to_string(x));
	else
		maxScoreText.setString("9999");
}

void UIFrame::GameOver()
{
	gameOver = 1;
}

void UIFrame::NewScore()
{
	newScore = 1;
}

void UIFrame::draw(sf::RenderTarget& rt, sf::RenderStates rs) const
{
	rt.draw(scoreTextTitle, rs);
	rt.draw(scoreText, rs);
	rt.draw(maxScoreTextTitle, rs);
	rt.draw(maxScoreText, rs);
	rt.draw(byText, rs);
	if (gameOver)
		rt.draw(gameOverText, rs);
	if (newScore)
		rt.draw(newScoreText, rs);
}

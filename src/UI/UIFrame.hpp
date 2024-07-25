#pragma once

#include <SFML/Graphics.hpp>

class UIFrame : public sf::Drawable
{
public:
	UIFrame();
	void SetScore(int);
	void SetMaxScore(int);
	void GameOver();
	void NewScore();

	virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;

private:
	sf::Font font;
	sf::Text scoreTextTitle;
	sf::Text scoreText;
	sf::Text maxScoreTextTitle;
	sf::Text maxScoreText;
	sf::Text byText;
	sf::Text gameOverText;
	sf::Text newScoreText;
	bool newScore = 0;
	bool gameOver = 0;
};

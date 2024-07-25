// Header guard: #ifndef GAME_FACADE_HPP...
#pragma once // Esta cabecera debe ser incluida una sola vez (reemplazo de header guard)

namespace sf { class RenderWindow; }

class GameFacade
{
public:
	GameFacade();
	~GameFacade();

	void InitializeGame();
	void PollEvents();
	void UpdateGame();
	void Render();

	bool IsWindowOpen() const;

private:
	void HandleInput();

private:
	// Puntertos a miembros para aplicar el patrón DIP y no
	// crear dependencias fuertes a módulos de bajo nivel
	class Board& board; // Declarar la referencia sin inicializar
	class SoundManager& soundManager; // Usar referencia para la instancia única

	class UIFrame* uiFrame;
	sf::RenderWindow* window;

	int score;
	int maxScore;
	bool isAlive;
	bool right, left, up;
};

#pragma once

#include <SFML/Graphics.hpp>

class Board : public sf::Drawable
{
public:
	// Método estático para obtener la instancia única
	static Board& GetInstance();

	///////////////////
	bool SpawnShape();
	bool UpdateBoard();
	void UpdateBoardColors();
	void UpdateLimitTimer(int l);
	void RotatePart();
	void Right();
	void Left();
	int CheckLine();
	void ClearBoard();
	void Cleanup(); // Método para limpiar recursos

	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

private:
	// Parts parts;
	std::unique_ptr<class ShapeFactory> shapeFactory;

	int newPartID, indColorNewPart;
	sf::Color newPartColor;

	int xIndex, yIndex;

	int timer = 0;
	int limitTimer = 30;

	int board[20][10];
	sf::RectangleShape boardVisualShapes[20][10];

	/////////////////////////////
	// Constructor privado para el Singleton
	Board();

	// Deshabilitar el constructor de copia y el operador de asignación
	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;
	/////////////////////////////////
};

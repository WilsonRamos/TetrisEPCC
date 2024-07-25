#include "Board.hpp"

#include "ShapeFactory.hpp"
#include "Shapes/ShapeBase.hpp"
#include "Shapes/ShapeTypes.hpp"

#include <ctime>
#include <cstring>
#include <iostream>

Board::Board()
	: shapeFactory(std::make_unique<ShapeFactory>())
{
	memset(board, 0, sizeof(board));
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			boardVisualShapes[i][j] = sf::RectangleShape(sf::Vector2f(20.0f, 20.0f)); // Conversión explícita a float
			boardVisualShapes[i][j].setPosition(static_cast<float>(j * 20), static_cast<float>(i * 20)); // Conversión explícita a float
			boardVisualShapes[i][j].setFillColor(sf::Color(50, 50, 50));
			boardVisualShapes[i][j].setOutlineThickness(2);
			boardVisualShapes[i][j].setOutlineColor(sf::Color(0, 0, 0));
		}
	}
}

// Implementación del método getInstance
Board& Board::GetInstance()
{
	static std::unique_ptr<Board> instance(new Board());
	return *instance;
}

bool Board::SpawnShape()
{
	srand(static_cast<unsigned int>(time(nullptr))); // Conversión explícita a unsigned int
	newPartID = rand() % ShapeBase::GetShapeTypesCount();

	const ShapeBase* const shape = shapeFactory->SpawnShapeByID(newPartID);

	int sz = (int)shape->getDataMatrix().size();

	yIndex = 0;
	xIndex = 5 - sz / 2;

	for (int i = 0; i < sz; ++i)
	{
		for (int j = 0; j < sz; ++j)
		{
			if (shape->getDataMatrix()[i][j])
			{
				if (board[i][j + xIndex] > 0)
					return false;
				board[i][j + xIndex] = -1;
			}
		}
	}

	int color = 1 + rand() % 7;
	indColorNewPart = color;

	switch (color)
	{
	case 1:
		newPartColor = sf::Color(255, 166, 0);
		break;
	case 2:
		newPartColor = sf::Color(245, 152, 245);
		break;
	case 3:
		newPartColor = sf::Color(51, 204, 153);
		break;
	case 4:
		newPartColor = sf::Color(255, 110, 110);
		break;
	case 5:
		newPartColor = sf::Color(255, 204, 77);
		break;
	case 6:
		newPartColor = sf::Color(166, 166, 255);
		break;
	case 7:
		newPartColor = sf::Color(138, 194, 247);
		break;
	}
	return true;
}

bool Board::UpdateBoard()
{
	bool limit = 0;
	int aux;

	if (timer >= limitTimer)
	{
		aux = 0;
		for (int i = 18; i >= 0; i--)
		{
			for (int j = 0; j < 10; j++)
			{
				if (board[i][j] == -1)
				{
					if (board[i + 1][j] <= 0)
						aux++;
				}
			}
		}

		if (aux == 4)
		{
			yIndex++;
			for (int i = 18; i >= 0; i--)
			{
				for (int j = 0; j < 10; j++)
				{
					if (board[i][j] == -1)
					{
						board[i][j] = 0;
						board[i + 1][j] = -1;
					}
				}
			}
		}
		else
		{
			for (int i = 19; i >= 0; i--)
			{
				for (int j = 0; j < 10; j++)
				{
					if (board[i][j] == -1)
						board[i][j] = indColorNewPart;
				}
			}
			limit = 1;
		}

		timer = 0;
	}

	timer++;
	return limit;
}

void Board::UpdateBoardColors()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			switch (board[i][j])
			{
			case 0:
				boardVisualShapes[i][j].setFillColor(sf::Color(50, 50, 50));
				break;
			case 1:
				boardVisualShapes[i][j].setFillColor(sf::Color(255, 166, 0));
				break;
			case 2:
				boardVisualShapes[i][j].setFillColor(sf::Color(245, 152, 245));
				break;
			case 3:
				boardVisualShapes[i][j].setFillColor(sf::Color(51, 204, 153));
				break;
			case 4:
				boardVisualShapes[i][j].setFillColor(sf::Color(255, 110, 110));
				break;
			case 5:
				boardVisualShapes[i][j].setFillColor(sf::Color(255, 204, 77));
				break;
			case 6:
				boardVisualShapes[i][j].setFillColor(sf::Color(166, 166, 255));
				break;
			case 7:
				boardVisualShapes[i][j].setFillColor(sf::Color(138, 194, 247));
				break;
			default:
				boardVisualShapes[i][j].setFillColor(newPartColor);
				break;
			}
		}
	}
}

void Board::UpdateLimitTimer(int l)
{
	limitTimer = l;
}

void Board::RotatePart()
{
	shapeFactory->RotateShape(newPartID);
	const ShapeBase* const shape = shapeFactory->SpawnShapeByID(newPartID);

	int sz = (int)shape->getDataMatrix().size();

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (shape->getDataMatrix()[i][j])
			{
				if (yIndex + i < 0 || yIndex + i >= 20 || xIndex + j < 0 || xIndex + j >= 10 || board[yIndex + i][xIndex + j] > 0)
				{
					shapeFactory->UnrotateShape(newPartID);
					return;
				}
			}
		}
	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == -1)
				board[i][j] = 0;
		}
	}

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (shape->getDataMatrix()[i][j])
			{
				board[i + yIndex][j + xIndex] = -1;
			}
		}
	}
}

void Board::Right()
{
	int aux = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == -1)
			{
				if (board[i][j + 1] <= 0)
				{
					aux++;
				}
			}
		}
	}

	if (aux == 4)
	{
		xIndex++;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 9; j >= 0; j--)
			{
				if (board[i][j] == -1)
					board[i][j] = 0, board[i][j + 1] = -1;
			}
		}
	}
}

void Board::Left()
{
	int aux = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (board[i][j] == -1)
			{
				if (board[i][j - 1] <= 0)
				{
					aux++;
				}
			}
		}
	}

	if (aux == 4)
	{
		xIndex--;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (board[i][j] == -1)
					board[i][j] = 0, board[i][j - 1] = -1;
			}
		}
	}
}

int Board::CheckLine()
{
	int aux = 0, lines = 0;

	for (int i = 19; i >= 0; i--)
	{
		aux = 0;
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] > 0)
				aux++;
			if (lines > 0)
				board[i + lines][j] = board[i][j], board[i][j] = 0;
		}
		if (aux == 10)
		{
			for (int j = 0; j < 10; j++)
				board[i][j] = 0;
			lines++;
		}
	}

	return lines;
}

void Board::ClearBoard()
{
	memset(board, 0, sizeof(board));
}

void Board::draw(sf::RenderTarget& rt, sf::RenderStates rs) const
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			rt.draw(boardVisualShapes[i][j], rs);
		}
	}
}

void Board::Cleanup()
{
	// Limpiar recursos aquí si es necesario
}

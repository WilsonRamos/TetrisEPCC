#pragma once

#include <vector>

class ShapeBase
{
public:
	ShapeBase(const std::vector<std::vector<bool>>& inDataMatrix);

	inline const std::vector<std::vector<bool>>& getDataMatrix() const { return dataMatrix; }

	void Rotate();
	void Unrotate();

	static unsigned int GetShapeTypesCount();

protected:
	static unsigned int RegisterShapeType();

private:
	std::vector<std::vector<bool>> dataMatrix;

	static unsigned int nextShapeID;
};

template <typename T>
class GenericShape : public ShapeBase
{
public:
	GenericShape(const std::vector<std::vector<bool>>& inDataMatrix);

public:
	static const unsigned int ID;
	static const unsigned int SIZE;
};

#include "ShapeBase.inl"

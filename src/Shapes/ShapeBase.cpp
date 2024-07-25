#include "ShapeBase.hpp"

unsigned int ShapeBase::nextShapeID = 0;

unsigned int ShapeBase::RegisterShapeType()
{
	return nextShapeID++;
}

ShapeBase::ShapeBase(const std::vector<std::vector<bool>>& inDataMatrix)
	: dataMatrix(inDataMatrix)
{
}

void ShapeBase::Rotate()
{
	std::vector<std::vector<bool>> vAux = dataMatrix;
	int indI = 0, indJ = 0;
	int sz = (int)dataMatrix.size();
	for (int i = 0; i < sz; ++i)
	{
		for (int j = sz - 1; j >= 0; --j)
		{
			dataMatrix[indI][indJ] = vAux[j][i];
			++indJ;
		}
		++indI;
		indJ = 0;
	}
}

void ShapeBase::Unrotate()
{
	std::vector<std::vector<bool>> vAux = dataMatrix;
	int indI = 0, indJ = 0;
	int sz = (int)dataMatrix.size();
	for (int i = sz - 1; i >= 0; --i)
	{
		for (int j = 0; j < sz; ++j)
		{
			dataMatrix[indI][indJ] = vAux[j][i];
			++indJ;
		}
		++indI;
		indJ = 0;
	}
}

unsigned int ShapeBase::GetShapeTypesCount()
{
	return nextShapeID;
}

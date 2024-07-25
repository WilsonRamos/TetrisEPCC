#pragma once

#include "ShapeBase.hpp"

class SquareShape : public GenericShape<SquareShape>
{
public:
	SquareShape();
};

class Thunder01Shape : public GenericShape<Thunder01Shape>
{
public:
	Thunder01Shape();
};

class Thunder02Shape : public GenericShape<Thunder02Shape>
{
public:
	Thunder02Shape();
};

class SemiT01Shape : public GenericShape<SemiT01Shape>
{
public:
	SemiT01Shape();
};

class SemiT02Shape : public GenericShape<SemiT02Shape>
{
public:
	SemiT02Shape();
};

class FlippedTShape : public GenericShape<FlippedTShape>
{
public:
	FlippedTShape();
};

class LineShape : public GenericShape<LineShape>
{
public:
	LineShape();
};

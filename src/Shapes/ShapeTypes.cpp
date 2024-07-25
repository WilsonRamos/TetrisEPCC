#include "ShapeTypes.hpp"

SquareShape::SquareShape()
	: GenericShape<SquareShape>({{1,1},
								 {1,1}})
{
}

Thunder01Shape::Thunder01Shape()
	: GenericShape<Thunder01Shape>({{0,0,0,0,0},
									{0,0,1,0,0},
									{0,0,1,1,0},
									{0,0,0,1,0},
									{0,0,0,0,0}})
{
}

Thunder02Shape::Thunder02Shape()
	: GenericShape<Thunder02Shape>({{0,0,0,0,0},
									{0,0,0,1,0},
									{0,0,1,1,0},
									{0,0,1,0,0},
									{0,0,0,0,0}})
{
}

SemiT01Shape::SemiT01Shape()
	: GenericShape<SemiT01Shape>({{0,0,0,0,0},
								  {0,0,1,1,0},
								  {0,0,1,0,0},
								  {0,0,1,0,0},
								  {0,0,0,0,0}})
{
}

SemiT02Shape::SemiT02Shape()
	: GenericShape<SemiT02Shape>({{0,0,0,0,0},
								  {0,1,1,0,0},
								  {0,0,1,0,0},
								  {0,0,1,0,0},
								  {0,0,0,0,0}})
{
}

FlippedTShape::FlippedTShape()
	: GenericShape<FlippedTShape>({{0,0,0,0,0},
								   {0,0,1,0,0},
								   {0,0,1,1,0},
								   {0,0,1,0,0},
								   {0,0,0,0,0}})
{
}

LineShape::LineShape()
	: GenericShape<LineShape>({{0,0,1,0},
							   {0,0,1,0},
							   {0,0,1,0},
							   {0,0,1,0}})
{
}

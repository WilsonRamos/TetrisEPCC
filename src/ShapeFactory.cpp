#include "ShapeFactory.hpp"

#include "Shapes/ShapeTypes.hpp"

ShapeFactory::ShapeFactory()
{
	shapesPool = {
		new SquareShape,
		new Thunder01Shape,
		new Thunder02Shape,
		new SemiT01Shape,
		new SemiT02Shape,
		new FlippedTShape,
		new LineShape
	};
}

ShapeFactory::~ShapeFactory()
{
	for (ShapeBase* shape : shapesPool)
	{
		delete shape;
	}
}

const ShapeBase* const ShapeFactory::SpawnShapeByID(unsigned int id) const
{
	return shapesPool[id];
}

void ShapeFactory::RotateShape(unsigned int index)
{
	shapesPool[index]->Rotate();
}

void ShapeFactory::UnrotateShape(unsigned int index)
{
	shapesPool[index]->Unrotate();
}

#pragma once

#include <vector>

class ShapeFactory
{
public:
	ShapeFactory();
	~ShapeFactory();

	const class ShapeBase* const SpawnShapeByID(unsigned int id) const;

	void RotateShape(unsigned int index);
	void UnrotateShape(unsigned int index);

private:
	std::vector<class ShapeBase*> shapesPool;
};

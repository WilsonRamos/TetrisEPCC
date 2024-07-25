template <typename T>
const unsigned int GenericShape<T>::ID{ ShapeBase::RegisterShapeType() };

template <typename T>
const unsigned int GenericShape<T>::SIZE{ sizeof(T) };

template<typename T>
inline GenericShape<T>::GenericShape(const std::vector<std::vector<bool>>& inDataMatrix)
	: ShapeBase(inDataMatrix)
{
	GenericShape<T>::ID;
}

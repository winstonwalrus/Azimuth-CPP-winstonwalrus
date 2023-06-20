#pragma once

template<typename OBJECT, enum TYPE>
class Factory
{
public:
	virtual OBJECT* Create(TYPE _type) = 0;

};
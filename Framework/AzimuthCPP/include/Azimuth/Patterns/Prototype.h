#pragma once

template<typename TYPE>
class Prototype
{
public:
	virtual TYPE* Clone() = 0;

};
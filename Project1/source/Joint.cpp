
#include "Joint.h"

Joint::Joint(int num, string type)
{
	this->num = num;
	this->type = type;
}

float Joint::getValue()
{
	return this->value;
}

void Joint::setValue(float value)
{
	this->value = value;
}
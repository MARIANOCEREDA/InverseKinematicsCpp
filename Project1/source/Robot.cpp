
#include "../headers/Robot.h"

Robot::Robot(double** dhM, double** toolM, double** baseM, double** T)
{
	this->dh = dhM;
	this->tool = toolM;
	this->base = baseM;
	this->T = T;
}


#pragma once

#include "../headers/Joint.h"

class Robot
{
private:
	double **dh; //Denavit-Hartenverg matrix
	double **tool; //Tool matrix (end effector)
	double **base; //Base matrix (identity in the simplest case)
	double **T; // Homogenous matrix containing the x,y,z point to achieve.
	double *qoffest;
public:
	Robot(double**,double**,double**,double**);
};
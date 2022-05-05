#pragma once

#include "../headers/Joint.h"
#include "../headers/Point.h"
#include <string>
using namespace std;

#define M_PI 3.141592653589793238462643383279502884

class Robot
{
private:
	string name;
public:
	Robot(string name);
	Point calculatePosition(double** base,double** tool,double** T);
};
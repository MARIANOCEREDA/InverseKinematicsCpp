#pragma once
#include <string>
using namespace std;

class Joint
{
private:
	int num;
	string type;
	float value;
public:
	Joint(int,string);
	float getValue();
	void setValue(float);
};


#pragma once
class API
	/**
	*@description: API from server side. It receives the data from the cliente. The data includes the x,y,z coordinates
	* for the end effector
	*/
{
private:
	int xfinal, yfinal, zfinal;
public:
	API();
	void connect();
	void receiveData();
	void disconnect();
};
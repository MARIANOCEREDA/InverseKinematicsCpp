#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "../paho.mqtt/paho.mqtt/src/MQTTClient.h"

#define ADDRESS     "tcp://broker.emqx.io:1883"
#define CLIENTID    "emqx_test"
#define TOPIC       "testtopic/1"
#define PAYLOAD     "Hello World!"
#define QOS         1
#define TIMEOUT     10000L

/**
* @name -> API
* @type -> class
* @description -> API class that connects the HMI in python with the robot in C++.
*/

class API
{
private:
	int xfinal, yfinal, zfinal;
	MQTTClient client;
public:
	API();
	MQTTClient connect();
	void disconnect();
	void publish();
	void subscribe();
};
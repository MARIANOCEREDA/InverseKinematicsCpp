#include "../headers/API.h"

API::API() {}

/**
* @name -> connect
* @type -> method
* @return void -> MQTTClient
* @description -> Connects the client and server.
*/

MQTTClient API::connect() {

    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;

    MQTTClient_create(&client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);

    // MQTT Connection parameters
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }

    // Publish message
    pubmsg.payload = PAYLOAD;
    pubmsg.payloadlen = strlen(PAYLOAD);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    printf("Waiting for up to %d seconds for publication of %s\n"
        "on topic %s for client with ClientID: %s\n",
        (int)(TIMEOUT / 1000), PAYLOAD, TOPIC, CLIENTID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);

    // Disconnect
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return client;
}

void API::disconnect()
{

}


void API::publish()
{

}

void API::subscribe()
{

}
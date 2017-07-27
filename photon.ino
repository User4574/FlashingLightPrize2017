#include <MQTT.h>

bool bulb = false;

void callback(char* topic, byte* payload, unsigned int length);

MQTT client("server.flashinglightprize.nathan.uk0.bigv.io", 1883, callback);

void callback(char* topic, byte* payload, unsigned int length) {
    char p[length + 1];
    memcpy(p, payload, length);
    p[length] = NULL;

    if (!strcmp(p, "0")) {
        bulb = !bulb;
        if (bulb) {
            digitalWrite(D0, HIGH);
        } else {
            digitalWrite(D0, LOW);
        }
    }
}


void setup() {
    pinMode(D0, OUTPUT);
    client.connect("bulb");
    if (client.isConnected()) {
        client.subscribe("ring/0");
    }
}

void loop() {
    if (client.isConnected())
        client.loop();
}

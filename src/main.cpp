#include <Arduino.h>
#include <BluetoothSerial.h>
#include <FS.h>
#include <Root.h>
#include <Graph.h>
#include <SPIFFS.h>
#include <Data.h>
#include <AMapping.h>

#define DEVICE_NAME "ESP32"

File *roverPathFile;
File *roverColisionsFile;

BluetoothSerial SerialBT;

void setup()
{
    Serial.begin(115200);
    SerialBT.begin(DEVICE_NAME);
    SPIFFS.begin();

    while (!SerialBT)
    {
        delay(100);
        Serial.println("Aguardando conexão Bluetooth...");
    }

    Serial.println("Conectado ao Bluetooth!");
}

void loop()
{

    // Se houver dados disponíveis no Bluetooth, receba-os
    // idle
    if (SerialBT.available())
    {
        char data = SerialBT.read();
        switch (data)
        {
        case 'n': //new root
            Graph *roverPath = newRoot();
            Graph *roverColisions = newRoot();
            pathGenerator(roverPathFile, roverColisionsFile);
            break;
        case 'm': //automatic mapping
            auto
            break;
        default:
            break;
        }

        // Imprima os dados recebidos no console serial
        Serial.println(data);
    }
}
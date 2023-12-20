#include <Arduino.h>
#include <BluetoothSerial.h>
#include <FS.h>
#include <Root.h>
#include <Graph.h>
#include <SPIFFS.h>
#include <Data.h>
#include <AMapping.h>
#include <ESP32Servo.h>

#define DEVICE_NAME "ESP32"
#define PINO_SERVO 25
#define PINO_TRIGGER_SEN1 23
#define PINO_ECHO_SEN1 22
#define PINO_TRIGGER_SEN2 34
#define PINO_ECHO_SEN2 35

File *roverPathFile;
File *roverColisionsFile;
BluetoothSerial SerialBT;
Servo motor;
Ultrasonic sen1(PINO_TRIGGER_SEN1, PINO_ECHO_SEN1);
Ultrasonic sen2(PINO_TRIGGER_SEN2, PINO_ECHO_SEN2);
Graph *roverPath;
Graph *roverColisions;
TaskHandle_t mappingTaskHandle = NULL;

void automaticMappingTask(void *arg) {
    automaticMapping(roverPathFile, roverColisionsFile, roverPath, roverColisions, &motor, &sen1, &sen2);
    vTaskDelay(100);
}

void setup()
{
    Serial.begin(115200);
    SerialBT.begin(DEVICE_NAME);
    SPIFFS.begin();

    motor.attach(PINO_SERVO);

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
    /*if (SerialBT.available())
    {
        char data = SerialBT.read();
        switch (data)
        {
        case 'n': // new root
            roverPath = newRoot(false);
            roverColisions = newRoot(true);
            pathGenerator(roverPathFile, roverColisionsFile);
            break;
        case 'm':                                                                                                 // automatic mapping
            if(mappingTaskHandle == NULL) {
                xTaskCreatePinnedToCore(automaticMappingTask, "automaticMappingTask", 10240, NULL, 10, &mappingTaskHandle, tskNO_AFFINITY);
            }
            break;
        case 'd':
            vTaskDelay(NULL);
            break;
        default:
            break;
        }

        // Imprima os dados recebidos no console serial
        Serial.println(data);
    }*/
    for(int i=0; i<180; i++) {
        motor.write(i);
        delay(200);
    }
}
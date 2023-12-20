#ifndef AMAPPING_H
#define AMAPPING_H

#include <FS.h>
#include <SPIFFS.h>
#include <ESP32Servo.h>
#include <Ultrasonic.h>

void automaticMapping(File *pathing, File *colisions, Graph *pathingGraph, Graph *colisionsGraph, Servo *motor, Ultrasonic *sen1, Ultrasonic *sen2);

#endif
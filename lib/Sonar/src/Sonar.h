#ifndef SONAR_H
#define SONAR_H

#include <stdio.h>
#include <stdlib.h>
#include <Servo.h>
#include <Ultrasonic.h>
#include <Graph.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <Servo.h>
#include <Ultrasonic.h>
#include <Graph.h>
#include <math.h>

double radAngle(double degree);

void checkSpace(Servo *motor, Ultrasonic *sen1, Ultrasonic *sen2, Graph *colisions, Node *position, double *longPathPossible, double *freePath);

#endif
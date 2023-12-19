#include <stdio.h>
#include <stdlib.h>
#include <Servo.h>
#include <Ultrasonic.h>
#include <Graph.h>
#include <math.h>

double radAngle(double degree)
{
    return (M_PI * degree) / 180.0;
}

// Supondo que 200m seja o limite de detecção
void checkSpace(Servo *motor, Ultrasonic *sen1, Ultrasonic *sen2, Graph *colisions, Node *position, double *longPathPossible, double *freePath)
{
    double maxFreeDistance = -1.0;
    for (double i = 0.0; i < 180.0; i++)
    {
        double d1 = sen1->read();
        if (d1 < 200.0)
        {
            if (d1 > maxFreeDistance) {
                maxFreeDistance = d1;
                *longPathPossible = i;
            }
            double d1Degree = radAngle(i);
            double d1X = position->x + (d1 * d1Degree);
            double d1Y = position->y + (d1 * d1Degree);
            add_node(colisions, (colisions->num_nodes) + 1, d1X, d1Y);
        } else {
            *freePath = i;
        }

        double d2 = sen2->read();
        if (d2 < 200.0)
        {
            if (d2 > maxFreeDistance) {
                maxFreeDistance = d2;
                *longPathPossible = i+180.0;
            }
            double d2Degree = radAngle(i + 180.0);
            double d2X = position->x + (d2 * d2Degree);
            double d2Y = position->y + (d2 * d2Degree);
            add_node(colisions, (colisions->num_nodes) + 1, d2X, d2Y);
        } else {
            *freePath = i+180.0;
        }

        motor->write(i);
    }
}
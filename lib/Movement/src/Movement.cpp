#include <math.h>
#include <Sonar.h>

double xPosition(double x0, double d, int angle) {
    double rad = radAngle(angle);
    return (x0 + (d * cos(rad)));
}
double yPosition(double y0, double d, int angle) {
    double rad = radAngle(angle);
    return (y0 + (d * sin(rad)));
}
void goFront() {
    
}

void rotate(int angle) {

}
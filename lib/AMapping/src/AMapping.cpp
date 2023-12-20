#include <stdio.h>
#include <stdlib.h>

#include <Movement.h>
#include <Sonar.h>
#include <FS.h>
#include <SPIFFS.h>
#include <ArduinoJson.h>
#include <jsonManager.h>
#include <Servo.h>
#include <Ultrasonic.h>

void automaticMapping(File *pathing, File *colisions, Graph *pathingGraph, Graph *colisionsGraph, Servo *motor, Ultrasonic *sen1, Ultrasonic *sen2)
{
    const size_t capacity = JSON_OBJECT_SIZE(2) + MAX_NODES * JSON_OBJECT_SIZE(3) + MAX_EDGES * JSON_OBJECT_SIZE(3); // tamanho da instância json
    DynamicJsonDocument dataPathInstance(capacity);                                                                  // instância json do caminho
    DynamicJsonDocument dataColisionInstance(capacity);                                                              // instância json das colisões

    for (unsigned i = 0; /*infinity*/; i++)
    {
        int *longPathPossible = NULL;
        int *freePath = NULL;
        Node *position = &pathingGraph->nodes[pathingGraph->num_nodes];
        double maxFreeDistance = 0.0;
        maxFreeDistance = checkSpace(motor, sen1, sen2, colisionsGraph, position, longPathPossible, freePath);
        if (freePath != NULL)
        {
            rotate(*freePath);
            double x = xPosition(position->x, 200.0, *freePath);
            double y = yPosition(position->y, 200.0, *freePath);
            add_node(pathingGraph, pathingGraph->nodes[pathingGraph->num_nodes].id + 1, x, y);
            add_edge(pathingGraph, position->id, pathingGraph->nodes[pathingGraph->num_nodes].id, *freePath);
        }
        else if (longPathPossible != NULL)
        {
            rotate(*longPathPossible);
            double x = xPosition(position->x, maxFreeDistance, *longPathPossible);
            double y = yPosition(position->y, maxFreeDistance, *longPathPossible);
            add_node(pathingGraph, pathingGraph->nodes[pathingGraph->num_nodes].id + 1, x, y);
            add_edge(pathingGraph, position->id, pathingGraph->nodes[pathingGraph->num_nodes].id, *longPathPossible);
        }
        else
        {
            rotate((int(pathingGraph->edges[pathingGraph->num_edges - 1].angle) + 180) % 360);
        }
        goFront();
        if (i % 5 == 0)
        {
            saveGraphToJson(pathingGraph, dataPathInstance);
            saveGraphToJson(pathingGraph, dataColisionInstance);
            String pathingString;
            String colisionString;
            serializeJson(dataPathInstance, pathingString);
            serializeJson(dataColisionInstance, colisionString);
            pathing->print(pathingString);
            colisions->print(colisionString);
        }
    }
}
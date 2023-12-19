#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <Graph.h>
#include <ArduinoJson.h>

void saveGraphToJson(Graph *graph, JsonDocument &doc);

void loadGraphFromJson(Graph *graph, JsonDocument &doc);

#endif
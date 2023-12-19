#include <Graph.h>
#include <ArduinoJson.h>

void saveGraphToJson(Graph *graph, JsonDocument &doc)
{
    doc["num_nodes"] = graph->num_nodes;
    doc["num_nodes"] = graph->num_nodes;

    JsonArray nodesArray = doc.createNestedArray("nodes");
    for (unsigned i = 0; i < graph->num_nodes; i++)
    {
        JsonObject nodeObj = nodesArray.createNestedObject();
        nodeObj["id"] = graph->nodes[i].id;
        nodeObj["x"] = graph->nodes[i].x;
        nodeObj["y"] = graph->nodes[i].y;
    }

    JsonArray edgesArray = doc.createNestedArray("edges");
    for (unsigned i = 0; i < graph->num_edges; i++)
    {
        JsonObject edgeObj = edgesArray.createNestedObject();
        edgeObj["id"] = graph->edges[i].from;
        edgeObj["x"] = graph->edges[i].to;
        edgeObj["y"] = graph->edges[i].angle;
    }
}

void loadGraphFromJson(Graph *graph, JsonDocument &doc)
{
    graph->num_nodes = doc["num_nodes"];
    graph->num_edges = doc["num_edges"];

    JsonArray nodesArray = doc["nodes"];
    for (unsigned i = 0; i < graph->num_nodes; i++)
    {
        JsonObject nodeObj = nodesArray[i];
        graph->nodes[i].id = nodeObj["id"];
        graph->nodes[i].x = nodeObj["x"];
        graph->nodes[i].y = nodeObj["y"];
    }

    JsonArray edgesArray = doc["edges"];
    for (unsigned i = 0; i < graph->num_edges; i++)
    {
        JsonObject edgeObj = edgesArray[i];
        graph->edges[i].from = edgeObj["from"];
        graph->edges[i].to = edgeObj["to"];
        graph->edges[i].angle = edgeObj["angle"];
    }
}
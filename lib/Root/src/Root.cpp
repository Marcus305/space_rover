#include "Root.h"
#include <Graph.h>

Graph *newRoot() {
    Graph newGraph;
    init_graph(&newGraph);
    add_node(&newGraph, 0, 0.0, 0.0);
    return &newGraph;
}
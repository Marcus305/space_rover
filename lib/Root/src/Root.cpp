#include "Root.h"
#include <Graph.h>

Graph *newRoot(bool colision) {
    Graph newGraph;
    init_graph(&newGraph);
    
    if(!colision)
        add_node(&newGraph, 0, 0.0, 0.0);

    return &newGraph;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Graph.h"


void init_graph(Graph *graph) {
  graph->num_nodes = 0;
  graph->num_edges = 0;
}

void add_node(Graph *graph, unsigned id, double x, double y) {
  graph->nodes[graph->num_nodes].id = id;
  graph->nodes[graph->num_nodes].x = x;
  graph->nodes[graph->num_nodes].y = y;
  graph->num_nodes++;
}

void add_edge(Graph *graph, unsigned from, unsigned to, double angle) {
  graph->edges[graph->num_edges].from = from;
  graph->edges[graph->num_edges].to = to;
  graph->edges[graph->num_edges].angle = angle;
  graph->num_edges++;
}

void update_pose(Graph *graph, unsigned node_id, double x, double y) {
  graph->nodes[node_id].x = x;
  graph->nodes[node_id].y = y;
}
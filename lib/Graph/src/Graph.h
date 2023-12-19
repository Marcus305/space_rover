#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 800
#define MAX_EDGES 300

typedef struct Node {
  unsigned id;
  double x;
  double y;
}Node;

typedef struct Edge {
  unsigned from;
  unsigned to;
  double angle;
}Edge;

typedef struct Graph {
  Node nodes[MAX_NODES];
  Edge edges[MAX_EDGES];
  unsigned num_nodes;
  unsigned num_edges;
}Graph;

void init_graph(Graph *graph);

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

#endif
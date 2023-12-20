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
  unsigned from; //inverte
  unsigned to; //real
  double angle;
}Edge;

typedef struct Graph {
  Node nodes[MAX_NODES];
  Edge edges[MAX_EDGES];
  unsigned num_nodes;
  unsigned num_edges;
}Graph;

void init_graph(Graph *graph);

void add_node(Graph *graph, unsigned id, double x, double y);

void add_edge(Graph *graph, unsigned from, unsigned to, double angle);

void update_pose(Graph *graph, unsigned node_id, double x, double y);

#endif
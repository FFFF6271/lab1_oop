#ifndef EDGES_H
#define EDGES_H

#include "oop3d.h"

typedef int edge_t[2];

struct edges_arr {
    edge_t *arr = NULL;
    int N_e = 0;
};

edges_arr init_edges();
int edges_allocate_arr(edges_arr &edges);
int edges_free_arr(edges_arr &edges);

int edges_load_arr(edges_arr &edges, input_stream &stream, int max_vertex);
int edges_load(edge_t& p, input_stream &stream, int max_vertex);

int get_edges_count(const edges_arr & edges);

int edges_get_start(const edges_arr &edges, int i);
int edges_get_end(const edges_arr &edges, int i);

edge_t *model_get_edges_arr(const edges_arr &edges);

#endif // EDGES_H

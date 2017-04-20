#include "oop3d.h"

#define BUFF_SIZE 100

static int edges_check_number_vertext(int n, int min_n, int max_n)
{
    return n >= min_n && n <= max_n;
}

edges_arr init_edges()
{
    edges_arr edges;
    edges.arr = NULL;
    edges.N_e = 0;
    return edges;
}

int edges_load_arr(edges_arr &edges, input_stream &stream, int max_vertex)
{
    int N;
    int ret = 0;
    ret = read_stream(N, stream);
    if(ret) {
        return ret;
    }
    edges.N_e = N;
    ret = edges_allocate_arr(edges);

    for(int i = 0; i < N && !ret; i++) {
        ret = edges_load(edges.arr[i], stream, max_vertex);
    }
    if(ret) {
        edges_free_arr(edges);
    }
    return ret;
}

int edges_load(edge_t &p, input_stream &stream, int max_vertex)
{
    int x, y;
    int ret = read_stream(x, stream);
    if(!ret)
        ret = read_stream(y, stream);
    if(!(edges_check_number_vertext(x, 1, max_vertex) && edges_check_number_vertext(y, 1, max_vertex))) {
        return FILE_ERROR;
    }

    if(!ret) {
        p[0] = x - 1;
        p[1] = y - 1;
    }
    return ret;
}

int edges_allocate_arr(edges_arr &edges)
{
    edges.arr = new edge_t [edges.N_e];
    if(!(edges.arr))
        return MEMORY_ERROR;
    return 0;
}

int edges_free_arr(edges_arr &edges)
{
    if(edges.arr)
        delete[] edges.arr;
    edges.arr = NULL;
    edges.N_e = 0;
    return 0;
}

int get_edges_count(const edges_arr & edges)
{
    return edges.N_e;
}

int edges_get_start(const edges_arr &edges, int i) {
    return edges.arr[i][0];
}

int edges_get_end(const edges_arr &edges, int i) {
    return edges.arr[i][1];
}

edge_t *model_get_edges_arr(const edges_arr &edges)
{
    return edges.arr;
}

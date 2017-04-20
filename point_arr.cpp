#include "oop3d.h"

vertex_arr init_vertex() {
    vertex_arr vertex;
    vertex.arr = NULL;
    vertex.N_v = 0;
    return vertex;
}

int point_arr_load(vertex_arr &vertex, input_stream &stream)
{
    int N;
    int ret = 0;
    ret = read_stream(N, stream);
    if(ret) {
        return ret;
    }
    vertex.N_v = N;
    ret = point_arr_init(vertex);

    for(int i = 0; i < N && !ret; i++) {
        ret = point_load(vertex.arr[i], stream);
    }
    if(ret) {
        point_arr_release(vertex);
    }
    return ret;
}

int point_arr_init(vertex_arr &vertex) {
    vertex.arr = new Point [vertex.N_v];
    if(!(vertex.arr))
        return MEMORY_ERROR;
    return 0;
}
int point_arr_release(vertex_arr &vertex) {
    if(vertex.arr)
        delete[] vertex.arr;
    vertex.arr = NULL;
    vertex.N_v = 0;
    return 0;
}

int point_arr_rotate(vertex_arr &vertex, const rotate_t &act)
{
    if(!vertex.arr)
        return MODEL_EMPTY;
    matrix_t m;
    point_get_result_action(m, act);
    int ret = 0;
    for(int i = 0; i < vertex.N_v && !ret; ++i) {
        ret = point_change_matrix(vertex.arr[i], m);
    }
   return ret;
}
int point_arr_scale(vertex_arr &vertex, const scale_t &act)
{
    if(!vertex.arr)
        return MODEL_EMPTY;

    matrix_t m;
    point_get_result_action(m, act);
    int ret = 0;
    for(int i = 0; i < vertex.N_v && !ret; ++i) {
        ret = point_change_matrix(vertex.arr[i], m);
    }
    return ret;
}

int point_arr_move(vertex_arr &vertex, const move_t &act)
{
    if(!vertex.arr)
        return MODEL_EMPTY;

    matrix_t m;
    point_get_result_action(m, act);
    int ret = 0;
    for(int i = 0; i < vertex.N_v && !ret; ++i) {
        ret = point_change_matrix(vertex.arr[i], m);
    }
    return ret;
}

int point_arr_get_length(const vertex_arr &vertex) {
    return vertex.N_v;
}

Point point_arr_get(const vertex_arr &vertex, int i) {
    return vertex.arr[i];
}
Point *point_arr_get_pointer(const vertex_arr &vertex) {
    return vertex.arr;
}


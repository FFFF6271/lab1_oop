#ifndef POINT_ARR_H
#define POINT_ARR_H

#include "oop3d.h"

struct vertex_arr {
    Point *arr = NULL;
    int N_v = 0;
};

vertex_arr init_vertex();

int point_arr_rotate(vertex_arr &vert, const rotate_t &act);
int point_arr_scale(vertex_arr &vertex, const scale_t &act);
int point_arr_move(vertex_arr &vertex, const move_t &act);

//загрузка массива точек опр. длины из файла
int point_arr_load(vertex_arr &vertex, input_stream &stream);

int point_arr_init(vertex_arr &vertex);
int point_arr_release(vertex_arr &vertex);

int point_arr_get_length(const vertex_arr &vertex);

Point point_arr_get(const vertex_arr &vertex, int i);

Point *point_arr_get_pointer(const vertex_arr &vertex);

#endif // POINT_ARR_H

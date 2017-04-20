#ifndef POINT_H
#define POINT_H

#include "oop3d.h"

#define  N_DIMEN 4

struct Point {
    double x;
    double y;
    double z;
};

// for NxN change
typedef double matrix_t[N_DIMEN][N_DIMEN];

/* vect in N*/
typedef double vector_t[N_DIMEN];

//получние результирующей матрицы поворота по 3-м углам
void point_get_result_action(matrix_t a, const rotate_t &act);

void point_get_result_action(matrix_t a, const scale_t &act);
void point_get_result_action(matrix_t a, const move_t &act);

int point_change_matrix(Point &p, const matrix_t &m_rotate);

//загрузка точки опр. длины из файла
int point_load(Point& p, input_stream &stream);

int draw_line(my_scene_t &scene, const Point &a, const Point &b);
#endif // POINT_H

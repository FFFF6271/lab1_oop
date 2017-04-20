#include "oop3d.h"

#define BUFF_SIZE 100

static int vector_to_point(Point &p, const vector_t &vec) {
    p.x = vec[0];
    p.y = vec[1];
    p.z = vec[2];
    return 0;
}

static int point_to_vector(vector_t &vec, const Point &p) {
    vec[0] = p.x;
    vec[1] = p.y;
    vec[2] = p.z;
    vec[3] = 1;
    return 0;
}

static int point_mult(vector_t &vec, const matrix_t &a)
{
    vector_t res = {0};
    for(int i = 0; i < N_DIMEN; i++) {
        for(int j = 0; j < N_DIMEN; j++) {
            res[i] += a[i][j] * vec[j];
        }
    }
    for(int i = 0; i < N_DIMEN; i++) {
        vec[i] = res[i];
    }
    return 0;
}

static void point_mult_matrix(matrix_t res, const matrix_t a, const matrix_t b)
{
    for(int i = 0; i < N_DIMEN; i++) {
        for(int j = 0; j < N_DIMEN; j++) {
            res[i][j] = 0;
            for(int k = 0; k < N_DIMEN; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

static void point_copy_matrix(matrix_t res, const matrix_t a)
{
    for(int i = 0; i < N_DIMEN; i++) {
        for(int j = 0; j < N_DIMEN; j++) {
            res[i][j] = a[i][j];
        }
    }
}

int point_load(Point& p, input_stream &stream)
{
    double x, y, z;
    int ret = 0;
    ret = read_stream(x, stream);
    if(!ret)
        ret = read_stream(y, stream);
    if(!ret)
        ret = read_stream(z, stream);

    if(!ret) {
        p.x = x;
        p.y = y;
        p.z = z;
    }
    return ret;
}

void point_get_result_action(matrix_t a, const rotate_t &act)
{
    matrix_t ax = { { 1, 0, 0 },
                       { 0, cos(act.x_angle), -sin(act.x_angle) },
                       { 0, sin(act.x_angle), cos(act.x_angle) } };
    matrix_t ay = { { cos(act.y_angle), 0, sin(act.y_angle) },
                       { 0, 1, 0 },
                       { -sin(act.y_angle), 0, cos(act.y_angle) } };
    matrix_t az = { { cos(act.z_angle), -sin(act.z_angle), 0 },
                       { sin(act.z_angle), cos(act.z_angle), 0 },
                       { 0, 0, 1 } };
    matrix_t tmp;
    point_mult_matrix(tmp, ax, ay);
    point_mult_matrix(a, tmp, az);
}

void point_get_result_action(matrix_t a, const scale_t &act) {
    matrix_t m = { { act.kx, 0, 0 },
                   { 0, act.ky, 0 },
                   { 0, 0, act.kz } };
    point_copy_matrix(a, m);
}

void point_get_result_action(matrix_t a, const move_t &act) {
    matrix_t m = { { 1, 0, 0, act.dx },
                   { 0, 1, 0, act.dy },
                   { 0, 0, 1, act.dz },
                   { 0, 0, 0, 1 } };
    point_copy_matrix(a, m);
}

int point_change_matrix(Point &p, const matrix_t &m_rotate) {
    vector_t vec;
    int ret = 0;
    ret = point_to_vector(vec, p);
    if(!ret)
        ret = point_mult(vec, m_rotate);

    if(!ret)
        ret = vector_to_point(p, vec);
    return ret;
}

int draw_line(my_scene_t &scene, const Point &a, const Point &b) {

    return draw_2d_line(scene, a.x, a.y, b.x, b.y);
}

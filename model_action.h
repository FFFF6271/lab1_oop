#ifndef MODEL_ACTION_H
#define MODEL_ACTION_H

#include "oop3d.h"

model_t init_model();
int model_is_empty(const model_t &model);

int model_rotate(model_t &model, const rotate_t &act);
int model_scale(model_t &model, const scale_t &act);
int model_move(model_t &model, const move_t &act);

int model_load_by_file_name(model_t &model, const file_name_t &act);

/* free model */
int model_release(model_t &model);

int draw_model(my_scene_t &scene, const model_t &model);

int point_arr_get_length(const model_t &model);

int model_get_edges_count(const model_t &model);

vertex_arr point_arr_get_pointer(const model_t &model);

edges_arr model_get_edges_arr(const model_t &model);

#endif // MODEL_ACTION_H

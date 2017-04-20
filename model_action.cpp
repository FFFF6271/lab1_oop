#include "oop3d.h"

int model_load_by_file_name(model_t &model, input_stream &stream);

model_t init_model() {
    model_t model;
    model.vertex = init_vertex();
    model.edges = init_edges();
    return model;
}

int model_is_empty(const model_t &model) {
    return point_arr_get_length(model);
}

int model_rotate(model_t &model, const rotate_t &act) {
    return point_arr_rotate(model.vertex, act);
}

int model_scale(model_t &model, const scale_t &act) {
    return point_arr_scale(model.vertex, act);
}

int model_move(model_t &model, const move_t &act) {
    return point_arr_move(model.vertex, act);
}

int model_load_by_file_name(model_t &model, input_stream &stream) {
    int ret = point_arr_load(model.vertex, stream);
    int N_v = point_arr_get_length(model.vertex);
    if(!ret)
        ret = edges_load_arr(model.edges, stream, N_v);
    return ret;
}

int model_load_by_file_name(model_t &model, const file_name_t &act) {
    input_stream stream;
    int ret = open_stream(stream, act.file_name);
    if(ret)
        return ret;
    model_t buff;
    ret = model_load_by_file_name(buff, stream);
    if(!ret)
        ret = model_release(model);
    if(!ret)
        model = buff;
    close_stream(stream);
    return ret;
}

int model_release(model_t &model) {
    edges_free_arr(model.edges);
    point_arr_release(model.vertex);
    return 0;
}


int draw_model(my_scene_t &scene, const model_t &model) {
    int N_e = model_get_edges_count(model);
    if(!model_is_empty(model))
        return MODEL_EMPTY;
    clean_scene(scene);

    int ret = 0;
    for(int i = 0; i < N_e && !ret; i++) {
        int start = edges_get_start(model.edges, i);
        int end = edges_get_end(model.edges, i);
        Point p1 = point_arr_get(model.vertex, start);
        Point p2 = point_arr_get(model.vertex, end);
        ret = draw_line(scene, p1, p2);
    }
    return ret;
}

int point_arr_get_length(const model_t &model) {
    return point_arr_get_length(model.vertex);
}

int model_get_edges_count(const model_t &model) {
    return get_edges_count(model.edges);
}

vertex_arr point_arr_get_pointer(const model_t &model) {
    return model.vertex;
}

edges_arr model_get_edges_arr(const model_t &model) {
    return model.edges;
}

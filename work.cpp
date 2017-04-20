#include "oop3d.h"

int main_controller(my_scene_t &scene, const t_action &act, type_action t)
{
    static model_t model = init_model();

    int result = OK;
    switch(t) {
    case CREATE:
        result = model_load_by_file_name(model, act.create);
        break;
    case ROTATE:
        result = model_rotate(model, act.rotate);
        break;
    case SCALE:
        result = model_scale(model, act.scale);
        break;
    case MOVE:
        result = model_move(model, act.move);
        break;
    case DRAW:
        result = draw_model(scene, model);
        break;
    case FREE:
        result = model_release(model);
        break;
    default:
        result = -1;
    }
    return result;
}


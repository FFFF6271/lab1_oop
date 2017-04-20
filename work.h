#ifndef WORK_H
#define WORK_H

#include "oop3d.h"

enum type_action
{
    ROTATE,
    CREATE,
    MOVE,
    SCALE,
    FREE,
    SAVE,
    DRAW
};

union t_action {
    rotate_t rotate;
    scale_t scale;
    file_name_t create;
    move_t move;
    bool free;
};

int main_controller(my_scene_t &scene, const t_action &act, type_action t);

#endif // WORK_H

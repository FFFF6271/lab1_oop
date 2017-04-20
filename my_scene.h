#ifndef MY_SCENE_H
#define MY_SCENE_H

#include "oop3d.h"

struct my_scene_t {
    QGraphicsScene *scene = NULL;
    double x_center;
    double y_center;
};

#endif // MY_SCENE_H

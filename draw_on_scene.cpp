#include "oop3d.h"

const QPen penBlack(Qt::black); // Задаём чёрную кисть


int
draw_2d_line(my_scene_t &scene, double x1, double y1,
        double x2, double y2) {
    if(!scene.scene) {
        return SCENE_NOT_FOUND;
    }

    scene.scene->addLine(scene.x_center + x1,
                         scene.y_center - y1,
                         scene.x_center + x2,
                         scene.y_center - y2,
                         penBlack);
    return 0;
}

int
clean_scene(my_scene_t &scene) {
    if(!scene.scene) {
        return SCENE_NOT_FOUND;
    }
    scene.scene->clear();
    return 0;
}

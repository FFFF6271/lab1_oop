#ifndef ACTION_H
#define ACTION_H

#include "oop3d.h"

#define FILE_NAME_SIZE 200

/**
  strcuts of action
 */

struct rotate_t {
    double x_angle;
    double y_angle;
    double z_angle;
};

struct scale_t {
    double kx;
    double ky;
    double kz;
};

struct move_t {
    double dx;
    double dy;
    double dz;
};

struct file_name_t {
    char file_name[FILE_NAME_SIZE];
};

#endif // ACTION_H

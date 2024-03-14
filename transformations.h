#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "draws.h"


typedef struct transfer {
    float dx;
    float dy;
    float dz;
} transfer;

typedef struct zoom {
    float kx;
    float ky;
    float kz;
} zoom;

typedef struct rotate {
    float psi_x;
    float psi_y;
    float psi_z;
} rotate;


int transfer_figure_t(points_data& points, transfer trans);
int zoom_figure_t(points_data& points, zoom zo);
int rotate_figure_t(points_data &points, rotate rot);

#endif //TRANSFORMATIONS_H

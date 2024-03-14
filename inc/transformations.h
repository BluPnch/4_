#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "draws.h"


typedef struct transfer {
    double dx;
    double dy;
    double dz;
} transfer;

typedef struct zoom {
    double kx;
    double ky;
    double kz;
} zoom;

typedef struct rotate {
    double psi_x;
    double psi_y;
    double psi_z;
} rotate;


int transfer_figure_t(points_data& points, transfer trans);
int zoom_figure_t(points_data& points, zoom zo);
int rotate_figure_t(points_data &points, rotate rot);

#endif //TRANSFORMATIONS_H

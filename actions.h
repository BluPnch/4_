#ifndef ACTIONS_H
#define ACTIONS_H

#include "figure.h"
#include <QGraphicsScene>

typedef struct draw {
    QGraphicsView *gV;
    int width;
    int height;
} draw;

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


typedef struct point_x_y_t {
    double x;
    double y;
} point_x_y_t;


int draw_figure(figure_t fig, draw arg);

void draw_links(points_data points, links_data links, QGraphicsScene *scene);


#endif //ACTIONS_H

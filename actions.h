#ifndef ACTIONS_H
#define ACTIONS_H

#include "figure.h"
#include <QGraphicsScene>

typedef struct draw {
    QGraphicsView *gV;
    int width;
    int height;
} draw;

typedef struct point_x_y_t {
    double x;
    double y;
} point_x_y_t;


int draw_figure(figure_t fig, draw arg);

void draw_links(points_data points, links_data links, QGraphicsScene *scene);


#endif //ACTIONS_H

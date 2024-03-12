#ifndef ACTIONS_H
#define ACTIONS_H

#include "figure.h"
#include <QGraphicsScene>

typedef struct draw
{
    QGraphicsView *gV;
    int width;
    int height;
}draw;

int draw_figure(figure_t fig, draw arg);


#endif //ACTIONS_H

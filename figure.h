#ifndef CUBE_H
#define CUBE_H

#include "point.h"
#include "actions.h"

struct figure_t
{
    points_data points;
    links_data links;
};


figure_t& init();
void empty_figure(figure_t& figure);
void copy_figure(figure_t& figure, figure_t& tmp);
int load_figure_from_file(figure_t &ob, const char *filename);

int draw_figure(figure_t figure, draw arg);

// int move_figure(figure_t& figure, move coeff);
// int scale_figure(figure_t& figure, scale coeff);
// int turn_figure(figure_t& figure, turn coeff);

#endif //CUBE_H

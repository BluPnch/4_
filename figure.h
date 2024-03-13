#ifndef CUBE_H
#define CUBE_H

#include "actions.h"
#include "point.h"
#include "link.h"

struct figure_t
{
    points_data points;
    links_data links;
};


figure_t& init();
void empty_figure(figure_t& figure);
void copy_figure(figure_t& figure, figure_t& tmp);
int load_figure_from_file(figure_t &ob, const char *filename);

int transfer_figure_t(points_data& points, transfer trans);
// int scale_figure(figure_t& figure, scale coeff);
// int turn_figure(figure_t& figure, turn coeff);

#endif //CUBE_H

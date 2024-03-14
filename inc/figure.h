#ifndef CUBE_H
#define CUBE_H

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


#endif //CUBE_H

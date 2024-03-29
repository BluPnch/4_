#include "figure.h"
#include "draws.h"
#include "point.h"
#include "errors.h"


int center_point(point_t point, draw window) {
    point.x += window.width;
    point.y += window.height;
}

figure_t& init()
{
    static figure_t figure;

    figure.points.n = 0;
    figure.points.arr = NULL;

    figure.links.n = 0;
    figure.links.arr = NULL;

    return figure;
}


void empty_figure(figure_t& figure)
{
    figure.points.n = 0;
    points_free(figure.points);

    figure.links.n = 0;
    links_free(figure.links);
}

void copy_figure(figure_t& figure, figure_t& tmp)
{
    figure.points.n = tmp.points.n;
    figure.points.arr = tmp.points.arr;

    figure.links.n = tmp.links.n;
    figure.links.arr = tmp.links.arr;
}


int load_figure_from_file(figure_t& figure, const char *filename)
{
    int res = 0;
    FILE *f = fopen(filename, "r");
    if (!f)
        return ERR_FILE_NOT_FOUND;
    figure_t figure_tmp = init();

    int err = points_process(figure_tmp.points, f);
    if (!err)
    {
        err = links_process(figure_tmp.links, f);
        if (err)
            points_free(figure_tmp.points);
    }

    if (!err)
    {
        empty_figure(figure);
        copy_figure(figure, figure_tmp);
    }

    fclose(f); // TODO Может перенести!!!!!!!!!!!!!
    return res;
}

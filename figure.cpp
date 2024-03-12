#include "figure.h"

#include "actions.h"
#include "point.h"
#include "errors.h"

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
    // TODO points_free(figuRre.points);

    figure.links.n = 0;
    // TODO links_free(figure.links);
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
    FILE *f = fopen(filename, "r");
    if (!f)
        return ERR_FILE_NOT_FOUND;
    figure_t figure_tmp = init();

    /*int err = process_points(cub_tmp.points, f);
    if (!err)
    {
        err = process_links(cub_tmp.links, f);
        if err:
            points_free(cub_tmp.points);
    }

    if (!err)
    {
        empty_figure_t(cub);
        copy_figure_t(cub, cub_tmp);
    }*/

    fclose(f);
    // TODO return err;
}

// _________________________________________________________________________________________


point_t point_center(point_t point, draw arg)
{
    point_t p_tmp;

    p_tmp.x = point.x + arg.width / 2;
    p_tmp.y = point.y + arg.height / 2;

    return p_tmp;
}

// _________________________________________________________________________________________


/*
int move_figure_t(figure_t& fig, move coeff)
{
    return move_points_array(fig.points.arr, fig.points.n, coeff);
}

int scale_figure_t(figure_t& fig, scale coeff)
{
    return scale_points_array(fig.points.arr, fig.points.n, coeff);
}

int turn_figure_t(figure_t& fig, turn coeff)
{
    return turn_points_array(fig.points.arr, fig.points.n, coeff);
}*/
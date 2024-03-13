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

    fclose(f);
    return res;
}


// _________________________________________________________________________________________

void trans_point(point_t& point, transfer trans)
{
    point.x += trans.dx;
    point.y += trans.dy;
    point.z += trans.dz;
}

int trans_points_arr(point_t* points, int n, transfer trans)
{
    if(!points)
        return ERR_NO_DOTS;
    int err = 0;
    for(int i = 0; i < n; i++)
        trans_point(points[i], trans);
    return err;
}

int transfer_figure_t(points_data& points, transfer trans)
{
    return trans_points_arr(points.arr, points.n, trans);
}

// int scale_figure_t(figure_t& fig, scale coeff)
// {
//     return scale_points_array(fig.points.arr, fig.points.n, coeff);
// }
//
// int turn_figure_t(figure_t& fig, turn coeff)
// {
//     return turn_points_array(fig.points.arr, fig.points.n, coeff);
// }
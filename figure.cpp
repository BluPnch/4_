#include "cube.h"
#include "point.h"
#include "errors.h"

cube& init()
{
    static cube cub;

    cube.points.n = 0;
    cube.points.arr = NULL;

    cube.links.n = 0;
    cube.links.arr = NULL;

    return cube;
}


void empty_cube(cube& cub)
{
    cube.points.n = 0;
    points_free(cub.points);

    cube.links.n = 0;
    links_free(cub.links);
}

void copy_cube(cube& cub, cube& tmp)
{
    cub.points.n = tmp.points.n;
    cub.points.arr = tmp.points.arr;

    cub.links.n = tmp.links.n;
    cub.links.arr = tmp.links.arr;
}


int read_cube_from_file(cube& cub, const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return FILE_NOT_FOUND;
    cube cub_tmp = init();

    /*int err = process_points(cub_tmp.points, f);
    if (!err)
    {
        err = process_links(cub_tmp.links, f);
        if err:
            points_free(cub_tmp.points);
    }

    if (!err)
    {
        empty_cube(cub);
        copy_cube(cub, cub_tmp);
    }*/

    fclose(f);
    return err;
}

// _________________________________________________________________________________________


point_t point_center(point_t point, draw arg)
{
    point_t p_tmp;

    p_tmp.x = point.x + arg.w / 2;
    p_tmp.y = point.y + arg.h / 2;

    return tmp;
}

// _________________________________________________________________________________________


int draw_cube(cube cub, draw arg)
{
    // graphics a;
    // int err = init_graph(a, arg.gV);
    // if (err)
    //     return err;

    draw_links(cub.points, cub.links, arg, a);

    a.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(arg.w, arg.h)));
    set(arg.gV, a);

    return err;
}

/*
int move_cube(cube& fig, move coeff)
{
    return move_points_array(fig.points.arr, fig.points.n, coeff);
}

int scale_cube(cube& fig, scale coeff)
{
    return scale_points_array(fig.points.arr, fig.points.n, coeff);
}

int turn_cube(cube& fig, turn coeff)
{
    return turn_points_array(fig.points.arr, fig.points.n, coeff);
}*/
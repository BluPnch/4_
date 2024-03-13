#include "transformations.h"


#include "errors.h"

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

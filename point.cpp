#include "point.h"
#include "errors.h"
#include <cstdlib>

// coord_point get_dot(point* points, int n)
// {
//     coord_point dot = {points[n].x, points[n].y};
//     return dot;
// }

int points_alloc(points_data& points, int n)
{
    points.n = n;
    points.arr = (point_t*) calloc(n, sizeof(point_t));

    if (!points.arr)
        return ERR_PTR_ALL;

    return NONE;
}


void points_free(points_data &points)
{
    if (points.arr)
        free(points.arr);
}


int point_read(point_t* p_act, FILE* f)
{
    if (fscanf(f, "%lf %lf %lf", &p_act->x, &p_act->y, &p_act->z) != 3)
        return ERR_FILE_FORMAT;

    return NONE;
}

int points_read(point_t *points, int n, FILE *f)
{
    int res = 0;
    for (int i = 0; i < n && !res; i++)
    {
        if (point_read(points + i, f))
            res = ERR_FILE_FORMAT;
    }
    return res;
}

// ______________________________________________________________________________


int links_alloc(links_data& links, int n)
{
    links.n = n;
    links.arr = (link_t*) calloc(n, sizeof(link_t));

    if (!links.arr)
        return ERR_PTR_ALL;
    return NONE;
}


void links_free(links_data &links)
{
    if (links.arr)
        free(links.arr);
}


int link_read(link_t* l_act, FILE* f)
{
    if (fscanf(f, "%lf %lf", &l_act->p1, &l_act->p2) != 2)
        return ERR_FILE_FORMAT;

    return NONE;
}

int links_read(link_t *links, int n, FILE *f)
{
    int res = 0;
    for (int i = 0; i < n && !res; i++)
    {
        if (link_read(links + i, f))
            res = ERR_FILE_FORMAT;
    }
    return res;
}
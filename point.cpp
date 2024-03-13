#include "errors.h"

#include "point.h"

static int read_n(int *n, FILE *f) {
    int err = 0;
    if (fscanf(f, "%d", n) != 1)
        err = ERR_FILE_FORMAT;
    if (*n <= 0)
        err = ERR_FILE_CONTENT;
    return err;
}


// ______________________________________________________________________________


int points_alloc(points_data &points, int n) {
    points.n = n;
    points.arr = (point_t *) calloc(n, sizeof(point_t));

    if (!points.arr)
        return ERR_PTR_ALL;

    return NONE;
}


void points_free(points_data &points) {
    if (points.arr)
        free(points.arr);
}


int point_read(point_t *p_act, FILE *f) {
    if (fscanf(f, "%lf %lf %lf", &p_act->x, &p_act->y, &p_act->z) != 3)
        return ERR_FILE_FORMAT;

    return NONE;
}


int points_read(point_t *points, int n, FILE *f) {
    int res = 0;
    for (int i = 0; i < n && !res; i++) {
        if (point_read(points + i, f))
            res = ERR_FILE_FORMAT;
    }
    return res;
}


int points_process(points_data &points, FILE *f) {
    int n, err = 0;
    err = read_n(&n, f);
    if (!err) {
        if (n)
            err = points_alloc(points, n);
        else
            err = ERR_NO_DOTS;

        if (!err) {
            if ((err = points_read(points.arr, n, f)) == ERR_FILE_FORMAT)
                points_free(points);
        }
    }
    return err;
}

// ______________________________________________________________________________

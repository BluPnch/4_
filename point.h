#ifndef POINT_H
#define POINT_H
#include <cstdio>


struct point_t
{
    double x;
    double y;
    double z;
};

struct points_data
{
    int n;
    point_t* arr;
};


int points_alloc(points_data &points, int n);
void points_free(points_data &points);
int point_read(point_t *p_act, FILE *f);
int points_read(point_t *points, int n, FILE *f);
int points_process(points_data &points, FILE *f);



#endif //POINT_H

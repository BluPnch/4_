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


struct link_t
{
    int p1;
    int p2;
};

struct links_data
{
    int n;
    link_t* arr;
};

int points_alloc(points_data &points, int n);
void points_free(points_data &points);
int point_read(point_t *p_act, FILE *f);
int points_read(point_t *points, int n, FILE *f);
int points_process(points_data &points, FILE *f);

int links_alloc(links_data &links, int n);
void links_free(links_data &links);
int link_read(link_t *l_act, FILE *f);
int links_read(link_t *links, int n, FILE *f);
int links_process(links_data& links, FILE* f);

#endif //POINT_H

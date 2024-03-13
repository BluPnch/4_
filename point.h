#ifndef POINT_H
#define POINT_H

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

#endif //POINT_H

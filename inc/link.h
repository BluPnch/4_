#ifndef LINKS_H
#define LINKS_H

#include <cstdio>

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

int links_alloc(links_data &links, int n);
void links_free(links_data &links);
int link_read(link_t &link, FILE *f);
int links_read(link_t *links, int n, FILE *f);
int links_process(links_data& links, FILE* f);

#endif //LINKS_H

#include "link.h"
#include "errors.h"

static int read_n(int *n, FILE *f) {
    int err = 0;
    if (fscanf(f, "%d", n) != 1)
        err = ERR_FILE_FORMAT;
    if (*n <= 0)
        err = ERR_FILE_CONTENT;
    return err;
}

int links_alloc(links_data &links, int n) {
    links.n = n;
    links.arr = (link_t *) calloc(n, sizeof(link_t));

    if (!links.arr)
        return ERR_PTR_ALL;
    return NONE;
}


void links_free(links_data &links) {
    if (links.arr)
        free(links.arr);
}


int link_read(link_t *l_act, FILE *f) {
    if (fscanf(f, "%d %d", &l_act->p1, &l_act->p2) != 2)
        return ERR_FILE_FORMAT;

    return NONE;
}

int links_read(link_t *links, int n, FILE *f) {
    int res = 0;
    for (int i = 0; i < n && !res; i++) {
        if (link_read(links + i, f))
            res = ERR_FILE_FORMAT;
    }
    return res;
}

int links_process(links_data& links, FILE* f)
{
    int n;
    int err = 0;

    err = read_n(&n, f);
    if (!err)
    {
        if (n)
            err = links_alloc(links, n);
        else
            err = ERR_NO_LINKS;

        if (!err)
        {
            if ((err = links_read(links.arr, n, f)) == ERR_FILE_FORMAT)
                links_free(links);
        }
    }
    return err;
}



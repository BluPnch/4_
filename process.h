#ifndef PROCESS_H
#define PROCESS_H

#include "transformations.h"

enum task
{
    INIT,
    LOAD_FILE,
    DRAW,
    TRANSFER,
    ZOOM,
    ROTATE,
    QUIT
};

typedef struct file
{
    const char* filename;
}load_file;

typedef struct request
{
    task t;
    union
    {
        file load_f;
        draw dr;
        transfer trans;
        zoom zo;
        rotate rot;
    };
}request;

int task_manager(request args);


#endif //PROCESS_H

#ifndef PROCESS_H
#define PROCESS_H

#include "actions.h"

enum task
{
    INIT,
    LOAD_FILE,
    DRAW,
    // MOVE,
    // SCALE,
    // TURN,
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
        // struct move mo;
        // struct scale sc;
        // struct turn tu;
    };
}request;

int task_manager(request args);


#endif //PROCESS_H

#include "process.h"
#include "figure.h"
#include "transformations.h"
#include "errors.h"


int task_manager(request req) {
    static figure_t figure = init();
    int err = 0; //TODO ERRORS!!!!!!!!!!!!!!!!!!

    switch (req.t) {
        case INIT:
            break;
        case LOAD_FILE:
            err = load_figure_from_file(figure, req.load_f.filename);
            break;
        case DRAW:
            err = draw_figure(figure, req.dr);
            break;
        case TRANSFER:
            err = transfer_figure_t(figure.points, req.trans);
            break;
        case ZOOM:
            err = zoom_figure_t(figure.points, req.zo);
            break;
        case ROTATE:
            err = rotate_figure_t(figure.points, req.rot);
            break;
        case QUIT:
            empty_figure(figure);
            break;
        default:
            err = ERR_UNKNOWN_COMMAND;
    }

    return err;
}

#include "process.h"
#include "figure.h"
#include "errors.h"

int task_manager(request req) {
    static figure_t figure = init();
    int err = 0;

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
        // case SCALE:
        //     err = scale_figure(fig, req.sc);
        // break;
        // case TURN:
        //     err = turn_figure(fig, req.tu);
        // break;
        case QUIT:
            empty_figure(figure);
            break;
        default:
            err = ERR_UNKNOWN_COMMAND;
    }

    return err;
}

#include "actions.h"
#include "errors.h"
#include <QGraphicsScene>
#include <QGraphicsView>

// int receive_x_y(point_t point, double n)
// {
//     coord_point dot = {point[n].x, point[n].y};
//     return dot;
// }
//
// int receive_x_y(point_t points_arr, link_t links_arr)
// {
//     n = links_arr.
//     coord_point dot = {dots[n].x, dots[n].y};
//     return dot;
// }


void draw_links(points_data points, links_data links, QGraphicsScene *scene) {
    // for (int i = 0; i < links.n; i++)
    // {
    //     p1, p2 = receive_x_y(points.arr, links.arr[i]);
    //     draw_line(p1, p2, a, dr);
    // }
    scene->addLine(0, 0, 100, 100);
}


void set(QGraphicsView *gV, QGraphicsScene *scene) {
    QGraphicsScene *prev = gV->scene();
    delete prev;
    gV->setScene(scene);
}

int draw_figure(figure_t fig, draw arg) {
    QGraphicsScene *scene = new QGraphicsScene(arg.gV);
    if (!scene)
        return ERR_PTR_ALL;

    draw_links(fig.points, fig.links, scene);

    scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(arg.width, arg.height)));

    set(arg.gV, scene);

    // TODO return err;
}

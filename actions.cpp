#include "actions.h"
#include "errors.h"
#include <QGraphicsScene>
#include <QGraphicsView>

int receive_x_y(point_t point)
{
    point_x_y_t point_x_y = {point.x, point.y};
    return point_x_y;
}


point_x_y_t *receive_start_end(point_t points_arr, link_t link, draw window)
{
    point_x_y_t start_x_y = receive_x_y(points_arr[link.p1]);
    point_x_y_t end_x_y = receive_x_y(points_arr[link.p2]);
    draw_line(start_x_y, end_x_y, window.gV, window);
    return [start_x_y, end_x_y];
}


void draw_links(points_data points, links_data links, draw window) {
    for (int i = 0; i < links.n; i++)
    {
        p1, p2 = receive_start_end(points.arr, links.arr[i]);
        draw_line(p1, p2, a, dr);
    }
    scene->addLine(0, 0, 100, 100);
}


void set(QGraphicsView *gV, QGraphicsScene *scene) {
    QGraphicsScene *prev = gV->scene();
    delete prev;
    gV->setScene(scene);
}

int draw_figure(figure_t fig, draw window) {
    QGraphicsScene *scene = new QGraphicsScene(window.gV);
    draw_links(fig.points, fig.links, scene);

    scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(window.width, window.height)));

    set(window.gV, scene);

    // TODO return err;
}

#include "draws.h"
#include <QGraphicsScene>
#include <QGraphicsView>

// point_x_y_t point_center(point_x_y_t point, QGraphicsScene *scene)
// {
//     point_x_y_t p_tmp;
//     p_tmp.x = point.x + scene->width() / 2;
//     p_tmp.y = point.y + scene->height() / 2;
//     return p_tmp;
// }


point_x_y_t receive_x_y(point_t point)
{
    point_x_y_t point_x_y = {point.x, point.y};
    return point_x_y;
}


void draw_line(point_t *points_arr, link_t link, QGraphicsScene *scene)
{
    point_x_y_t start_x_y = receive_x_y(points_arr[link.p1]);
    point_x_y_t end_x_y = receive_x_y(points_arr[link.p2]);
    // start_x_y = point_transform(start_x_y, scene);
    // end_x_y = point_transform(end_x_y, scene);

    scene->addLine(start_x_y.x, start_x_y.y, end_x_y.x, end_x_y.y);
}


void draw_links(points_data points, links_data links, QGraphicsScene *scene) {
    for (int i = 0; i < links.n; i++)
        draw_line(points.arr, links.arr[i], scene);
}


void set(QGraphicsView *gV, QGraphicsScene *scene) {
    QGraphicsScene *prev = gV->scene();
    delete prev;
    gV->setScene(scene);
}

int draw_figure(figure_t fig, draw window) {
    int res = 0;
    QGraphicsScene *scene = new QGraphicsScene(window.gV);
    draw_links(fig.points, fig.links, scene);

    scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(window.width, window.height)));
    set(window.gV, scene);

    return res;
}

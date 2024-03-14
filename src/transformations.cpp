#include "transformations.h"

#include <cmath>

#include "errors.h"

#define PI 3.14


void trans_point(point_t &point, transfer trans) {
    point.x += trans.dx;
    point.y += trans.dy;
    point.z += trans.dz;
}

int trans_points_arr(point_t *points, int n, transfer trans) {
    if (!points)
        return ERR_NO_DOTS;
    int err = 0;
    for (int i = 0; i < n; i++)
        trans_point(points[i], trans);
    return err;
}

int transfer_figure_t(points_data &points, transfer trans) {
    return trans_points_arr(points.arr, points.n, trans);
}


// ____________________________________________________________________________________

void zoom_point(point_t &point, zoom zo) {
    point.x *= zo.kx;
    point.y *= zo.ky;
    point.z *= zo.kz;
}

int zoom_points_arr(point_t *points, int n, zoom zo) {
    if (!points)
        return ERR_NO_DOTS;
    int err = 0;
    for (int i = 0; i < n; i++)
        zoom_point(points[i], zo);
    return err;
}

int zoom_figure_t(points_data &points, zoom zo) {
    return zoom_points_arr(points.arr, points.n, zo);
}


// ____________________________________________________________________________________


double my_cos(double psi) {
    return cos(psi * PI / 180);
}

double my_sin(double psi) {
    return sin(psi * PI / 180);
}

void x_turn_point(point_t &point, double psi) {
    const double cos_psi = my_cos(psi), sin_psi = my_sin(psi);
    point.y = point.y + cos_psi + point.z * sin_psi;
    point.z = -point.y * sin_psi + point.z * cos_psi;
}

void y_turn_point(point_t &point, double psi) {
    const double cos_psi = my_cos(psi), sin_psi = my_sin(psi);
    point.x = point.x * cos_psi + point.z * sin_psi;
    point.z = -point.x * sin_psi + point.z * cos_psi;
}

void z_turn_point(point_t &point, double psi) {
    const double cos_psi = my_cos(psi), sin_psi = my_sin(psi);
    point.x = point.x * cos_psi + point.y * sin_psi;
    point.y = -point.x * sin_psi + point.y * cos_psi;
}


int rotate_points_arr(point_t *points, int n, rotate rot) {
    if (!points)
        return ERR_NO_DOTS;
    int err = 0;
    for (int i = 0; i < n; i++) {
        x_turn_point(points[i], rot.psi_x);
        y_turn_point(points[i], rot.psi_y);
        z_turn_point(points[i], rot.psi_z);
    }
    return err;
}

int rotate_figure_t(points_data &points, rotate rot) {
    return rotate_points_arr(points.arr, points.n, rot);
}
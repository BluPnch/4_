#include "mainwindow.h"
#include "process.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
                                         ui(new Ui::MainWindow) {
    ui->setupUi(this);


    request req;
    req.t = INIT;
    task_manager(req);

    req.t = LOAD_FILE;
    // req.load_f.filename = "/home/andrey/CLionProjects/4_/figure.txt";
    req.load_f.filename = "/home/varya/4 семестр/figure.txt";
    task_manager(req);

    draw();

    // Показываем окно после инициализации
    show();
}

MainWindow::~MainWindow() {
    delete ui;
}

errors MainWindow::draw() {
    request req;
    req.t = DRAW;
    req.dr.gV = ui->graphicsView;
    req.dr.height = ui->graphicsView->height();
    req.dr.width = ui->graphicsView->width();
    task_manager(req);
}


errors MainWindow::transform_and_show(request req)
{
    errors err = (errors) task_manager(req);
    if (err)
        return err;
    draw();
    return err;
}

void MainWindow::on_transfer_clicked() {
    double x = ui->transf_x->value(), y = ui->transf_y->value(), z = ui->transf_z->value();
    printf("%lf %lf %lf\n", x, y, z);
    request req;
    req.t = TRANSFER;

    req.trans.dx = x;
    req.trans.dy = y;
    req.trans.dz = z;

    errors err = transform_and_show(req);
    // if (err)
    //     error_message(err);
    draw();
}
void MainWindow::on_zoom_clicked() {
    double x = ui->zoom_x->value(),  y = ui->zoom_y->value(), z = ui->zoom_z->value();
    printf("%lf %lf %lf\n", x, y, z);
    request req;
    req.t = ZOOM;

    req.zo.kx = x;
    req.zo.ky = y;
    req.zo.kz = z;
    errors err = transform_and_show(req);
    draw();
}
void MainWindow::on_rotate_clicked() {
    double x = ui->rot_x->value(),  y = ui->rot_y->value(), z = ui->rot_z->value();
    printf("%lf %lf %lf\n", x, y, z);
    request req;
    req.t = ROTATE;

    req.rot.psi_x = x;
    req.rot.psi_y = y;
    req.rot.psi_z = z;
    errors err = transform_and_show(req);
    draw();
}
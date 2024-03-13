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

void MainWindow::push_transfer() {
    double x = ui->transf_x->value(), y = ui->transf_y->value(), z = ui->transf_z->value();
    printf("%lf %lf %lf\n", x, y, z);
    // TODO что-то сделать
    draw();
}
void MainWindow::push_zoom() {
    double x = ui->zoom_x->value(),  y = ui->zoom_y->value(), z = ui->zoom_z->value();
    printf("%lf %lf %lf\n", x, y, z);
    // TODO что-то сделать
    draw();
}
void MainWindow::push_rotate() {
    double x = ui->rot_x->value(),  y = ui->rot_y->value(), z = ui->rot_z->value();
    printf("%lf %lf %lf\n", x, y, z);
    // TODO что-то сделать
    draw();
}
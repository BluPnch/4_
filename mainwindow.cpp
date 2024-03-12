#include "mainwindow.h"
#include "process.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
                                         ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // scene = new QGraphicsScene(ui->graphicsView);
    // scene = new QGraphicsScene(0, 0, SCREEN_WIDTH - 2, SCREEN_HEIGHT - 2, parent);
    // scene->addRect(scene->sceneRect());
    // ui->graphicsView->setScene(scene);

    request req;
    req.t = INIT;
    task_manager(req);


    req.t = LOAD_FILE;
    req.load_f.filename = "/home/andrey/CLionProjects/4_/figure.txt";
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

void MainWindow::on_pushButton_4_clicked() {
    double x = ui->doubleSpinBox->value();
    printf("%lf\n", x);
    // TODO что-то сделать
    draw();
}

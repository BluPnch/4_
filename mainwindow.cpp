#include "mainwindow.h"
#include "process.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // scene = new QGraphicsScene(ui->graphicsView);
    // scene = new QGraphicsScene(0, 0, SCREEN_WIDTH - 2, SCREEN_HEIGHT - 2, parent);
    // scene->addRect(scene->sceneRect());
    // ui->graphicsView->setScene(scene);

    request req;
    req.t = INIT;
    task_manager(req);

    // Показываем окно после инициализации
    show();
}

/*MainWindow::MainWindow(QWidget *parent):
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // scene = new QGraphicsScene(ui->graphicsView);
    scene = new QGraphicsScene(0, 0, SCREEN_WIDTH - 2, SCREEN_HEIGHT - 2, parent);
    scene->addRect(scene->sceneRect());
    ui->graphicsView->setScene(scene);

    request req;
    req.t = INIT;
    task_manager(req);
}*/

MainWindow::~MainWindow()
{
    delete ui;
}

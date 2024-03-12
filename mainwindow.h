#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QMainWindow>

#include "errors.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void push_transfer();
    void push_zoom();
    void push_rotate();

private:
    Ui::MainWindow *ui;
    QGraphicsView *gV;

    errors draw();
};
#endif // MAINWINDOW_H

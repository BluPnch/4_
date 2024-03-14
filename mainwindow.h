#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QMainWindow>

#include "errors.h"
#include "process.h"

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
    void on_transfer_clicked();
    void on_zoom_clicked();
    void on_rotate_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsView *gV;

    errors draw();

    errors transform_and_show(request req);
};
#endif // MAINWINDOW_H

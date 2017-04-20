#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "oop3d.h"

#include "mygraphicview.h"
#include "mycontroller.h"

#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void SendingScene(my_scene_t *my_scene_t);
private:
    Ui::MainWindow  *ui;
    MyGraphicView   *myPicture;
    MyController    *myController;
};


#endif // MAINWINDOW_H

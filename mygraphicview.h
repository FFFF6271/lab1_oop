#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include "oop3d.h"

#define POINT_SIZE 3

namespace Ui {
class MyGraphicView;
}

class MyGraphicView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit MyGraphicView(QWidget *parent = 0);
    ~MyGraphicView();
    void Paint(model_t &mod);
    void Paint(QGraphicsScene *scene);
    void Connect();
signals:
    void SendScene(my_scene_t* my_scene);
private:
    Ui::MyGraphicView *ui;
    my_scene_t my_scene;
};

#endif // MYGRAPHICVIEW_H

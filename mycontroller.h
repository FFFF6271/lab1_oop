#ifndef MYCONTROLLER_H
#define MYCONTROLLER_H

#include "oop3d.h"

using namespace std;
enum Text_Error { EMPTY, E_SYMBOL, NO_ER };


namespace Ui {
class MyController;
}

class MyController : public QWidget
{
    Q_OBJECT

public:
    explicit MyController(QWidget *parent = 0);
    ~MyController();
    void GetScene(my_scene_t *scene);
signals:
    void AnswerChange(model_t &mod);
    void SceneChange(QGraphicsScene *scene);
private slots:
    void on_rotateButton_clicked();

    void on_scaleButton_clicked();

    void on_moveButton_clicked();

    void on_fileButton_clicked();
private:
    double *GetData(vector <QLineEdit*> &vec);
    my_scene_t scene;
    Ui::MyController *ui;
    model_t model;
    QWidget *par;
    QRegExpValidator *Validator;
};

double Analiz_Text(QString str);
#endif // MYCONTROLLER_H

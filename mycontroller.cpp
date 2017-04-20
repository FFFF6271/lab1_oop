#include "mycontroller.h"
#include "ui_mycontroller.h"

#include "oop3d.h"

#define MIN_PAR 10
text_error LineEditError;


MyController::MyController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyController)
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    par = parent;
    log_w("test %s", "sjdjweoe");
    ui->setupUi(this);
    Validator = new QRegExpValidator(QRegExp("^[+-]?[0-9]{0,5}(\\.|,|$)[0-9]{0,4}$"));
    ui->xEdit->setValidator(Validator);
    ui->yEdit->setValidator(Validator);
    ui->zEdit->setValidator(Validator);
}

void MyController::GetScene(my_scene_t *scene1) {
    this->scene.x_center = scene1->x_center;
    this->scene.y_center = scene1->y_center;
    this->scene.scene = scene1->scene;
}

MyController::~MyController()
{
    t_action act;
    act.free = true;
    delete Validator;
    main_controller(scene, act, FREE);
    delete ui;
}

double * MyController::GetData(vector <QLineEdit*> &vec)
{
    QString str;
    double *data = new double[vec.size()];
    double x;
    QString mess;
    for(unsigned int i = 0; i < vec.size(); i++) {
        str = vec[i]->text();
        x = Analiz_Text(str);
        switch(LineEditError)
        {
        case EMPTY:
            mess = "Область текста пуста.\n Введите данные!";
            break;
        case E_SYMBOL:
            mess = "Ошибочный символ\n "
                   "Разрешается использование только цифр, '.'',' и знаков табуляции";
            break;
        }
        if(LineEditError != NO_ER) {
            QErrorMessage errorMessage;
            errorMessage.showMessage(mess);
            errorMessage.exec();
            break;
        }
        data[i] = x;
    }
   return data;
}

double Analiz_Text(QString str)
{
    LineEditError = NO_ER;
    if(str == "") {
        LineEditError = EMPTY;
        return 0;
    }
    str.replace(QString(","), QString("."));

    QStringList list = str.split(' ', QString::SkipEmptyParts);
    if(list.size() > 1) {
        LineEditError = E_SYMBOL;
        return 0;
    }

    double x;
    bool ok = true;
    for(int i = 0; i < list.size(); i++) {
        x = list.at(i).toDouble(&ok);
        //cout << tmp.toStdString() << " " << ok << " " << x << endl;
        if(!ok) {
            LineEditError = E_SYMBOL;
            return 0;
        }
    }
    return x;
}


void MyController::on_rotateButton_clicked()
{

    vector<QLineEdit*> edits;
    edits.push_back(ui->xEdit);
    edits.push_back(ui->yEdit);
    edits.push_back(ui->zEdit);

    double *data = GetData(edits);

    if(LineEditError != NO_ER)
        return;


    t_action act;

    act.rotate.x_angle = data[0] * M_PI / 180;
    act.rotate.y_angle = data[1] * M_PI / 180;
    act.rotate.z_angle = data[2] * M_PI / 180;

    main_controller(scene, act, ROTATE);
    main_controller(scene, act, DRAW);
    delete[] data;
}

void MyController::on_scaleButton_clicked()
{

    vector<QLineEdit*> edits;
    edits.push_back(ui->xEdit);
    edits.push_back(ui->yEdit);
    edits.push_back(ui->zEdit);

    double *data = GetData(edits);

    if(LineEditError != NO_ER)
        return;

    t_action act;

    act.scale.kx = data[0];
    act.scale.ky = data[1];
    act.scale.kz = data[2];

    main_controller(scene, act, SCALE);
    main_controller(scene, act, DRAW);
    delete[] data;

}

void MyController::on_moveButton_clicked()
{

    vector<QLineEdit*> edits;
    edits.push_back(ui->xEdit);
    edits.push_back(ui->yEdit);
    edits.push_back(ui->zEdit);

    double *data = GetData(edits);

    if(LineEditError != NO_ER)
        return;


    t_action act;

    act.move.dx = data[0];
    act.move.dy = data[1];
    act.move.dz = data[2];

    main_controller(scene, act, MOVE);
    main_controller(scene, act, DRAW);
    delete[] data;
}


void MyController::on_fileButton_clicked()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    if(str == "")
        return;
    t_action act;
    strcpy(act.create.file_name, str.toStdString().c_str());
    int res = main_controller(scene, act, CREATE);
    QString mess = "";
    if(res == FILE_NOT_FIND) {
        mess = "Cannot open file";
    } else if(res == FILE_ERROR) {
        mess = "Error format of data";
    } else if(res == MEMORY_ERROR) {
        mess = "Mamory error";
    }
    if(mess != "") {
        QErrorMessage errorMessage;
        errorMessage.showMessage(mess);
        errorMessage.exec();
        return;
    }
    main_controller(scene, act, DRAW);
}

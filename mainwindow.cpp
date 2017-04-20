#include "mainwindow.h"

#include "oop3d.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QHBoxLayout *layout = new QHBoxLayout;
    ui->centralWidget->setLayout(layout);
    this->setWindowTitle("Object Oriented Programming 1");

    myPicture = new MyGraphicView();
    layout->addWidget(myPicture);

    myController = new MyController();
    layout->addWidget(myController);
    myController->setFixedWidth(253);

    QObject::connect(myPicture, SIGNAL(SendScene(my_scene_t*)),
            this, SLOT(SendingScene(my_scene_t*)));
    myPicture->Connect();
}

void MainWindow::SendingScene(my_scene_t *my_scene)
{
    std::cout << "window:" << my_scene->x_center << endl;
    myController->GetScene(my_scene);
}

MainWindow::~MainWindow()
{
    delete myPicture;
    delete myController;
    delete ui;
}

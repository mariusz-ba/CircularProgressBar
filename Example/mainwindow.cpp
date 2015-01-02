#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStringListModel(this);
    QStringList lista;
    lista << "FILLING" << "ROUNDING";
    model->setStringList(lista);
    ui->comboBox->setModel(model);

    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(changeCurrentType(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeColor()
{
    ui->widget->setColor(QColorDialog::getColor());
}

void MainWindow::changeCurrentType(QString napis)
{
    if(napis == "FILLING"){ui->widget->setType(CircularProgressBar::FILLING);}
    if(napis == "ROUNDING"){ui->widget->setType(CircularProgressBar::ROUNDING);}
}

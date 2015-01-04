#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->checkBox,SIGNAL(toggled(bool)),this,SLOT(renderValue(bool)));

    model = new QStringListModel;
    QStringList list;
    list << "FILLING" << "ROUNDING";
    model->setStringList(list);
    ui->comboBox->setModel(model);

    connect(ui->comboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(changeCurrentType(QString)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor();
    ui->widget->setColor(color);
}

void Dialog::renderValue(bool ok)
{
    ui->widget->renderValue(ok);
}

void Dialog::changeCurrentType(QString s)
{
    if(s == "FILLING") {ui->widget->setType(CircularProgressBar::FILLING);}
    if(s == "ROUNDING") {ui->widget->setType(CircularProgressBar::ROUNDING);}
}

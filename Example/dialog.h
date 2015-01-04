#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QStringListModel>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void renderValue(bool);
    void changeCurrentType(QString);

private:
    Ui::Dialog *ui;
    QStringListModel* model;
};

#endif // DIALOG_H

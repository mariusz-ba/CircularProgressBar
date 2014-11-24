/********************************************************
 *
 * CircularProgressBar.h
 *
 * Created by Mariusz Baran on 17.11.2014
 * Copyright (c) 2014 Mariusz Baran. All rights reserved
 *
 ********************************************************/

#ifndef CIRCULARPROGRESSBAR_H
#define CIRCULARPROGRESSBAR_H

#include <QWidget>
#include <QtGui>

class CircularProgressBar : public QWidget
{
    Q_OBJECT
public:
    explicit CircularProgressBar(QWidget *parent = 0);
    int getValue() const;       //This fucntion returns a progressbar value which is stored ind m_x variable as a radius of filled circle (0.. 100)
    void setColor(QColor color);        //Sets a color of filled circle; Default color is black

protected:
    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent* event);

private:
    int radius;
    int m_x;
    QPoint center;
    QColor fillColor;

signals:
    void valueChanged(int x);       //This singnal is emited always when the setValue slot has occurred

public slots:
    void setValue(int x);           //Sets a value of progressbar (0.. 100)

};
#endif // CIRCULARPROGRESSBAR_H

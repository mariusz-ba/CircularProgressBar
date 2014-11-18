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
    int getValue() const;

protected:
    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent* event);

private:
    int radius;
    int m_x;
    QPoint center;

signals:
    void valueChanged(int x);

public slots:
    void setValue(int x);

};
#endif // CIRCULARPROGRESSBAR_H

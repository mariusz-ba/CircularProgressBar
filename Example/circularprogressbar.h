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

    enum TYPE{FILLING, ROUNDING};

    explicit CircularProgressBar(QWidget *parent = 0, TYPE typ = FILLING);

    void setColor(QColor color);        //Sets a color of fill; Default color is black
    void setType(TYPE typ);
    void renderValue(bool b);

    int getValue() const;       //This fucntion returns a progressbar value which is stored ind _value variable (0.. 100)
    bool isRenderValue() const;
    QPoint getCenter() const;
    QFont getValueFont() const;
    QColor getColor() const;

protected:

    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent* event);

private:

    TYPE _type;
    int _radius;
    bool _renderVal;
    int _value;
    QPoint _center;
    QColor _fillColor;
    QFont _valueFont;

signals:
    void valueChanged(int value);       //This singnal is emited always when the setValue slot has occurred

public slots:
    void setValue(int value);           //Sets a value of progressbar (0.. 100)

};

#endif // CIRCULARPROGRESSBAR_H

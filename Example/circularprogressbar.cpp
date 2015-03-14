#include "circularprogressbar.h"


CircularProgressBar::CircularProgressBar(QWidget *parent, TYPE typ) :
    QWidget(parent), _type(typ), _renderVal(true), _value(0)
{
    _radius = qMin(this->width()/2, this->height()/2)-1;
    _center = QPoint(this->width()/2,this->height()/2);
    _fillColor = Qt::black;
    _valueFont.setFamily("calibri");
}

void CircularProgressBar::paintEvent(QPaintEvent* /*event*/)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(_center,_radius,_radius);
    if(_value < 0){
        _value=0;
    }
    if(_value > 100){
        _value=100;
    }

    switch(_type){
    case FILLING:{
        painter.setBrush(QBrush(_fillColor));
        painter.drawEllipse(_center, _radius*_value/100, _radius*_value/100);
        break;
    }
    case ROUNDING:{
        if(_value != 0 && _value != 100){
            painter.setBrush(QBrush(_fillColor));
            double val = (double)_value;

            int startAngle = 90 * 16;
            int spanAngle = val/100*360 * 16 * -1;
            QRectF rectangle(_center.x()-_radius,_center.y()-_radius,_radius*2,_radius*2);
            painter.drawPie(rectangle,startAngle,spanAngle);

        }
        if(_value == 100){
            painter.setBrush(QBrush(_fillColor));
            painter.drawEllipse(_center, _radius*_value/100, _radius*_value/100);
        }
        break;
    }
    }

    if(_renderVal){
        QFontMetrics fm(_valueFont);
        int val_width = fm.width(QString::number(_value)+"%");
        QPoint point(_center.x()-val_width/2,_center.y()+fm.height()/3);
        painter.setFont(_valueFont);
        painter.drawText(point, QString::number(_value)+"%");
    }

}

void CircularProgressBar::resizeEvent(QResizeEvent* /*event*/)
{
    _center = QPoint(this->width()/2,this->height()/2);
    _radius = qMin(this->width()/2, this->height()/2)-1;
    _valueFont.setPixelSize((int)(2.0/10*_radius));
    repaint();
}

void CircularProgressBar::setValue(int value)
{
    _value = value;
    emit valueChanged(_value);
    repaint();
}

int CircularProgressBar::getValue() const
{
    return _value;
}

bool CircularProgressBar::isRenderValue() const
{
    return _renderVal;
}

void CircularProgressBar::setColor(QColor color)
{
    _fillColor = color;
    repaint();
}

void CircularProgressBar::setType(CircularProgressBar::TYPE typ)
{
    _type = typ;
    repaint();
}

QPoint CircularProgressBar::getCenter() const
{
    return _center;
}

void CircularProgressBar::renderValue(bool b)
{
    _renderVal = b;
    repaint();
}

QFont CircularProgressBar::getValueFont() const
{
    return _valueFont;
}

QColor CircularProgressBar::getColor() const
{
    return _fillColor;
}

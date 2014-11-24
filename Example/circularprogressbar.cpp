#include "circularprogressbar.h"


CircularProgressBar::CircularProgressBar(QWidget *parent) :
    QWidget(parent)
{
    radius = qMin(this->width()/2, this->height()/2);
    center = QPoint(this->width()/2,this->height()/2);
    fillColor = Qt::black;
}

void CircularProgressBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //painter.setBrush(QBrush(borderColor));
    painter.drawEllipse(center,radius,radius);
    if(m_x < 0){
        m_x=0;
    }
    if(m_x > 100){
        m_x=100;
    }else{
        painter.setBrush(QBrush(fillColor));
        painter.drawEllipse(center, radius*m_x/100, radius*m_x/100);
    }
}

void CircularProgressBar::resizeEvent(QResizeEvent *event)
{
    center = QPoint(this->width()/2,this->height()/2);
    radius = qMin(this->width()/2, this->height()/2);
    repaint();
}

void CircularProgressBar::setValue(int x)
{
    m_x = x;
    emit valueChanged(m_x);
    repaint();
}

int CircularProgressBar::getValue() const
{
    return m_x;
}

void CircularProgressBar::setColor(QColor color)
{
    fillColor = color;
    repaint();
}

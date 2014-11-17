#include "circleprogressbar.h"

CircleProgressBar::CircleProgressBar(QWidget *parent) :
    QWidget(parent)
{
    radius = qMin(this->width()/2, this->height()/2);
    center = QPoint(this->width()/2,this->height()/2);
}

void CircleProgressBar::setValue(int x)
{
    m_x = x;
    repaint();
}

void CircleProgressBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawEllipse(center,radius,radius);

    if(m_x < 0){
        m_x=0;
    }
    if(m_x > 100){
        m_x=100;
    }else{
        painter.setBrush(QBrush(Qt::black));
        painter.drawEllipse(center, radius*m_x/100, radius*m_x/100);
    }

}

void CircleProgressBar::resizeEvent(QResizeEvent *event)
{
    center = QPoint(this->width()/2,this->height()/2);
    radius = qMin(this->width()/2, this->height()/2);
    repaint();
}


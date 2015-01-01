#include "circularprogressbar.h"


CircularProgressBar::CircularProgressBar(QWidget *parent, TYPE typ) :
    QWidget(parent)
{
    radius = qMin(this->width()/2, this->height()/2);
    center = QPoint(this->width()/2,this->height()/2);
    fillColor = Qt::black;
}

void CircularProgressBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawEllipse(center,radius,radius);
    if(m_x < 0){
        m_x=0;
    }
    if(m_x > 100){
        m_x=100;
    }


    switch(m_type){
    case FILLING:{
        painter.setBrush(QBrush(fillColor));
        painter.drawEllipse(center, radius*m_x/100, radius*m_x/100);
        break;
    }
    case ROUNDING:{
        if(m_x != 0 && m_x != 100){
            painter.setBrush(QBrush(fillColor));
            painter.drawLine(center.x(),center.y(),center.x(),center.y()-radius);
            double val = (double)m_x;
            double angle = qDegreesToRadians(val/100*360);

            int sinAR = (int) (qSin(angle)*radius);
            int cosAR = (int) (qCos(angle)*radius);

            if(m_x <= 25){
                painter.drawLine(center.x(),center.y(),center.x()+sinAR,center.y()-cosAR);
            }
            if(m_x > 25 && m_x <= 50){
                painter.drawLine(center.x(),center.y(),center.x()+sinAR,center.y()-cosAR);
            }
            if(m_x > 50 && m_x <= 75){
                painter.drawLine(center.x(),center.y(),center.x()+sinAR,center.y()-cosAR);
            }
            if(m_x > 75 && m_x <= 100){
                painter.drawLine(center.x(),center.y(),center.x()+sinAR,center.y()-cosAR);
            }
        }
        if(m_x == 100){
            painter.setBrush(QBrush(fillColor));
            painter.drawEllipse(center, radius*m_x/100, radius*m_x/100);
        }
        break;
    }
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

void CircularProgressBar::setType(CircularProgressBar::TYPE typ)
{
    m_type = typ;
    repaint();
}

QPoint CircularProgressBar::getCenter() const
{
    return center;
}

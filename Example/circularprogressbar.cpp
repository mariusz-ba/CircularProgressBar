#include "circularprogressbar.h"


CircularProgressBar::CircularProgressBar(QWidget *parent, TYPE typ) :
    QWidget(parent), m_type(typ), renderVal(true), m_x(0)
{
    radius = qMin(this->width()/2, this->height()/2)-1;
    center = QPoint(this->width()/2,this->height()/2);
    fillColor = Qt::black;
    valueFont.setFamily("calibri");
}

void CircularProgressBar::paintEvent(QPaintEvent* /*event*/)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
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
            double val = (double)m_x;

            int startAngle = 90 * 16;
            int spanAngle = val/100*360 * 16 * -1;
            QRectF rectangle(center.x()-radius,center.y()-radius,radius*2,radius*2);
            painter.drawPie(rectangle,startAngle,spanAngle);

        }
        if(m_x == 100){
            painter.setBrush(QBrush(fillColor));
            painter.drawEllipse(center, radius*m_x/100, radius*m_x/100);
        }
        break;
    }
    }

    if(renderVal){
        QFontMetrics fm(valueFont);
        int val_width = fm.width(QString::number(m_x)+"%");
        QPoint point(center.x()-val_width/2,center.y()+fm.height()/3);
        painter.setFont(valueFont);
        painter.drawText(point, QString::number(m_x)+"%");
    }

}

void CircularProgressBar::resizeEvent(QResizeEvent* /*event*/)
{
    center = QPoint(this->width()/2,this->height()/2);
    radius = qMin(this->width()/2, this->height()/2)-1;
    valueFont.setPixelSize((int)(2.0/10*radius));
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

bool CircularProgressBar::isRenderValue() const
{
    return renderVal;
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

void CircularProgressBar::renderValue(bool b)
{
    renderVal = b;
    repaint();
}

QFont CircularProgressBar::getValueFont() const
{
    return valueFont;
}

QColor CircularProgressBar::getColor() const
{
    return fillColor;
}

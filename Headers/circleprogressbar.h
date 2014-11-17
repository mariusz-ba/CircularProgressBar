#ifndef CIRCLEPROGRESSBAR_H
#define CIRCLEPROGRESSBAR_H

#include <QWidget>
#include <QtGui>

class CircleProgressBar : public QWidget
{
    Q_OBJECT
public:
    explicit CircleProgressBar(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent* event);

private:
    int radius;
    int m_x;
    QPoint center;

signals:

public slots:
    void setValue(int x);
};

#endif // CIRCLEPROGRESSBAR_H

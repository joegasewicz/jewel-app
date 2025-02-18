//
// Created by Joe (Personal) on 17/02/2025.
//

#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsPathItem>
#include <QMouseEvent>
#include <QVector>


class Canvas : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QGraphicsScene *scene;
    QVector<QGraphicsEllipseItem*> controlPointItems;
    QGraphicsPathItem *currentPathItem;

    void updateBezierCurve();
};


#endif //CANVAS_H

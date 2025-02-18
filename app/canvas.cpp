//
// Created by Joe (Personal) on 17/02/2025.
//

#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QGraphicsView(parent), currentPathItem(nullptr)
{
    scene = new QGraphicsScene(this);
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setDragMode(QGraphicsView::RubberBandDrag);
}


void Canvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPointF scenePos = mapToScene(event->pos());

        // Create a draggable control point
        QGraphicsEllipseItem *controlPoint = scene->addEllipse(
            scenePos.x() -5, scenePos.y() -5, 10, 10,
            QPen(Qt::green), QBrush(Qt::blue)
        );
        controlPoint->setFlag(QGraphicsItem::ItemIsMovable);
        controlPointItems.append(controlPoint);


        if (controlPointItems.size() == 4)
        {
            // creates a Bezier curve when we have 4 control points
            currentPathItem = scene->addPath(QPainterPath(), QPen(Qt::green, 2));
            updateBezierCurve();
        }
    }
    QGraphicsView::mousePressEvent(event);
}


void Canvas::updateBezierCurve() {
    if (controlPointItems.size() < 4 || !currentPathItem) return;

    // Get the control points updated positions
    QPointF p0 = controlPointItems[0]->scenePos() + QPointF(5, 5);
    QPointF p1 = controlPointItems[1]->scenePos() + QPointF(5, 5);
    QPointF p2 = controlPointItems[2]->scenePos() + QPointF(5, 5);
    QPointF p3 = controlPointItems[3]->scenePos() + QPointF(5, 5);

    // Create and update the bezier path
    QPainterPath path;
    path.moveTo(p0);
    path.cubicTo(p1, p2, p3);
    currentPathItem->setPath(path);
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    updateBezierCurve();
    QGraphicsView::mouseMoveEvent(event);
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    updateBezierCurve();
    QGraphicsView::mouseReleaseEvent(event);
}


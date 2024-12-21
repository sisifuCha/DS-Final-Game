#ifndef IMAGEOBJECT_H
#define IMAGEOBJECT_H

#endif // IMAGEOBJECT_H
#include <QGraphicsObject>
#include <QImage>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

class ImageObject : public QGraphicsObject {
    Q_OBJECT
    Q_PROPERTY(QPointF position READ pos WRITE setPos NOTIFY positionChanged)

public:
    ImageObject(const QImage &image, QGraphicsItem *parent = nullptr)
        : QGraphicsObject(parent), m_image(image) {}

    QRectF boundingRect() const override {
        return QRectF(QPointF(0, 0), m_image.size());
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override {
        painter->drawImage(boundingRect(), m_image);
    }

    QPointF pos() const {
        return scenePos();
    }

    void setPos(const QPointF &pos) {
        if (pos != scenePos()) {
            this->setPos(pos);
            emit positionChanged();
        }
    }

signals:
    void positionChanged();

private:
    QImage m_image;
};

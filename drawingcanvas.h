#ifndef DRAWINGCANVAS_H
#define DRAWINGCANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include <QVector>
#include <QPoint>
#include <QRect>
#include <vector>
#include "CustomMatrix.h"

class DrawingCanvas : public QWidget {
    Q_OBJECT

public:
    explicit DrawingCanvas(QWidget *parent = nullptr);

    const int WINDOW_WIDTH = 400;
    const int WINDOW_HEIGHT = 400;

public slots:
    void paintLines();
    void clearPoints();
    void segmentDetection();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QVector<QPoint> m_points;
    std::vector<CustomMatrix> windows;
    std::vector<QRect> detectedWindows;
    bool isPaintLinesClicked = false;
};

#endif // DRAWINGCANVAS_H

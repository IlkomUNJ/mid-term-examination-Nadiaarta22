#include "drawingcanvas.h"
#include "CustomMatrix.h"
#include <QPainter>
#include <QImage>
#include <QDebug>
#include <iostream>
using namespace std;

DrawingCanvas::DrawingCanvas(QWidget *parent) {
    setMinimumSize(this->WINDOW_WIDTH, this->WINDOW_HEIGHT);
    setStyleSheet("background-color: white; border: 1px solid gray;");
}

void DrawingCanvas::clearPoints() {
    m_points.clear();
    detectedWindows.clear();
    update();
}

void DrawingCanvas::paintLines() {
    isPaintLinesClicked = true;
    update();
}

void DrawingCanvas::segmentDetection() {
    QPixmap pixmap = this->grab();
    QImage image = pixmap.toImage();

    cout << "image width " << image.width() << endl;
    cout << "image height " << image.height() << endl;

    int windowSize = 3;
    int half = windowSize / 2;

    detectedWindows.clear();

    for (int i = half; i < image.width() - half; i++) {
        for (int j = half; j < image.height() - half; j++) {
            bool local_window[3][3] = {false};

            int activePixels = 0;

            for (int m = -half; m <= half; m++) {
                for (int n = -half; n <= half; n++) {
                    QRgb rgbValue = image.pixel(i + m, j + n);
                    bool isActive = (rgbValue != 0xffffffff);
                    local_window[m + half][n + half] = isActive;
                    if (isActive) activePixels++;
                }
            }

            if (activePixels > 0) {
                CustomMatrix mat(local_window);
                detectedWindows.push_back(QRect(i - half, j - half, windowSize, windowSize));
                windows.push_back(mat);
            }
        }
    }

    cout << "Total detected windows: " << detectedWindows.size() << endl;

    update();
}

void DrawingCanvas::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::blue, 5);
    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::blue));

    for (const QPoint &point : std::as_const(m_points)) {
        painter.drawEllipse(point, 3, 3);
    }

    if (isPaintLinesClicked) {
        pen.setColor(Qt::red);
        pen.setWidth(4);
        pen.setStyle(Qt::SolidLine);
        painter.setPen(pen);

        for (int i = 0; i < m_points.size() - 1; i += 2) {
            painter.drawLine(m_points[i], m_points[i + 1]);
        }
        isPaintLinesClicked = false;
    }

    if (!detectedWindows.empty()) {
        pen.setColor(Qt::magenta);
        pen.setWidth(1);
        painter.setPen(pen);

        for (const QRect &rect : detectedWindows) {
            painter.drawRect(rect);
        }
    }
}

void DrawingCanvas::mousePressEvent(QMouseEvent *event) {
    m_points.append(event->pos());
    update();
}

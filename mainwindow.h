#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "drawingcanvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    DrawingCanvas *m_canvas;
    QPushButton *m_clearButton;
    QPushButton *m_detectButton;
    QPushButton *m_drawButton;
};

#endif

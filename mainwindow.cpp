#include "mainwindow.h"
#include "drawingcanvas.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    m_canvas = new DrawingCanvas(this);
    mainLayout->addWidget(m_canvas, 1);

    m_drawButton = new QPushButton("Draw Lines", this);
    m_detectButton = new QPushButton("Detect Segment", this);
    m_clearButton = new QPushButton("Clear Canvas", this);

    buttonLayout->addWidget(m_drawButton);
    buttonLayout->addWidget(m_detectButton);
    buttonLayout->addWidget(m_clearButton);

    mainLayout->addLayout(buttonLayout);

    connect(m_clearButton, &QPushButton::clicked, m_canvas, &DrawingCanvas::clearPoints);
    connect(m_drawButton, &QPushButton::clicked, m_canvas, &DrawingCanvas::paintLines);
    connect(m_detectButton, &QPushButton::clicked, m_canvas, &DrawingCanvas::segmentDetection);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    setWindowTitle("Segment Detection - Computer Graphics");
    resize(500, 500);
}

MainWindow::~MainWindow() {}

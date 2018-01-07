#include "mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent)
{
    mainWidget = new QWidget;
    mainLayout = new QHBoxLayout(mainWidget);

    navigationWidget = new QNavigationWidget;
//    rightWidget->setFixedWidth(600 - navigationWidget->width());
    navigationWidget->setRowHeight(40);

    navigationWidget->addItem("个人问题");
    navigationWidget->addItem("问题总览");

    navigationWidget->addItem("补丁规划");
    navigationWidget->addItem("值守保障");
    navigationWidget->addItem("关于");

    showWidget = new QShowWidget;


    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(navigationWidget);
    mainLayout->addWidget(showWidget);
    
    setCentralWidget(mainWidget);
    connect(navigationWidget, &QNavigationWidget::currentItemChanged, showWidget, &QShowWidget::selectItem);
}

MainWindow::~MainWindow()
{
}

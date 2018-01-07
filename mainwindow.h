#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include "qnavigationwidget.h"
#include "modelview/qshowwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QMainWindow *parent=0);
    ~MainWindow();

private:
    QWidget *mainWidget;
    QHBoxLayout *mainLayout;
    QNavigationWidget *navigationWidget;
    QShowWidget* showWidget;
};	

#endif

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "dockwidgetconfig.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void handlerItemParamChanged(QString id);

private:
    Ui::MainWindow *ui;
    DockWidgetConfig *dockWidget;
};

#endif // MAINWINDOW_H

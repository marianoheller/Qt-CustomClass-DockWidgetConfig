#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dockWidget = new DockWidgetConfig();
    dockWidget->hide();
    dockWidget->setTitulo("Modificacion de imagenes.\nasdasdasd");
    dockWidget->addItem("Brillo",-100,100,0);
    this->addDockWidget(Qt::RightDockWidgetArea,dockWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    dockWidget->toggleShowHide();
}

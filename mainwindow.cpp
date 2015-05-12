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
    dockWidget->setWindowTitle("asd");
    dockWidget->addItem("Brillo",-100,100,0);
    dockWidget->addItem("QWEQWE",-100,300,200);
    this->addDockWidget(Qt::RightDockWidgetArea,dockWidget);
    connect(dockWidget,SIGNAL(itemParamChanged(QString)),this,SLOT(handlerItemParamChanged(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    dockWidget->toggleShowHide();
    static int faux=0;
    switch (faux) {
    case 0:
        dockWidget->addItem("REQRERWE",-100,300,200);
        break;
    case 1:
        dockWidget->removeItemAt(1);
    default:
        break;
    }faux++;
}


void MainWindow::handlerItemParamChanged(QString id)
{
    qDebug() << id;
}

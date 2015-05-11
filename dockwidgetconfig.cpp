#include "dockwidgetconfig.h"

DockWidgetConfig::DockWidgetConfig():
    QDockWidget()
{
    connect(this,SIGNAL(itemListChanged()),this,SLOT(handlerItemListChanged()));

    titulo.SeparadorFrame = new QFrame();
    titulo.SeparadorFrame->setFrameShape(QFrame::HLine);
    titulo.TituloLabel = new QLabel();
    titulo.isTit=false;
    titulo.isSeparador=false;
    mainVLayout = new QVBoxLayout();
    mainGroupBox = new QGroupBox();

    this->setWidget(mainGroupBox);
    mainGroupBox->setLayout(mainVLayout);

    itemList.clear();
}

DockWidgetConfig::~DockWidgetConfig()
{

}

void DockWidgetConfig::addItem(itemDockWidgetConfig_t *item)
{
    itemList.push_back(item);
    emit itemListChanged();
}

void DockWidgetConfig::addItem(QString nombre, int rangeMin, int rangeMax, int statingPoint)
{
    itemDockWidgetConfig_t *item = new itemDockWidgetConfig_t;
    item->Titulo = new QLabel(nombre);
    item->Slider = new QSlider( Qt::Horizontal);
    item->Slider->setRange(rangeMin,rangeMax);
    item->Slider->setSliderPosition(statingPoint);
    item->DoubleSpinBox=NULL;
    item->isDouble = false;
    item->Spinbox = new QSpinBox();
    item->Spinbox->setRange(rangeMin,rangeMax);
    item->Spinbox->setValue(statingPoint);

    item->localHLayout = new QHBoxLayout();
    item->localVLayout = new QVBoxLayout();

    itemList.push_back(item);
    emit itemListChanged();
}

void DockWidgetConfig::addItem(QString nombre, float rangeMin, float rangeMax, float statingPoint)
{
    itemDockWidgetConfig_t *item = new itemDockWidgetConfig_t;
    item->Titulo = new QLabel(nombre);
    item->Slider = new QSlider( Qt::Horizontal );
    item->Slider->setRange(rangeMin,rangeMax);
    item->Slider->setSliderPosition(statingPoint);
    item->Spinbox=NULL;
    item->isDouble = true;
    item->DoubleSpinBox = new QDoubleSpinBox();
    item->DoubleSpinBox->setRange(rangeMin,rangeMax);
    item->DoubleSpinBox->setValue(statingPoint);

    item->localHLayout = new QHBoxLayout();
    item->localVLayout = new QVBoxLayout();

    itemList.push_back(item);
    emit itemListChanged();
}


void DockWidgetConfig::setItems(QVector<itemDockWidgetConfig_t *> list)
{
    itemList.clear();
    itemList = list;
    emit itemListChanged();
}

void DockWidgetConfig::removeItemAt(int index)
{
    itemList.removeAt(index);
    emit itemListChanged();
}

void DockWidgetConfig::removeItem(itemDockWidgetConfig_t *itemPtr)
{
    itemList.removeOne(itemPtr);
    emit itemListChanged();
}

void DockWidgetConfig::clearItems()
{
    itemList.clear();
    emit itemListChanged();
}

int DockWidgetConfig::indexOf(itemDockWidgetConfig_t *itemPtr)
{
    return itemList.indexOf(itemPtr);
}

itemDockWidgetConfig_t* DockWidgetConfig::getItemAt(int index)
{
    return itemList.at(index);
}

QVector<itemDockWidgetConfig_t *> DockWidgetConfig::getItems()
{
    QVector<itemDockWidgetConfig_t *> aux = itemList;
    return aux;
}

int DockWidgetConfig::itemCount()
{
    return itemList.count();
}

void DockWidgetConfig::handlerItemListChanged()
{

    //Titulo
    if (titulo.isTit)
    {
        mainVLayout->addWidget(titulo.TituloLabel);
    }
    if (titulo.isSeparador)
    {
        mainVLayout->addWidget(titulo.SeparadorFrame);
    }
    //Items
    for (int i=0;i< itemList.size() ; i++)
    {
        itemList.at(i)->localVLayout->addWidget(itemList.at(i)->Titulo);
        itemList.at(i)->localHLayout->addWidget(itemList.at(i)->Slider);
        if (itemList.at(i)->isDouble)
            itemList.at(i)->localHLayout->addWidget(itemList.at(i)->DoubleSpinBox);
        else
            itemList.at(i)->localHLayout->addWidget(itemList.at(i)->Spinbox);
        itemList.at(i)->localVLayout->addLayout(itemList.at(i)->localHLayout);
    }
}


void DockWidgetConfig::setTitulo(QString tit)
{
    titulo.TituloLabel->setText(tit);
    titulo.isTit = true;
}

QString DockWidgetConfig::getTitulo()
{
    return titulo.TituloLabel->text();
}

void DockWidgetConfig::setSeparador(bool isSep)
{
    titulo.isSeparador=isSep;
}


void DockWidgetConfig::toggleShowHide()
{
    if (this->isHidden())
        this->show();
    else
        this->hide();
}

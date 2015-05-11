#include "dockwidgetconfig.h"

DockWidgetConfig::DockWidgetConfig():
    QDockWidget()
{
    connect(this,SIGNAL(itemListChanged()),this,SLOT(handlerItemListChanged()));

    titulo.TituloLabel=NULL;
    titulo.SeparadorFrame=NULL;
    titulo.isTit=false;
    titulo.isSeparador=false;

    itemList.clear();
}

DockWidgetConfig::~DockWidgetConfig()
{

}

void DockWidgetConfig::addItem(itemDockWidgetConfig_t *item)
{
    itemList.push_back(item);
    emit itemListChanged;
}


void DockWidgetConfig::setItems(QVector<itemDockWidgetConfig_t *> list)
{
    itemList.clear();
    itemList = list;
    emit itemListChanged;
}

void DockWidgetConfig::removeItemAt(int index)
{
    itemList.removeAt(index);
    emit itemListChanged;
}

void DockWidgetConfig::removeItem(itemDockWidgetConfig_t *itemPtr)
{
    itemList.removeOne(itemPtr);
    emit itemListChanged;
}

void DockWidgetConfig::clearItems()
{
    itemList.clear();
    emit itemListChanged;
}

void DockWidgetConfig::indexOf(itemDockWidgetConfig_t *itemPtr)
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

}


void DockWidgetConfig::setTitulo(QString tit)
{
    titulo.TituloLabel->setText(tit);
}

QString DockWidgetConfig::getTitulo()
{
    return titulo.TituloLabel->text();
}

void DockWidgetConfig::setSeparador(bool isSep)
{
    titulo.isSeparador=isSep;
}

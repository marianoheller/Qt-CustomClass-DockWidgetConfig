#ifndef DOCKWIDGETCONFIG_H
#define DOCKWIDGETCONFIG_H


#include <QDockWidget>
#include <QLayout>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QGroupBox>
#include <QSpacerItem>
#include <QFrame>
#include <QSignalMapper>


typedef struct {
    QLabel *Titulo;
    QSlider *Slider;
    QSpinBox *Spinbox;
    QDoubleSpinBox *DoubleSpinBox;
    bool isDouble;

    QVBoxLayout *localVLayout;
    QHBoxLayout *localHLayout;
} itemDockWidgetConfig_t;

typedef struct {
    QLabel *TituloLabel;
    QFrame *SeparadorFrame;
    bool isTit;
    bool isSeparador;
} tituloDockWidgetConfig_t;

class DockWidgetConfig : public QDockWidget
{
    Q_OBJECT
public:
    DockWidgetConfig();
    ~DockWidgetConfig();
    //virtual QSize sizeHint () const;
    void toggleShowHide();

    ///ITEMS
    void setItems( QVector <itemDockWidgetConfig_t*> list);
    void addItem (itemDockWidgetConfig_t *item);
    void addItem(QString nombre,int rangeMin, int rangeMax, int statingPoint);
    void addItem(QString nombre,float rangeMin, float rangeMax, float statingPoint);
    QVector <itemDockWidgetConfig_t*> getItems();
    itemDockWidgetConfig_t* getItemAt(int index);
    int itemCount();
    void removeItemAt(int index);
    void removeItem(itemDockWidgetConfig_t* itemPtr);
    void clearItems();
    int indexOf(itemDockWidgetConfig_t *itemPtr);

    ///Titulo
    QString getTitulo();
    void setTitulo(QString tit);
    void setSeparador(bool isSep);
signals:
    itemListChanged();
    itemParamChanged(QString id);

private slots:
    void handlerItemListChanged();
    //void handlerMapItemParamChanged(QString);

private:
    QVector <itemDockWidgetConfig_t*> itemList;
    tituloDockWidgetConfig_t titulo;
    QVBoxLayout *mainVLayout;
    QGroupBox *mainGroupBox;
    QSpacerItem *lastSpacer;
};

#endif // DOCKWIDGETCONFIG_H

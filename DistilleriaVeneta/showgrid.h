#ifndef SHOWGRID_H
#define SHOWGRID_H

#include <QScrollArea>
#include <QGridLayout>
#include <QFrame>

#include "qproduct.h"
#include "controller.h"

class showgrid : public QWidget
{
    Q_OBJECT
private:
    QScrollArea *product_area;
    QFrame *contenitore;
    QGridLayout *layout;
    controller* presenter;

public:
    showgrid(QWidget* = nullptr);
    void setcontroller(controller*);
};

#endif // SHOWGRID_H

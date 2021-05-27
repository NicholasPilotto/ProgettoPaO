#ifndef TABLEROW_H
#define TABLEROW_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSpinBox>
#include <QList>
#include "gridshow.h"

class tablerow : public QWidget
{
    Q_OBJECT
private:

    QTableWidgetItem* bin_item;
    QTableWidgetItem* name_item;
    QTableWidgetItem* dim_item;
    QTableWidgetItem* price_item;

public:
    tablerow(QWidget* = nullptr);
    void set_row(const deep_ptr<product> &, int, QTableWidget*&, int);
};

#endif // TABLEROW_H

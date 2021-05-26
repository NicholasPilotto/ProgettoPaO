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
    QList<QTableWidgetItem*> list_items;
    QList<std::pair<QList<QTableWidgetItem*>,QSpinBox*>> list_table;
public:
    tablerow(/*const deep_ptr<product>&, int, QTableWidget*&, int,*/ QWidget* = nullptr);
    void set_rows(const deep_ptr<product> &, int, QTableWidget*&, int);
};

#endif // TABLEROW_H

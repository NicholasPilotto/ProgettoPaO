#ifndef RECEIPTSHOW_H
#define RECEIPTSHOW_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QIcon>

#include "Hierarchy/product.h"
#include "Utilities/deep_ptr.hpp"
#include "Utilities/u_vector.hpp"
using std::pair;

class receiptshow : public QWidget
{
    Q_OBJECT
private:
    QTableWidget* table;
public:
    receiptshow(const u_vector<std::pair<deep_ptr<product>,int>>&, QWidget* = nullptr);
    void addTable(QVBoxLayout*);
    void refreshTable(const u_vector<std::pair<deep_ptr<product>,int>>&);
};

#endif // RECEIPTSHOW_H

#ifndef SHOWRECEIPT_H
#define SHOWRECEIPT_H

#include "controller.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSpinBox>
#include <QHeaderView>
#include <QIcon>
#include <QMessageBox>

class showreceipt : public QWidget {
    Q_OBJECT
private:
    controller* presenter;
    QTableWidget* table;

    void addTable(QVBoxLayout*);
    void refreshtable() const;
    void showdeleteline();
    void setcontroller(controller* c);

public:
    explicit showreceipt(QWidget* = nullptr);
};

#endif // SHOWRECEIPT_H

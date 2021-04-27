#ifndef RECEIPTSHOW_H
#define RECEIPTSHOW_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QIcon>

class receiptshow : public QWidget
{
    Q_OBJECT
private:
    QTableWidget* table;
    QVBoxLayout* table_layout;
public:
    receiptshow(QWidget* = nullptr);
    void addTable();
};

#endif // RECEIPTSHOW_H

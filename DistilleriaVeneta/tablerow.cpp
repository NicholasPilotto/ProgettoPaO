#include "tablerow.h"

tablerow::tablerow(/*const deep_ptr<product> & p, int value_spin, QTableWidget*& table, int riga,*/ QWidget * parent) : QWidget(parent) {
//    set_rows(p,value_spin,table,riga);
}

void tablerow::set_rows(const deep_ptr<product> & p, int value_spin, QTableWidget*& table, int riga) { // p è (*cit).first e value_spin è (*cit).second

    table->setRowHeight(riga, 50);

    // Inserimento icona cestino

    const QIcon* icon = new QIcon("../Grafica/Immagini/delete.png");
    QTableWidgetItem* bin_item = new QTableWidgetItem(*icon, "");
    table->setVerticalHeaderItem(riga, bin_item);

    // Inserimento nome

    QTableWidgetItem* name_item = new QTableWidgetItem();
    name_item->setText(p->get_name().data());
    name_item->setTextAlignment(Qt::AlignCenter);
    table->setItem(riga, 0, name_item);
    list_items.append(name_item);

    // Inserimento grandezza bottiglia

    QTableWidgetItem* dim_item = new QTableWidgetItem();
    dim_item->setText(QString::fromStdString(p->fromKindToStdString(p->get_kind())));
    dim_item->setTextAlignment(Qt::AlignCenter);
    table->setItem(riga, 1, dim_item);
    list_items.append(dim_item);

    // Inserimento SpinBox

    QSpinBox* num_item = new QSpinBox();
    num_item->setRange(1, 2147483647);
    table->setCellWidget(riga, 2, num_item);

    // Inserimento totale per linea

    QTableWidgetItem* price_item = new QTableWidgetItem();
    price_item->setText(QString::number(p->get_price()*value_spin, 'f', 2) + " €");
    price_item->setTextAlignment(Qt::AlignCenter);
    table->setItem(riga, 3, price_item);
    list_items.append(price_item);

    std::pair<QList<QTableWidgetItem*>,QSpinBox*> aux;
    aux.first.append(list_items);
    aux.second = num_item;

    list_table.append(aux);
}

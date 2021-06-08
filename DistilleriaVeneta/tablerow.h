#ifndef TABLEROW_H
#define TABLEROW_H

#include <QList>
#include <QObject>
#include <QSpinBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QWidget>

#include "receiptshow.h"

class tablerow : public QWidget {
  Q_OBJECT
 private:
  QTableWidgetItem* bin_item;
  QTableWidgetItem* name_item;
  QTableWidgetItem* dim_item;
  QSpinBox* num_item;
  QTableWidgetItem* price_item;
  QTableWidget* table;

  const QIcon* icon;

 public:
  /**
   * @brief costruttore di tablerow
   * @param t : QTableWidget*&, puntatore passato per riferimento indicante lo socntrino
   */
  tablerow(QTableWidget*&);

  ~tablerow();

  /**
   * @brief metodo setter per settare le righe dello scontrino
   * @param p : const deep_ptr<product>&, indirizzo del prodotto da inserire nello scontrino
   * @param value_spin : int, indica la quantità del prodotto
   * @param riga : int, indica la posizione nello scontrino
   */
  void set_row(const deep_ptr<product>&, int, int);

  /**
   * @brief metodo getter per avere lo spinbox della riga dello scontrino
   * @return QSpinBox*&, puntatore per riferimento allo spinbox
   */
  QSpinBox*& get_spin();
};

#endif  // TABLEROW_H

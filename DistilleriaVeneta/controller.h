#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "view.h"

class controller : public QObject {
  Q_OBJECT
 private:
  view* view;

 public:
  explicit controller(QObject* = nullptr);
  virtual ~controller();
};

#endif // CONTROLLER_H

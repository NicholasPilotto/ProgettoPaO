#ifndef QSTACKEDWIDGETHOVER_H
#define QSTACKEDWIDGETHOVER_H

#include <QEvent>
#include <QFrame>
#include <QHoverEvent>
#include <QStackedWidget>
#include <QWidget>

#include "overlay.h"
#include "qproduct.h"

class QStackedWidgetHover : public QStackedWidget {
  Q_OBJECT
 protected:
  void hoverEnter(QHoverEvent*);
  void hoverLeave(QHoverEvent*);
  void hoverMove(QHoverEvent*);
  bool event(QEvent*);

 public:
  explicit QStackedWidgetHover(QProduct*, QOverlay*, QStackedWidget* = nullptr);
};

#endif  // QSTACKEDWIDGETHOVER_H

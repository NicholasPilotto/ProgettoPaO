#ifndef QSTACKEDWIDGETHOVER_H
#define QSTACKEDWIDGETHOVER_H

#include <QWidget>
#include <QFrame>
#include <QStackedWidget>
#include <QEvent>
#include <QHoverEvent>

#include "qproduct.h"
#include "overlay.h"

class QStackedWidgetHover : public QStackedWidget
{
    Q_OBJECT
protected:
    void hoverEnter(QHoverEvent*);
    void hoverLeave(QHoverEvent*);
    void hoverMove(QHoverEvent*);
    bool event(QEvent*);
public:
    explicit QStackedWidgetHover(QProduct*, QOverlay*, QStackedWidget* = nullptr);
};

#endif // QSTACKEDWIDGETHOVER_H

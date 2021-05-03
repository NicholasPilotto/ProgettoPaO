#include "grid_element.h"

grid_element::grid_element(QProduct* p, overlay* o, QStackedWidget* parent) : QStackedWidget(parent)
{
    addWidget(p);
    addWidget(o);
}

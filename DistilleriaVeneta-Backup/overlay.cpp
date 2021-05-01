#include "overlay.h"

overlay::overlay(QWidget* parent) : QWidget(parent)
{
    overlay_layout = new QVBoxLayout();
    small_button = new QPushButton("Small");
    medium_button = new QPushButton("Medium");
    large_button = new QPushButton("Large");

    overlay_layout->addWidget(small_button);
    overlay_layout->addWidget(medium_button);
    overlay_layout->addWidget(large_button);

    setLayout(overlay_layout);

}

#include "overlay.h"

QOverlay::QOverlay(QWidget* parent) : QWidget(parent) {
  // Creazione layout

  overlay_layout = new QVBoxLayout(this);

  // Creazione bottoni

  small_button = new QPushButton("Small", this);
  medium_button = new QPushButton("Medium", this);
  large_button = new QPushButton("Large", this);

  // Aggiunta bottoni

  overlay_layout->addWidget(small_button);
  overlay_layout->addWidget(medium_button);
  overlay_layout->addWidget(large_button);

  // Set Layout

  setLayout(overlay_layout);
}


QPushButton* QOverlay::get_small_button() const {return small_button;}

QPushButton* QOverlay::get_medium_button() const {return medium_button;}

QPushButton* QOverlay::get_large_button() const {return large_button;}

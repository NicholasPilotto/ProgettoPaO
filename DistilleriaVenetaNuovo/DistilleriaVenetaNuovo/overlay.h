#ifndef OVERLAY_H
#define OVERLAY_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class QOverlay : public QWidget {
  Q_OBJECT
 private:
  QVBoxLayout* overlay_layout;
  QPushButton* small_button;
  QPushButton* medium_button;
  QPushButton* large_button;


 public:
  explicit QOverlay(QWidget* = nullptr);
};

#endif  // OVERLAY_H

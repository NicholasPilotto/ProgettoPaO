#ifndef OVERLAY_H
#define OVERLAY_H


#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class overlay : public QWidget
{
    Q_OBJECT
private:
    QPushButton* small_button;
    QPushButton* medium_button;
    QPushButton* large_button;
    QVBoxLayout* overlay_layout;

public:
    overlay(QWidget* = nullptr);
};

#endif // OVERLAY_H

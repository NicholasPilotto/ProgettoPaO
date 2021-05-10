#-------------------------------------------------
#
# Project created by QtCreator 2021-05-07T10:35:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DistilleriaVenetaNuovo
TEMPLATE = app

CONFIG += c++1z

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    Hierarchy/cream.cpp \
    Hierarchy/grappa.cpp \
    Hierarchy/liquor.cpp \
    Hierarchy/non_spirits.cpp \
    Hierarchy/old.cpp \
    Hierarchy/product.cpp \
    Hierarchy/spirits.cpp \
    Hierarchy/young.cpp \
    io_json.cpp \
    receipt.cpp \
    model.cpp \
    controller.cpp \
    view.cpp \
    gridshow.cpp \
    qproduct.cpp \
    overlay.cpp \
    receiptshow.cpp

HEADERS += \
    Hierarchy/cream.h \
    Hierarchy/enum.h \
    Hierarchy/grappa.h \
    Hierarchy/liquor.h \
    Hierarchy/non_spirits.h \
    Hierarchy/old.h \
    Hierarchy/product.h \
    Hierarchy/spirits.h \
    Hierarchy/young.h \
    Utilities/deep_ptr.hpp \
    Utilities/u_vector.hpp \
    io_json.h \
    receipt.h \
    model.h \
    controller.h \
    view.h \
    gridshow.h \
    qproduct.h \
    overlay.h \
    receiptshow.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    resources.qrc

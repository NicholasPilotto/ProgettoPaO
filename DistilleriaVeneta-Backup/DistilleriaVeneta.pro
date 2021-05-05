QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++1z

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
  controller.cpp \
  filter.cpp \
    gridshow.cpp \
  io_json.cpp \
  main.cpp \
  model.cpp \
    qproduct.cpp \
  receipt.cpp \
    receiptshow.cpp \
  view.cpp \
  ./Hierarchy/product.cpp \
  ./Hierarchy/spirits.cpp \
  ./Hierarchy/grappa.cpp \
  ./Hierarchy/old.cpp \
  ./Hierarchy/young.cpp \
  ./Hierarchy/liquor.cpp \
  ./Hierarchy/non_spirits.cpp \
  ./Hierarchy/cream.cpp \
    overlay.cpp \
    grid_element.cpp

HEADERS += \
  controller.h \
  filter.h \
    gridshow.h \
  io_json.h \
    qproduct.h \
  receipt.h \
  model.h \
    receiptshow.h \
  view.h \
  ./Hierarchy/enum.h \
  ./Hierarchy/product.h \
  ./Hierarchy/spirits.h \
  ./Hierarchy/grappa.h \
  ./Hierarchy/old.h \
  ./Hierarchy/young.h \
  ./Hierarchy/liquor.h \
  ./Hierarchy/non_spirits.h \
  ./Hierarchy/cream.h \
  ./Utilities/u_vector.hpp \
  ./Utilities/deep_ptr.hpp \
  ./Utilities/aux_func.hpp \
    overlay.h \
    grid_element.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
  recources.qrc

macos:ICON = juice.icns

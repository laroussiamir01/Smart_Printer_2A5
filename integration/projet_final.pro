
QT       += core gui sql charts network printsupport
QT += sql
QT += charts
QT += printsupport
QT += serialport



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    achat.cpp \
    arduino.cpp \
    client.cpp \
    commande.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    materiel.cpp \
    personnel.cpp \
    reclamation.cpp \
    service.cpp

HEADERS += \
    achat.h \
    arduino.h \
    client.h \
    commande.h \
    connection.h \
    mainwindow.h \
    materiel.h \
    personnel.h \
    reclamation.h \
    service.h \
    stat_combo.h \
    stat_combo_com.h \
    stat_combo_mat.h \
    stat_combo_perso.h

FORMS += \
    mainwindow.ui \
    stat_combo.ui \
    stat_combo_com.ui \
    stat_combo_mat.ui \
    stat_combo_perso.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
STATECHARTS +=

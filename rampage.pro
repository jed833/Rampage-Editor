TEMPLATE = app
TARGET = rampage
DEPENDPATH += .
INCLUDEPATH += .
CONFIG += link_pkgconfig
PKGCONFIG += python

QT += widgets

# Input
HEADERS += mainwindow.h editorblade.h
FORMS +=
SOURCES += main.cpp mainwindow.cpp editorblade.cpp
RESOURCES +=


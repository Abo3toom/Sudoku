QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sudoku-qt
TEMPLATE = app


SOURCES += main.cpp\
           mainwindow.cpp \
           matrix.cpp \
           rdarray.cpp


HEADERS  += mainwindow.h \
    include.h \
    matrix.h \
    rdarray.h

FORMS    += mainwindow.ui

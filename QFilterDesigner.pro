#-------------------------------------------------
#
# Project created by QtCreator 2013-03-28T13:36:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFilterDesigner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    iir/State.cpp \
    iir/RootFinder.cpp \
    iir/RBJ.cpp \
    iir/PoleFilter.cpp \
    iir/Legendre.cpp \
    iir/Elliptic.cpp \
    iir/Custom.cpp \
    iir/ChebyshevII.cpp \
    iir/ChebyshevI.cpp \
    iir/Cascade.cpp \
    iir/Butterworth.cpp \
    iir/Biquad.cpp \
    iir/Bessel.cpp \
    QCustomPlot/qcustomplot.cpp

HEADERS  += mainwindow.h \
    iir/Utilities.h \
    iir/Types.h \
    iir/State.h \
    iir/RootFinder.h \
    iir/RBJ.h \
    iir/PoleFilter.h \
    iir/MathSupplement.h \
    iir/Legendre.h \
    iir/Layout.h \
    iir/Elliptic.h \
    iir/Custom.h \
    iir/Common.h \
    iir/ChebyshevII.h \
    iir/ChebyshevI.h \
    iir/Cascade.h \
    iir/Butterworth.h \
    iir/Biquad.h \
    iir/Bessel.h \
    QCustomPlot/qcustomplot.h

FORMS    += mainwindow.ui

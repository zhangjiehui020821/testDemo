#-------------------------------------------------
#
# Project created by QtCreator 2021-01-22T11:18:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlutoMax
TEMPLATE = app

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
        widget.cpp \
    ImageDisplay.cpp \
    camerathread.cpp \
    hbasetype.cpp \
    hthreshold.cpp \
    hscaleimage.cpp \
    herosion.cpp \
    hdilation.cpp \
    hopening.cpp \
    hclosing.cpp \
    buttoncontextmenu.cpp \
    hmeanimage.cpp \
    hgaussfilter.cpp

HEADERS += \
        widget.h \
    ImageDisplay.h \
    camerathread.h \
    hbasetype.h \
    hthreshold.h \
    hscaleimage.h \
    herosion.h \
    hdilation.h \
    hopening.h \
    hclosing.h \
    buttoncontextmenu.h \
    hmeanimage.h \
    hgaussfilter.h

FORMS += \
        widget.ui \
    imagedisplay.ui \
    ImageDisplay.ui

INCLUDEPATH += "D:/MyEnvironment/halcon/include/"
INCLUDEPATH += "D:/MyEnvironment/halcon/include/halconcpp"
LIBPATH     += "D:\MyEnvironment\halcon\lib\x64-win64"
unix:LIBS   += -lhalconcpp -lhalcon -ldl -lpthread
win32:LIBS  += halconcpp.lib halcon.lib

RESOURCES += \
    iconimage.qrc

DISTFILES += \
    ../../../../../../iconImage/icon_maximize .png \
    ../../../../../../iconImage/icon_maximize .png


msvc{
    QMAKE_CFLAGS+=/utf-8
    QMAKE_CXXFLAGS+=/utf-8
}

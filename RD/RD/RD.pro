QT      += core gui widgets
QT      += opengl

LIBS += User32.lib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
#CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cdrawobject.cpp \
    cinputcontroller.cpp \
    cobject.cpp \
    collision.cpp \
    cplayer.cpp \
    gldisplaywidget.cpp \
    cube.cpp \
    labyrinthe.cpp \
    main.cpp \
    mainwindow.cpp \
    mazegenerator.cpp \
    mazehandler.cpp \
    room.cpp \
    transform.cpp \
    wall.cpp

HEADERS += \
    GLDisplayWidget.h \
    cdrawobject.h \
    cinputcontroller.h \
    cobject.h \
    collision.h \
    cplayer.h \
    mainwindow.h \
    mazegenerator.h \
    mazehandler.h \
    transform.h \
    cube.h \
    labyrinthe.h \
    mainwindow.h \
    room.h \
    wall.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:LIBS += -lOpengl32\
              -lglu32

unix:LIBS += -lglut -lGLU

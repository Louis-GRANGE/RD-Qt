QT      += core gui widgets
QT      += opengl

#LIBS += User32.lib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
#CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    camera.cpp \
    cdrawobject.cpp \
    cinputcontroller.cpp \
    cobject.cpp \
    collectable.cpp \
    collision.cpp \
    complexcollision.cpp \
    cplayer.cpp \
    gldisplaywidget.cpp \
    labyrinthe.cpp \
    linecollision.cpp \
    main.cpp \
    mainwindow.cpp \
    room.cpp \
    scenemanager.cpp \
    singleton.cpp \
    testcollision.cpp \
    transform.cpp \
    wall.cpp

HEADERS += \
    GLDisplayWidget.h \
    camera.h \
    cdrawobject.h \
    cinputcontroller.h \
    cobject.h \
    collectable.h \
    collision.h \
    complexcollision.h \
    cplayer.h \
    linecollision.h \
    mainwindow.h \
    scenemanager.h \
    singleton.h \
    testcollision.h \
    transform.h \
    labyrinthe.h \
    room.h \
    wall.h

FORMS += \
    mainwindow.ui


win32:LIBS += -lOpengl32\
              -lglu32

unix:LIBS += -lglut -lGLU

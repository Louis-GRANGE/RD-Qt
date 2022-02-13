QT      += core gui widgets
QT      += opengl

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
    labyrinthe.cpp \
    main.cpp \
    mainwindow.cpp \
    room.cpp \
    singleton.cpp \
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
    singleton.h \
    transform.h \
    labyrinthe.h \
    room.h \
    wall.h

FORMS += \
    mainwindow.ui


win32:LIBS += -lOpengl32\
              -lglu32

unix:LIBS += -lglut -lGLU

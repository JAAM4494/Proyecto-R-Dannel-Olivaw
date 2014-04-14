#-------------------------------------------------
#
# Project created by QtCreator 2014-04-08T22:36:46
#
#-------------------------------------------------

SOURCES += \
    individuo.cpp \
    poblacion.cpp \
    evolucion.cpp \
    reproduccion.cpp \
    mainGenetico.cpp \
    MainWindow.cpp \
    grayMain.cpp

HEADERS += \
    individuo.h \
    poblacion.h \
    evolucion.h \
    reproduccion.h

LIBS += \
    `pkg-config --libs --cflags opencv`

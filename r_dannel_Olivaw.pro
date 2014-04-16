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
    grayMain.cpp \
    ball.cpp \
    moveball.cpp

HEADERS += \
    individuo.h \
    poblacion.h \
    evolucion.h \
    reproduccion.h \
    ball.h \
    moveball.h

LIBS += \
    `pkg-config --libs --cflags opencv`

OTHER_FILES += \
    imagen_color.jpeg \
    ball2.png

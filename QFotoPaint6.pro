#-------------------------------------------------
#
# Project created by QtCreator 2024-09-01T12:00:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFotoPaint6

TEMPLATE = app

CONFIG += c++17

SOURCES += src/main.cpp \
    src/bajorrelieve.cpp \
    src/capturadevideo.cpp \
    src/ajustelineal.cpp \
    src/colorfalso.cpp \
    src/ecualizacionhistograma.cpp \
    src/informacionmultimedia.cpp \
    src/inpaint.cpp \
    src/mainwindow.cpp \
    src/imagenes.cpp \
    src/dialognueva.cpp \
    src/brillocontraste.cpp \
    src/matsatlum.cpp \
    src/morfologia.cpp \
    src/perfilado.cpp \
    src/perspectiva.cpp \
    src/pincharestirar.cpp \
    src/rojoverdeazul.cpp \
    src/starwars.cpp \
    src/suavizados.cpp \
    src/video.cpp \
    src/rotaravideo.cpp \
    src/mediaponderada.cpp \
    src/acercade.cpp \
    src/mediadevideo.cpp

HEADERS += include/mainwindow.h \
    include/bajorrelieve.h \
    include/capturadevideo.h \
    include/ajustelineal.h \
    include/colorfalso.h \
    include/ecualizacionhistograma.h \
    include/imagenes.h \
    include/dialognueva.h \
    include/brillocontraste.h \
    include/informacionmultimedia.h \
    include/inpaint.h \
    include/matsatlum.h \
    include/morfologia.h \
    include/perfilado.h \
    include/perspectiva.h \
    include/pincharestirar.h \
    include/rojoverdeazul.h \
    include/starwars.h \
    include/suavizados.h \
    include/video.h \
    include/rotaravideo.h \
    include/mediaponderada.h \
    include/acercade.h \
    include/mediadevideo.h

INCLUDEPATH += $$PWD/include

FORMS += ui/mainwindow.ui \
    ui/bajorrelieve.ui \
    ui/capturadevideo.ui \
    ui/ajustelineal.ui \
    ui/colorfalso.ui \
    ui/dialognueva.ui \
    ui/brillocontraste.ui \
    ui/ecualizacionhistograma.ui \
    ui/informacionmultimedia.ui \
    ui/inpaint.ui \
    ui/matsatlum.ui \
    ui/morfologia.ui \
    ui/perfilado.ui \
    ui/perspectiva.ui \
    ui/pincharestirar.ui \
    ui/rojoverdeazul.ui \
    ui/starwars.ui \
    ui/suavizados.ui \
    ui/rotaravideo.ui \
    ui/mediaponderada.ui \
    ui/acercade.ui \
    ui/mediadevideo.ui

INCLUDEPATH += "C:\OpenCV\OpenCV4.10.0G\include"

LIBS += -L"C:\OpenCV\OpenCV4.10.0G\lib"\
        -llibopencv_world4100

RESOURCES += recursos.qrc

RC_ICONS = imagenes/icono.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

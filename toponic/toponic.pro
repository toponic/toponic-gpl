TEMPLATE = app
CONFIG += debug_and_release
TARGET = toponic
VERSION = 0.0.1
QT += core \
    gui

# ----------------------------------------------------
INCLUDEPATH += inc \
    inc/ui \

# ----------------------------------------------------
HEADERS += \
    inc/mainwindow.h \
    inc/application.h \
    inc/project.h \
    inc/projectproperties.h \
    inc/projectpropertiesdialog.h \
    inc/coordinatesystems.h \
    inc/coordinatesystem.h \
    inc/toponic.h \
    inc/initellipsoids.h \
    inc/ellipsoids.h \
    inc/ellipsoid.h

# ----------------------------------------------------
SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/application.cpp \
    src/project.cpp \
    src/projectproperties.cpp \
    src/projectpropertiesdialog.cpp \
    src/coordinatesystems.cpp \
    src/coordinatesystem.cpp \
    src/ellipsoids.cpp \
    src/ellipsoid.cpp

# ----------------------------------------------------
TRANSLATIONS = \
    tr/toponic_ru.ts

# ----------------------------------------------------
UI_HEADERS_DIR = inc/ui
UI_SOURCES_DIR = src/ui
FORMS += \
    ui/mainwindow.ui \
    ui/centralwidget.ui \
    ui/projectpropertiesdialog.ui

# ----------------------------------------------------
RESOURCES += res/toponic.qrc
win32:RC_FILE = res/toponic.rc

# ----------------------------------------------------
CONFIG (debug, debug|release) {
    MOC_DIR = ../tmp/debug/toponic/moc
    OBJECTS_DIR = ../tmp/debug/toponic/obj
    RCC_DIR = ../tmp/debug/toponic/rcc
    DESTDIR = ../bin/debug
}
else {
    CONFIG += warn_off
    MOC_DIR = ../tmp/release/toponic/moc
    OBJECTS_DIR = ../tmp/release/toponic/obj
    RCC_DIR = ../tmp/release/toponic/rcc
    DESTDIR = ../bin/release
}










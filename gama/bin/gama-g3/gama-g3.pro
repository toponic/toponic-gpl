TEMPLATE = app

win32 {
    DEFINES += \
        GNU_gama_expat_1_1 \
        XML_NS
}

CONFIG -= qt
CONFIG += debug_and_release console

CONFIG (debug, debug|release) {
    OBJECTS_DIR = ../../../tmp/debug/gama/obj
    DESTDIR = ../../../bin/debug
    LIBS += -L../../../bin/debug -lgama
} else {
    CONFIG += warn_off
    OBJECTS_DIR = ../../../tmp/release/gama/obj
    DESTDIR = ../../../bin/release
    LIBS += -L../../../bin/release -lgama
}

INCLUDEPATH += \
    ../.. \
    ../../lib \
    ../../lib/expat/xmlparse \
    ../../lib/expat/xmltok \
    ../../lib/expat/xmlwf \
    ../../lib/gnu_gama \
    ../../lib/gnu_gama/adj \
    ../../lib/gnu_gama/g3 \
    ../../lib/gnu_gama/sparse \
    ../../lib/gnu_gama/local \
    ../../lib/gnu_gama/local/acord \
    ../../lib/gnu_gama/local/c/api \
    ../../lib/gnu_gama/local/median \
    ../../lib/gnu_gama/local/results/text \
    ../../lib/gnu_gama/xml \
    ../../lib/matvec

TARGET = gama-g3

SOURCES += ../gama-g3.cpp

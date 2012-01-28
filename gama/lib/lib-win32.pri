QMAKE_CXXFLAGS += -fpermissive

DEFINES += \
    GNU_gama_expat_1_1 \
    XML_NS

#-----------------------------------------------------------------
# По сути нам надо-то только чтобы в файле config.h находилась
# строка #define VERSION "1.11" (с правильным номером версии)
#-----------------------------------------------------------------

GAMA_CONFIG_H = $$PWD/../config.h
GAMA_CONFIG_H_WIN = $$replace(GAMA_CONFIG_H, /, \\)

exists ($$GAMA_CONFIG_H) {
    system (del $$GAMA_CONFIG_H_WIN)
}

!exists ($$GAMA_CONFIG_H) {
    VERSION_DEFINE_STRING = define VERSION \"1.11\" #Вот тут и надо менять номер версии
    VERSION_DEFINE_STRING = $$join(VERSION_DEFINE_STRING, " ",$$LITERAL_HASH)
    system (echo $$VERSION_DEFINE_STRING>$$GAMA_CONFIG_H_WIN)
}

!exists ($$GAMA_CONFIG_H) {
    error ("ERROR: Can not find config.h file! Exit qmake!")
} else {
    HEADERS += $$GAMA_CONFIG_H
}

QMAKE_CLEAN += $$GAMA_CONFIG_H_WIN

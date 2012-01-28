QMAKE_CXXFLAGS += -fpermissive

QMAKE_CLEAN += $$PWD/../config.h

!exists ($$PWD/../config.h) {
    !exists ($$PWD/../temp) {
        message ("Creating temp directory and configuring gama...")
        system  (mkdir $$PWD/../temp && cd $$PWD/../temp && $$PWD/../configure)
    }
    exists ($$PWD/../temp/config.h) {
        message ("Copy config.h from temp directory...")
        system  (cp $$PWD/../temp/config.h $$PWD/..)
        message ("Deleting temp directory...")
        system  (rm $$PWD/../temp -fr)
    }
}

!exists ($$PWD/../config.h) {
    error ("ERROR: Can not find config.h file! Exit qmake!")
} else {
    HEADERS += ../config.h
}

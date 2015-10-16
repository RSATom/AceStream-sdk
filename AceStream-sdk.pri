INCLUDEPATH += $$PWD/include

HEADERS += $$PWD/include/acestreamplayer/*.h

win32 {
    LIBS += $$PWD/lib/msvc/libtsplayer.lib
} else: !android {
    LIBS += -ltsplayer
}

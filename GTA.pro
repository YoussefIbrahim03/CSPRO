QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DirectedUnweightedGraph.cpp \
    bullet.cpp \
    dijkstra.cpp \
    enemy.cpp \
    enemydeath.cpp \
    health.cpp \
    heart.cpp \
    house.cpp \
    lose.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    powerpellet.cpp \
    score.cpp \
    win.cpp

HEADERS += \
    ../graph.h \
    DirectedUnweightedGraph.h \
    bullet.h \
    enemy.h \
    enemydeath.h \
    game.h \
    graph.h \
    health.h \
    heart.h \
    house.h \
    lose.h \
    mainwindow.h \
    player.h \
    pointers.h \
    powerpellet.h \
    score.h \
    win.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Board.txt \
    Tweety.png \
    bullet.png \
    gangsta.png \
    goldskull.png \
    heart.jpeg \
    house.gif\
    road.png \
    wall.png \
    youlose.jpeg \
    youwin.jpeg

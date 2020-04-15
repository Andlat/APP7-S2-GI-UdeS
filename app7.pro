TEMPLATE = vcapp
TARGET = APP7
CONFIG += warn_on qt debug_and_release windows
HEADERS += Window.h PayoutTable.h Question.h Option.h Timer.h Parametre.h
SOURCES += main.cpp Window.cpp PayoutTable.cpp Question.cpp Option.cpp Timer.cpp Parametre.cpp
QT += core gui widgets

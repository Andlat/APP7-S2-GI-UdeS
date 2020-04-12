TEMPLATE = vcapp
TARGET = APP7
CONFIG += warn_on qt debug_and_release windows console
HEADERS += Window.h PayoutTable.h Question.h Option.h Timer.h Menu.h
SOURCES += main.cpp Window.cpp PayoutTable.cpp Question.cpp Option.cpp Timer.cpp Menu.cpp
QT += core gui widgets

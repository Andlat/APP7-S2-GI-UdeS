TEMPLATE = vcapp
TARGET = APP7
CONFIG += warn_on qt debug_and_release windows console
HEADERS += Window.h PayoutTable.h Question.h Choice.h Timer.h
SOURCES += main.cpp Window.cpp PayoutTable.cpp Question.cpp Choice.cpp Timer.cpp
QT += core gui widgets

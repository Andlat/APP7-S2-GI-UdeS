#include "Timer.h"
#include <iostream>


Timer::Timer(QWidget* parent, unsigned t)
	:init_t(t), time_left(t), QLabel(QString::number(t)+" s", parent)
{
	this->setFont(QFont("Arial", 24));
	looper = new QTimer(parent);
	connect(looper, &QTimer::timeout, this, &Timer::update);
}

Timer::~Timer()
{
}

Timer * Timer::start()
{
	looper->start(1000);
	return this;
}

void Timer::stop()
{
	looper->setSingleShot(true);
}

void Timer::reset()
{
	time_left = init_t;
}

void Timer::add(int t)
{
	time_left += t;
}

inline void Timer::operator+=(int t)
{
	this->add(t);
}

unsigned Timer::left()
{
	return this->time_left;
}

void Timer::update()
{
	--time_left;
	this->setText(QString::number(time_left) + " s");
}

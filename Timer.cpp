#include "Timer.h"
#include <QMessageBox>


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

Timer* Timer::stop()
{
	this->looper->stop();
	
	return this;
}

Timer* Timer::reset()
{
	time_left = init_t+1;//+1s since the update removes 1s
	this->update();

	return this;
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

void Timer::isExpired()
{
	if (time_left == 0) {
		looper->stop();

		QMessageBox msg;
		msg.setText("Temps ecoule. Vous avez perdu...\n:'(");
		msg.exec();
	}
}

void Timer::update()
{
	--time_left;
	this->setText(QString::number(time_left) + " s");

	isExpired();
}

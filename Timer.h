#ifndef TIMER_H
#define TIMER_H

#include <QLabel>
#include <QTimer>

class Timer :
	public QLabel
{
	Q_OBJECT
public:
	Timer(QWidget* parent = nullptr, unsigned t = 30);
	~Timer();

	Timer* start();
	Timer* stop();

	Timer* reset();

	void add(int t);
	void operator+=(int t);
	unsigned left();

	unsigned init_t();
	void setInit_t(unsigned init_t);

private slots:
	void update();

private:
	void isExpired();

	QTimer* looper;
	unsigned time_left;
	unsigned _init_t;
};

#endif /* TIMER_H */
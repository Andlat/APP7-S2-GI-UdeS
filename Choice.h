#ifndef CHOICE_H
#define CHOICE_H

#include <QPushButton>

class Option :
	public QPushButton
{
	Q_OBJECT
public:
	Option();
	Option(QString q, QWidget* parent = nullptr);
	~Option();

	void set(QString c);
	QString get();

signals:
	void selected();

private:
	QString option;
};

#endif /* CHOICE_H */


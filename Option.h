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

	bool operator==(Option op);
	bool operator==(Option* op);

signals:
	void selected(Option*);

private:
	QString option;
};

#endif /* CHOICE_H */


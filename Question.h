#ifndef QUESTION_H
#define QUESTION_H

#include <QLabel>

#include "Choice.h"

class Question: public QLabel
{
public:
	Question();
	Question(QString q, QWidget* parent=nullptr);
	~Question();

	void set(QString q);
	QString get();

	void setOptions(Option* options[4]);
	void setOptions(Option* o1= nullptr, Option* o2 = nullptr, Option* o3 = nullptr, Option* o4 = nullptr);

	Option** Options();

private:
	QString question;

	Option* options[4] = { nullptr };
};

#endif /* QUESTION_H */
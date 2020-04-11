#ifndef QUESTION_H
#define QUESTION_H

#include <QLabel>

class Question: public QLabel
{
public:
	Question();
	Question(QString q, QWidget* parent=nullptr);
	~Question();

	void set(QString q);
	QString get();

private:
	QString question;
};

#endif /* QUESTION_H */
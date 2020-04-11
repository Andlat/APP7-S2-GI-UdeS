#include "Question.h"



Question::Question()
	:Question("")
{
}

Question::Question(QString q, QWidget* parent)
	: QLabel(q, parent)
{
	this->setStyleSheet("color: #5B3BFF; font-size: 30px;");
	this->setAlignment(Qt::AlignCenter);
}


Question::~Question()
{
}

void Question::set(QString q)
{
	this->setText(q);
	this->question = q;
}

QString Question::get()
{
	return this->question;
}

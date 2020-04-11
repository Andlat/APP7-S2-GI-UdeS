#include "Question.h"



Question::Question()
	:Question("")
{
}

Question::Question(QString q, QWidget* parent)
	: QLabel(q, parent)
{
	this->setStyleSheet("color: #5B3BFF; font-size: 30px; font-weight: bold;");
	this->setAlignment(Qt::AlignCenter);
	this->setWordWrap(true);
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

void Question::setOptions(Option * options[4])
{
	for (unsigned short i = 0; i < 4; ++i)
		this->options[i] = options[i];
}

void Question::setOptions(Option * o1, Option * o2, Option * o3, Option * o4)
{
	this->options[0] = o1;
	this->options[1] = o2;
	this->options[2] = o3;
	this->options[3] = o4;
}

Option ** Question::Options()
{
	return this->options;
}

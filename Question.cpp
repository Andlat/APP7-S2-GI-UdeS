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
	bool haveToDeleteAnswer = true;

	for (unsigned short i = 0; i < 4; ++i) {

		if (options[i] != nullptr) {
			if (answer == options[i])//Check if the pointer provided to the answer is the same as one of the answers. To prevent a double deletion.
				haveToDeleteAnswer = false;

			delete options[i];
			options[i] = nullptr;
		}
	}
	
	if (haveToDeleteAnswer && answer != nullptr)
		delete answer;
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
	deleteCurrentOptions();

	for (unsigned short i = 0; i < 4; ++i)
		this->options[i] = options[i];
}

void Question::setOptions(Option * o1, Option * o2, Option * o3, Option * o4)
{

	deleteCurrentOptions();

	this->options[0] = o1;
	this->options[1] = o2;
	this->options[2] = o3;
	this->options[3] = o4;
}

void Question::setAnswer(Option * answer)
{
	if (this->answer != nullptr)
		delete this->answer;

	this->answer = answer;
}

Option ** Question::Options()
{
	return this->options;
}

Option * Question::Answer()
{
	return this->answer;
}

bool Question::Verify(Option * op)
{
	return op == this->answer;
}

void Question::ConnectOptions(const std::function<void(Option*)>& slot_functor)
{
	for (unsigned short i = 0; i < 4; ++i)
		connect(this->options[i], &Option::selected, slot_functor);
}

void Question::deleteCurrentOptions()
{
	for (unsigned i = 0; i < 4; ++i) {
		if (options[i] != nullptr)
			delete options[i];
	}
}

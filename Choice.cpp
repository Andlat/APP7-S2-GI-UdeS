#include "Choice.h"



Option::Option()
	: Option("")
{

}

Option::Option(QString q, QWidget* parent)
	: QPushButton(q, parent)
{
	this->setStyleSheet("color: #5B3BFF; font-size: 30px; border-radius:5px; text-align: left;");
	this->setCursor(Qt::PointingHandCursor);

	//Emettre le signal selected quand le choix est clique/selectionne
	connect(this, &QPushButton::clicked, this, [this](){emit selected();});
}


Option::~Option()
{
}

void Option::set(QString c)
{
	this->option = c;
}

QString Option::get()
{
	return this->option;
}

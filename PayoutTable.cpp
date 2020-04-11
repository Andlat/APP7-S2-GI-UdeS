#include "PayoutTable.h"
#include <iostream>
#include <QLabel>

PayoutTable::PayoutTable() {

	layout = new QVBoxLayout;

	for (short i = sizeof(this->amounts)/sizeof(int) - 1; i >= 0; --i) {
		
		auto label = new QLabel(QString::number(amounts[i]) + " $", this);
		label->setAlignment(Qt::AlignRight);

		layout->addWidget(label);

		amountLabels[i] = label;
	}

	amountLabels[0]->setStyleSheet("background: yellow;");//Highlight the first amount
	this->setLayout(layout);
}

int PayoutTable::next()
{
	if (currentAmount != &amounts[sizeof(amounts) / sizeof(int) - 1]) {//If not at the last amount, go to the next one
		++currentAmount;


		//Highlight the new amount
		short nextLabelIndex = &currentAmount[0] - &amounts[0];
		amountLabels[nextLabelIndex-1]->setStyleSheet("background: white;");
		amountLabels[nextLabelIndex]->setStyleSheet("background: yellow;");
	}

	return this->get();
}

int PayoutTable::get()
{
	return *currentAmount;
}

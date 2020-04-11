#include "PayoutTable.h"

#include <QLabel>

PayoutTable::PayoutTable() {

	layout = new QVBoxLayout;

	for (unsigned short i = 0; i < sizeof(this->amounts) / sizeof(int); ++i) {
		auto label = new QLabel(QString::number(amounts[i]), this);
		layout->addWidget(label);
	}

	this->setLayout(layout);
}
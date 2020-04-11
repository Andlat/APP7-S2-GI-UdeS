#include "Window.h"
#include "PayoutTable.h"

#include <QGridLayout>
#include <QPushButton>


Window::Window(){
	auto mainLayout = new QGridLayout; /* TODO Choisir le layout approprié. */
	auto centralWidget = new QWidget;

	centralWidget->setLayout(mainLayout);


	auto payoutTable = new PayoutTable;
	mainLayout->addWidget(payoutTable);

	setCentralWidget(centralWidget);
	setMinimumSize(500, 500);

	//Bouton temporaire pour changer le montant surligné
	auto nextBtn = new QPushButton("Next", this);
	connect(nextBtn, &QPushButton::clicked, payoutTable, &PayoutTable::next);
	mainLayout->addWidget(nextBtn);
}

Window::~Window(){
}

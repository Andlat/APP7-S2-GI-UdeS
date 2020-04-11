#include "Window.h"
#include "PayoutTable.h"
#include "Question.h"

#include <QGridLayout>
#include <QPushButton>


Window::Window(){
	auto mainLayout = new QGridLayout;
	auto centralWidget = new QWidget;
	this->setStyleSheet("border:1px solid black"); /* TODO ceci est temporaire pour mieux voir le layout */

	centralWidget->setLayout(mainLayout);

	setCentralWidget(centralWidget);
	setMinimumSize(900, 600);


	//Titre
	auto title = new QLabel("Qui veut gagner des millions ?", this);
	title->setAlignment(Qt::AlignCenter);
	title->setStyleSheet("color: #4431C4; font-size: 50px");

	mainLayout->addWidget(title, 0,0, 1,0);

	//Question
	auto question = new Question("Quel programme universitaire est le meilleur ?", this);
	mainLayout->addWidget(question, 1, 1);

	//Table des montants
	auto payoutTable = new PayoutTable;
	mainLayout->addWidget(payoutTable,1,2);

	//Bouton temporaire pour changer le montant surligné
	auto nextBtn = new QPushButton("Next", this);
	connect(nextBtn, &QPushButton::clicked, payoutTable, &PayoutTable::next);
	mainLayout->addWidget(nextBtn,2,2);
}

Window::~Window(){
}

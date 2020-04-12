#include "Window.h"
#include "PayoutTable.h"
#include "Question.h"
#include "Choice.h"

#include <QGridLayout>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>



Window::Window(){
	auto mainLayout = new QGridLayout;
	auto centralWidget = new QWidget;
	//this->setStyleSheet("border:1px solid black"); /* TODO ceci est temporaire pour mieux voir le layout */

	centralWidget->setLayout(mainLayout);

	setCentralWidget(centralWidget);
	setMinimumSize(900, 600);


	//Titre
	auto title = new QLabel("Qui veut gagner des millions ?", this);
	title->setAlignment(Qt::AlignCenter);
	title->setStyleSheet("color: #4431C4; font-size: 50px; font-weight: bold;");

	mainLayout->addWidget(title, 0,0, 1,0);

	//Question
	auto question = new Question("Quel programme universitaire est le meilleur ?", this);
	mainLayout->addWidget(question, 1, 1);

	question->setOptions(
		new Option("A) Genie informatique", this),
		new Option("O) Genie robotique", this),
		new Option("U) Genie electrique", this),
		new Option("E) Administration", this)
		);

	//Layout des choix de reponse
	auto choicesContainer = new QWidget;
	auto choicesLayout = new QGridLayout;
	choicesContainer->setLayout(choicesLayout);
	mainLayout->addWidget(choicesContainer, 2,1);
	
	choicesLayout->setSpacing(30);

	choicesLayout->addWidget(question->Options()[0], 0,0);
	choicesLayout->addWidget(question->Options()[1], 1, 0);
	choicesLayout->addWidget(question->Options()[2], 0, 1);
	choicesLayout->addWidget(question->Options()[3], 1, 1);

	//Table des montants
	auto payoutTable = new PayoutTable;
	mainLayout->addWidget(payoutTable,1,2,2,1);


	//Bouton temporaire pour changer le montant surligné
	auto nextBtn = new QPushButton("Next", this);
	connect(nextBtn, &QPushButton::clicked, payoutTable, &PayoutTable::next);
	mainLayout->addWidget(nextBtn,3,2);

	//bouton pour choisir de partir
	auto stopGame = new QPushButton("parir", this);
	connect(stopGame, &QPushButton::clicked, this, &Window::quit);
	mainLayout->addWidget(stopGame, 3, 1);
	
	// gestion du menu des actions du menu
	auto save_ac = new QAction("sauvegarde");
	connect(save_ac, &QAction::triggered, this, &Window::save);
	auto help_ac = new QAction("aide");
	connect(help_ac, &QAction::triggered, this, &Window::help);

	//section du menu
	auto menu = new QMenu;
	menu = menuBar()->addMenu("Fichier");
	menu->addAction(save_ac);
	menu = menuBar()->addMenu("Edition");
	menu->addAction(help_ac);

}

Window::~Window(){
}

void Window::quit()
{
	messageBox("quitter la partie");
}

void Window::save()
{
	messageBox("Sauvegarde du score");
}

void Window::help()
{
	messageBox("Explication du jeu");
}

void Window::messageBox(QString s)
{
	message.setText(s);
	message.exec();
}

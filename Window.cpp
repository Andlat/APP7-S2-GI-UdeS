#include "Window.h"
#include "Question.h"
#include "Option.h"
#include "Timer.h"

#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QFile>
#include <QTextStream>
#include <QIcon>
#include <QImage>


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

	auto correctOption = new Option("A) Genie informatique", this);

	question->setOptions(
		correctOption,
		new Option("O) Genie robotique", this),
		new Option("U) Genie electrique", this),
		new Option("E) Administration", this)
		);

	question->setAnswer(correctOption);
	question->ConnectOptions([question](Option* selected) {
		
		QMessageBox msg;

		if (question->Verify(selected))
			msg.setText("Bonne reponse !!!");
		else
			msg.setText("Mauvaise reponse...");

		msg.exec();
	});

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

	//Timer
	auto timer = new Timer(this,30);
	mainLayout->addWidget(timer->start(), 3, 0,1,1,Qt::AlignCenter);

	//Table des montants
	payoutTable = new PayoutTable;
	mainLayout->addWidget(payoutTable,1,2,2,1);

	//Bouton temporaire pour changer le montant surlign�
	auto nextBtn = new QPushButton("Continuer", this);
	connect(nextBtn, &QPushButton::clicked, payoutTable, &PayoutTable::next);
	mainLayout->addWidget(nextBtn,3,2);


	//bouton pour quitter la partie
	auto stopGame = new QPushButton("Quitter", this);
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

	//Lignes de vie
	/* image pour le 50/50 , telephone, public, image de background */
	//50/50
	auto lifelinesLayout = new QVBoxLayout;
	auto lifelinesWidget = new QWidget;
	lifelinesWidget->setLayout(lifelinesLayout);
	mainLayout->addWidget(lifelinesWidget, 1,0);

	
	auto cinquante = new QPushButton(this);
	connect(cinquante, &QPushButton::clicked, this, &Window::cinquante);
	cinquante->setIcon(QIcon("cinquante"));
	cinquante->setIconSize(QSize(50, 50));
	lifelinesLayout->addWidget(cinquante);

	//telephone
	auto telephone = new QPushButton(this);
	connect(telephone, &QPushButton::clicked, this, &Window::telephone);
	telephone->setIcon(QIcon("telephone"));
	telephone->setIconSize(QSize(50, 50));
	//mainLayout->addWidget(telephone, 1, 0, Qt::AlignLeft);
	lifelinesLayout->addWidget(telephone);

	//public
	auto publics = new QPushButton(this);
	connect(publics, &QPushButton::clicked, this, &Window::publics);
	publics->setIcon(QIcon("public"));
	publics->setIconSize(QSize(50, 50));
	//mainLayout->addWidget(publics, 0, 0, Qt::AlignLeft);
	lifelinesLayout->addWidget(publics);
}

Window::~Window(){
}

void Window::quit()
{
	messageBox("quitter la partie");
	save();
	this->close();
}

void Window::save()
{
	messageBox("votre score a ete sauvegarder dans score.txt");
	QFile file("score.txt");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;
	QTextStream out(&file);
	out << "votre score est de : " << this->payoutTable->get() << '$' << endl;
}

void Window::help()
{
	QString text;
	text = ("Ce jeu consiste a remporter de l'argent a chaque fois que vous trouvez la bonne reponse aux questions. Pour vous aidez,"
		"vous disposez de 4 outils soit : le 50/50; le telephone; l'avie du public et le joker. Leur fonctionnement sont expliques ci-dessous"
		"Le 50/50 permet d'eliminer 2 reponses sur les 4. La reponse de la question se trouve dans l'une de ces 2 reponses"
		"Le telephone vous donne la possibilit� d'appeler un ami qui pourra vous aider a repondre � la question"
		"L'aide du public vous permet de consulter le public et d'avoir leur opinion sur reponse"
		"Le joker vous donne directement la bonne reponse "
		"Bonne chance :) ");
	messageBox(text);
}

void Window::cinquante()
{
	messageBox("50/50 selectionner");
}

void Window::telephone()
{
	messageBox("coup de telephone");
}

void Window::publics()
{
	messageBox("adie du public");
}

void Window::messageBox(QString s)
{
	message.setText(s);
	message.exec();
}

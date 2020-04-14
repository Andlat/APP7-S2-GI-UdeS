#include "Window.h"

Window::Window(){
	_param = Param();

	auto mainLayout = new QGridLayout;
	auto centralWidget = new QWidget(this);

	centralWidget->setLayout(mainLayout);

	setCentralWidget(centralWidget);
	setMinimumSize(900, 600);
	setWindowTitle("Qui veut gagner des millions ?");
	setWindowIcon(QIcon("logo"));

	this->message = new QMessageBox(this);

	//Titre
	auto title = new QLabel("Qui veut gagner des millions ?", this);
	title->setAlignment(Qt::AlignCenter);
	title->setStyleSheet("color: #4431C4; font-size: 50px; font-weight: bold;");

	mainLayout->addWidget(title, 0,0, 1,0);
	

	//Timer
	timer = new Timer(this, 30);
	mainLayout->addWidget(timer->start(), 3, 0, 1, 1, Qt::AlignCenter);


	//Question
	question = new Question("Quel programme universitaire est le meilleur ?", this);
	mainLayout->addWidget(question, 1, 1);

	auto correctOption = new Option("A) Genie informatique", this);

	question->setOptions(
		correctOption,
		new Option("O) Genie robotique", this),
		new Option("U) Genie electrique", this),
		new Option("E) Administration", this)
		);

	question->setAnswer(correctOption);
	question->ConnectOptions([this](Option* selected) {
		
		this->timer->stop();

		this->hasTrigerredCorrectAnswer = question->Verify(selected);
		this->messageBox(hasTrigerredCorrectAnswer ? "Bonne reponse !!!\nVeuillez continuer." : "Mauvaise reponse..\nVous avez perdu.\nVotre montant final est " + QString::number(this->payoutTable->get()) + '$');
	});

	//Layout des choix de reponse
	choicesContainer = new QWidget;
	auto choicesLayout = new QGridLayout;
	choicesContainer->setLayout(choicesLayout);
	mainLayout->addWidget(choicesContainer, 2,1);
	
	choicesLayout->setSpacing(30);

	choicesLayout->addWidget(question->Options()[0], 0,0);
	choicesLayout->addWidget(question->Options()[1], 1, 0);
	choicesLayout->addWidget(question->Options()[2], 0, 1);
	choicesLayout->addWidget(question->Options()[3], 1, 1);

	//Table des montants
	payoutTable = new PayoutTable;
	mainLayout->addWidget(payoutTable,1,2,2,1);

	//Bouton pour passer a la prochaine question/prochain montant
	auto nextBtn = new QPushButton("Continuer", this);
	nextBtn->setCursor(Qt::PointingHandCursor);
	connect(nextBtn, &QPushButton::clicked, [this]() {
		if (this->hasTrigerredCorrectAnswer) {//Passer � la prochaine question si la bonne reponse a ete selectionne
			this->timer->reset()->start();
			this->payoutTable->next();
			
			this->hasTrigerredCorrectAnswer = false;
		}
		else {
			this->messageBox("Veuillez selectionner une bonne reponse pour continuer au prochain montant.");
		}
	});
	mainLayout->addWidget(nextBtn,3,2);


	//bouton pour quitter la partie
	auto stopGame = new QPushButton("Quitter", this);
	stopGame->setCursor(Qt::PointingHandCursor);
	connect(stopGame, &QPushButton::clicked, this, &Window::quit);
	mainLayout->addWidget(stopGame, 3, 1);
	
	// gestion du menu des actions du menu
	auto save_ac = new QAction("Sauvegarder");
	connect(save_ac, &QAction::triggered, this, &Window::save);
	auto help_ac = new QAction("Aide");
	connect(help_ac, &QAction::triggered, this, &Window::help);
	auto param_ac = new QAction("Parametres");
	connect(param_ac, &QAction::triggered, this, &Window::parametre);

	//section du menu
	auto menu = new QMenu;
	menu = menuBar()->addMenu("Fichier");
	menu->addAction(save_ac);
	menu = menuBar()->addMenu("Edition");
	menu->addAction(help_ac);
	menu->addAction(param_ac);

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
	cinquante->setCursor(Qt::PointingHandCursor);
	lifelinesLayout->addWidget(cinquante);

	//telephone
	auto telephone = new QPushButton(this);
	connect(telephone, &QPushButton::clicked, this, &Window::telephone);
	telephone->setIcon(QIcon("telephone"));
	telephone->setIconSize(QSize(50, 50));
	telephone->setCursor(Qt::PointingHandCursor);
	lifelinesLayout->addWidget(telephone);

	//public
	auto publics = new QPushButton(this);
	connect(publics, &QPushButton::clicked, this, &Window::publics);
	publics->setIcon(QIcon("public"));
	publics->setIconSize(QSize(50, 50));
	publics->setCursor(Qt::PointingHandCursor);
	lifelinesLayout->addWidget(publics);
}

Window::~Window(){
}

void Window::quit()
{
	messageBox("Quitter la partie");
	if (_param.autoSave)
	{
		save();
	}
	
	this->close();
}

void Window::save()
{
	messageBox("Votre score a ete sauvegarder dans score.txt");
	QFile file(_param.filename);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;
	QTextStream out(&file);
	out << "Votre score est de : " << this->payoutTable->get() << '$' << endl;
}

void Window::help()
{
	QString text;
	text = ("Ce jeu consiste a remporter de l'argent a chaque fois que vous trouvez la bonne reponse aux questions. Pour vous aidez,"
		"vous disposez de 4 outils soit : le 50/50; le telephone; l'avis du public et le joker. Leur fonctionnement sont expliques ci-dessous"
		"Le 50/50 permet d'eliminer 2 reponses sur les 4. La reponse de la question se trouve dans l'une de ces 2 reponses"
		"Le telephone vous donne la possibilite d'appeler un ami qui pourra vous aider a repondre a la question"
		"L'aide du public vous permet de consulter le public et d'avoir leur opinion sur reponse"
		"Le joker vous donne directement la bonne reponse "
		"Bonne chance :) ");
	messageBox(text, "Aide");
}

void Window::cinquante()
{
	messageBox("50/50 selectionne");
}

void Window::telephone()
{
	messageBox("Coup de telephone");
}

void Window::publics()
{
	messageBox("Aide du public");
}

void Window::messageBox(QString s, QString winTitle)
{
	message->setText(s);
	message->setWindowTitle(winTitle);
	message->exec();
}

void Window::parametre()
{
	timer->stop();
	//question->hide();
	choicesContainer->hide();

	Parametre parametre(_param);
	connect(&parametre, SIGNAL(paramChanged(Param)), this, SLOT(updateParam(Param)));
	parametre.exec();

	choicesContainer->show();
	//question->show();
	timer->start();
}

void Window::updateParam(Param param)
{
	_param = param;
	if (_param.timeQuestion != timer->init_t())
	{
		timer->setInit_t(_param.timeQuestion);
	}
}
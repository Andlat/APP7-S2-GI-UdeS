#include "Parametre.h"

Parametre::Parametre()
{
	Param param;
	buildDialog(param);
}

Parametre::Parametre(Param param)
{
	buildDialog(param);
}

void Parametre::buildDialog(Param param)
{
	_param = param;
	auto mainLayout = new QVBoxLayout(this);

	_mainWidget = new QWidget(this);
	_form = new QFormLayout(_mainWidget);

	_mainWidget->setLayout(_form);

	mainLayout->addWidget(_mainWidget);
	resize(800, 600);
	setWindowTitle("Parametres");
	setWindowIcon(QIcon("logo"));

	_difficulty = new QComboBox(_mainWidget);

	_difficulty->addItem("Facile", 0);
	_difficulty->addItem("Moyen", 1);
	_difficulty->addItem("Difficile", 2);
	_difficulty->addItem("Extreme", 3);
	_difficulty->setCurrentIndex(_param.difficulty);

	_form->addRow("Difficulte", _difficulty);

	_timeQuestion = new QSpinBox(_mainWidget);
	_timeQuestion->setValue(_param.timeQuestion);
	_timeQuestion->setMinimum(10);
	_timeQuestion->setMaximum(60);

	_form->addRow("Temps pour repondre aux questions", _timeQuestion);


	_autoSave = new QCheckBox(_mainWidget);
	_autoSave->setChecked(_param.autoSave);

	_form->addRow("Sauvegarde automatique", _autoSave);



	auto line = new QWidget(_mainWidget);
	auto lineLayout = new QHBoxLayout(line);

	line->setLayout(lineLayout);

	_filename = new QLineEdit(_mainWidget);
	_filename->setText(_param.filename);
	_browseButton = new QPushButton(line);
	_browseButton->setText("Naviguer");

	connect(_browseButton, SIGNAL(clicked()), this, SLOT(browse()));

	lineLayout->addWidget(_filename);
	lineLayout->addWidget(_browseButton);

	_form->addRow("Fichier de sauvegarde", line);

	auto footerWidget = new QWidget(this);
	auto footerLayout = new QHBoxLayout(footerWidget);

	_okButton = new QPushButton("Ok", footerWidget);
	_okButton->setMaximumWidth(150);
	_cancelButton = new QPushButton("Cancel", footerWidget);
	_cancelButton->setMaximumWidth(150);
	_applyButton = new QPushButton("Appliquer", footerWidget);
	_applyButton->setMaximumWidth(150);

	footerLayout->addWidget(_okButton);
	footerLayout->addWidget(_cancelButton);
	footerLayout->addWidget(_applyButton);
	footerLayout->setAlignment(Qt::AlignBottom | Qt::AlignRight);

	connect(_okButton, SIGNAL(clicked()), this, SLOT(ok()));
	connect(_cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(_applyButton, SIGNAL(clicked()), this, SLOT(apply()));


	mainLayout->addWidget(footerWidget);

}



void Parametre::apply()
{
	//QString message = "Difficulte choisie : " + _difficulty->currentData().toString() + "\n";
	//message += "Temps de reponse : " + QString::number(_timeQuestion->value()) + "\n";
	//message += "Sauvegarde automatique : " + (QString) (_autoSave->checkState() == Qt::Checked ? "Oui" : "Non") + "\n";
	//message += "Fichier de sauvegarde : " + _filename->text() + "\n";
	//QMessageBox::information(this, "Parametres choisis", message, QMessageBox::Ok, QMessageBox::Ok);

	_param.autoSave = _autoSave->checkState();
	_param.difficulty = _difficulty->currentIndex();
	_param.filename = _filename->text();
	_param.timeQuestion = _timeQuestion->value();


	emit paramChanged(_param);
}

void Parametre::ok()
{
	apply();
	close();
}

void Parametre::browse()
{
	_filename->setText(QFileDialog::getSaveFileName(this, "Fichier de score", "score.txt", "*.txt"));
}

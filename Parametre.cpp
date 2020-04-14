#include "Parametre.h"

Parametre::Parametre()
{
	auto mainLayout = new QVBoxLayout(this);

	mainWidget = new QWidget(this);
	auto form = new QFormLayout(mainWidget);

	mainWidget->setLayout(form);

	mainLayout->addWidget(mainWidget);
	resize(800, 600);
	setWindowTitle("Parametres");

	difficulte = new QComboBox(mainWidget);

	difficulte->addItem("Facile", 0);
	difficulte->addItem("Moyen", 1);
	difficulte->addItem("Difficile", 2);
	difficulte->addItem("Extreme", 3);

	form->addRow("Difficulte", difficulte);

	timeQuestion = new QSpinBox(mainWidget);
	timeQuestion->setValue(30);
	timeQuestion->setMinimum(10);
	timeQuestion->setMaximum(60);

	form->addRow("Temps pour repondre aux questions", timeQuestion);


	autoSave = new QCheckBox(mainWidget);

	form->addRow("Sauvegarde automatique", autoSave);



	auto line = new QWidget(mainWidget);
	auto lineLayout = new QHBoxLayout(line);

	line->setLayout(lineLayout);

	filename = new QLineEdit(mainWidget);
	filename->setText(QDir::currentPath() + "/score.txt");
	browseButton = new QPushButton(line);
	browseButton->setText("Naviguer");

	connect(browseButton, SIGNAL(clicked()), this, SLOT(browse()));

	lineLayout->addWidget(filename);
	lineLayout->addWidget(browseButton);

	form->addRow("Fichier de sauvegarde", line);

	auto footerWidget = new QWidget(this);
	auto footerLayout = new QHBoxLayout(footerWidget);

	okButton = new QPushButton("Ok", footerWidget);
	okButton->setMaximumWidth(150);
	cancelButton = new QPushButton("Cancel", footerWidget);
	cancelButton->setMaximumWidth(150);
	applyButton = new QPushButton("Appliquer", footerWidget);
	applyButton->setMaximumWidth(150);

	footerLayout->addWidget(okButton);
	footerLayout->addWidget(cancelButton);
	footerLayout->addWidget(applyButton);
	footerLayout->setAlignment(Qt::AlignBottom | Qt::AlignRight);

	connect(okButton, SIGNAL(clicked()), this, SLOT(ok()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(applyButton, SIGNAL(clicked()), this, SLOT(apply()));


	mainLayout->addWidget(footerWidget);

}

void Parametre::apply()
{
	QString message = "Difficulte choisie : " + difficulte->currentData().toString() + "\n";
	message += "Temps de reponse : " + QString::number(timeQuestion->value()) + "\n";
	message += "Sauvegarde automatique : " + (QString) (autoSave->checkState() == Qt::Checked ? "Oui" : "Non") + "\n";
	message += "Fichier de sauvegarde : " + filename->text() + "\n";

	QMessageBox::information(this, "Parametres choisis",  message, QMessageBox::Ok, QMessageBox::Ok);
}

void Parametre::ok()
{
	apply();
	close();
}

void Parametre::browse()
{
	filename->setText(QFileDialog::getSaveFileName(this, "Fichier de score", "score.txt", "*.txt"));
}
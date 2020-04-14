#ifndef PARAMETRE_H
#define PARAMETRE_H

#include <QMainWindow>
#include <QFormLayout.h>
#include <QLabel.h>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog.h>
#include <QSpinBox>
#include <QDir>
#include <QMessageBox>
#include <QString>
#include <QDialog>

class Parametre : public QDialog {
	Q_OBJECT

public:
	Parametre();
private slots:
	void apply();
	void ok();
	void browse();
private:
	QComboBox* difficulte;
	QWidget* mainWidget;
	QCheckBox* autoSave;
	QFormLayout* form;
	QLineEdit* filename;
	QSpinBox* timeQuestion;
	QPushButton* browseButton;
	QPushButton* applyButton;
	QPushButton* okButton;
	QPushButton* cancelButton;
};

#endif

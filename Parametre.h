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
#include <QMessageBox>
#include <QString>
#include <QDialog>
#include <QDir>

struct Param {
	int difficulty;
	int timeQuestion;
	QString filename;
	bool autoSave;
	Param() :
		difficulty(0),
		timeQuestion(30),
		filename(QDir::currentPath() + "/score.txt"),
		autoSave(false) {};
	Param(int _difficulty, int _timeQuestion, QString _filename, bool _autoSave) :
		difficulty(_difficulty),
		timeQuestion(_timeQuestion),
		filename(_filename),
		autoSave(_autoSave)	{};
};

class Parametre : public QDialog {
	Q_OBJECT

public:
	Parametre();
	Parametre(Param param);
signals:
	void paramChanged(Param param);
private slots:
	void apply();
	void ok();
	void browse();
private:
	void buildDialog(Param param);
	QComboBox* _difficulty;
	QWidget* _mainWidget;
	QCheckBox* _autoSave;
	QFormLayout* _form;
	QLineEdit* _filename;
	QSpinBox* _timeQuestion;
	QPushButton* _browseButton;
	QPushButton* _applyButton;
	QPushButton* _okButton;
	QPushButton* _cancelButton;
	Param _param;
};

#endif

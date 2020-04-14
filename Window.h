#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QFile>
#include <QTextStream>
#include <QIcon>
#include <QDir>

#include "PayoutTable.h"
#include "Timer.h"
#include "Parametre.h"
#include "Question.h"
#include "Option.h"

class Window: public QMainWindow
{
	Q_OBJECT

public:
	Window();
	~Window();

/*
protected:
#ifndef QT_NO_CONTEXTMENU
	void contextMenuEvent(QContextMenuEvent *event) override;
#endif /* QT_NO_CONTEXTMENU */

private slots:
	void quit();
	void save();
	void help();
	void cinquante();
	void telephone();
	void publics();
	void parametre();
	void updateParam(Param param);

private:
	void messageBox(QString s, QString winTitle = "Qui veut gagner des millions ?");
	QMessageBox* message;

	QWidget* choicesContainer;
	Question* question;

	PayoutTable* payoutTable;
	Timer* timer;

	bool hasTrigerredCorrectAnswer = false;
	Param _param;
};


#endif /* WINDOW_H */

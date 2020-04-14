#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "PayoutTable.h"
#include "Timer.h"

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

private:
	void messageBox(QString s);
	QMessageBox message;

	PayoutTable* payoutTable;
	Timer* timer;

	bool hasTrigerredCorrectAnswer = false;
};


#endif /* WINDOW_H */

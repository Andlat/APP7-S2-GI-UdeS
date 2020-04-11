#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

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

};


#endif /* WINDOW_H */

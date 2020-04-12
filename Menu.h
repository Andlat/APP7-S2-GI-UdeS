#ifndef MENU_H
#define MENU_H
#include <QMenu>

class Menu : public QMenu
{
	Q_OBJECT

public:
	Menu();
	~Menu();

private slots:
		void save();
		void help();

};

#endif /* MENU_H */


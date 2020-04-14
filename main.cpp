#include <QApplication>
#include "Window.h"
#include "Parametre.h"

int main(int argc, char* argv[]){
	QApplication app(argc, argv);

	Window win;
	win.show();

	return app.exec();
}

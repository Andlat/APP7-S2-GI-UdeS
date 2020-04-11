#include "Window.h"
#include "PayoutTable.h"

#include <QGridLayout>


Window::Window(){
	auto mainLayout = new QGridLayout; /* TODO Choisir le layout approprié. */
	auto centralWidget = new QWidget;

	centralWidget->setLayout(mainLayout);
	mainLayout->addWidget(new PayoutTable);

	setCentralWidget(centralWidget);
	setMinimumSize(500, 500);
}

Window::~Window(){
}

#ifndef PAYOUTTABLE_H
#define PAYOUTTABLE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class PayoutTable: public QWidget{
	Q_OBJECT
public:
	PayoutTable();
	int get();

public slots:
	int next();
	
private:
	int amounts[15] = { 500, 1000, 2000, 3000, 5000, 7000, 10000, 12500, 15000, 25000, 50000, 100000, 250000, 500000, 1000000 };
	int* currentAmount = &amounts[0];
	QLabel* amountLabels[15];

	QVBoxLayout* layout;
};

#endif /* PAYOUTTABLE_H */
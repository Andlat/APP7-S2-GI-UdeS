#ifndef PAYOUTTABLE_H
#define PAYOUTTABLE_H

#include <QWidget>
#include <QVBoxLayout>

class PayoutTable: public QWidget{
public:
	PayoutTable();
private:
	int amounts[15] = { 500, 1000, 2000, 3000, 5000, 7000, 10000, 12500, 15000, 25000, 50000, 100000, 250000, 500000, 1000000 };

	QVBoxLayout* layout;

};

#endif /* PAYOUTTABLE_H */
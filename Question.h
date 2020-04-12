#ifndef QUESTION_H
#define QUESTION_H

#include <QLabel>
#include <functional>

#include "Option.h"

/*
 * Classe qui contient la question, les reponses et peux valider la bonne reponse.
 * Chaque pointeur d'option donnee a cette classe sera supprime une fois que la question n'en a plus besoin.
 */
class Question: public QLabel
{
public:
	Question();
	Question(QString q, QWidget* parent=nullptr);
	~Question();

	void set(QString q);
	QString get();

	void setOptions(Option* options[4]);
	void setOptions(Option* o1= nullptr, Option* o2 = nullptr, Option* o3 = nullptr, Option* o4 = nullptr);
	void setAnswer(Option* answer);

	Option** Options();
	Option* Answer();

	bool Verify(Option* op);

	void ConnectOptions(const std::function<void(Option*)>& slot_functor);

private:
	void deleteCurrentOptions();

	QString question;

	Option* options[4] = { nullptr };
	Option* answer = nullptr;
};

#endif /* QUESTION_H */
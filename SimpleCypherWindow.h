#ifndef SIMPLE_CYPHER_WINDOW_H
#define SIMPLE_CYPHER_WINDOW_H

#include <QDialog>
#include <QTextEdit>

#include "Cypher.h"

class SimpleCypherWindow : public QDialog{
	//Macro para poder declarar slots y señales propios.
	Q_OBJECT
	
	public:
		SimpleCypherWindow();
				
	private:
		QTextEdit* messageEdit;
		QTextEdit* cypherEdit;
		QPushButton* cypherButton;
		Cypher* cypherObject;
		
	public slots:
		void getMessageText();
		
	signals:
		void sendText( const QString& );
};

#endif //SIMPLE_CYPHER_WINDOW_H

#ifndef CYPHER_H
#define CYPHER_H

#include <QObject>
#include <QString>

class Cypher : public QObject{
	//Macro para poder declarar slots y señales propios.
	Q_OBJECT
	
	public:
		Cypher( QObject* parent = 0 );
		
	public slots:
		void cypher( const QString& message );
	
	private:
		QString cypheredMsg;
		
		void cypher( QString& msg, int izq, int der );
	
	signals:
		void messageCyphered( const QString& );
};

#endif //CYPHER_H

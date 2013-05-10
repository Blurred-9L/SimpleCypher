#include "Cypher.h"

Cypher::Cypher( QObject* parent ) : QObject( parent ){
}

void Cypher::cypher( const QString& message ){
	QString msg( message );
	
	cypheredMsg.clear();
	cypher( msg, 0, msg.length() - 1 );
	
	emit messageCyphered( cypheredMsg );
}

void Cypher::cypher( QString& msg, int izq, int der ){
	int center = ( izq + der ) / 2;
	
	cypheredMsg.append( msg.at( center ).toAscii() );
	if( center - 1 >= izq ){
		cypher( msg, izq, center - 1 );
	}
	if( center + 1 <= der ){
		cypher( msg, center + 1, der );
	}
}

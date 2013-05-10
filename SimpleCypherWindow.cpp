#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>

#include "SimpleCypherWindow.h"

SimpleCypherWindow::SimpleCypherWindow(){
	QHBoxLayout* mainLayout = new QHBoxLayout( this );
	QVBoxLayout* buttonLayout = new QVBoxLayout();
	
	messageEdit = new QTextEdit();
	mainLayout -> addWidget( messageEdit );
	
	mainLayout -> addLayout( buttonLayout );
	cypherButton = new QPushButton( "Cypher" );
	buttonLayout -> addWidget( cypherButton );
	buttonLayout -> addStretch();
	
	cypherEdit = new QTextEdit();
	cypherEdit -> setReadOnly( true );
	mainLayout -> addWidget( cypherEdit );
	
	cypherObject = new Cypher( this );
	
	connect( cypherButton, SIGNAL( clicked() ), this, SLOT( getMessageText() ) );
	connect( this, SIGNAL( sendText( const QString& ) ), cypherObject, SLOT( cypher( const QString& ) ) );
	connect( cypherObject, SIGNAL( messageCyphered( const QString& ) ), cypherEdit, SLOT( append( const QString& ) ) );
}

void SimpleCypherWindow::getMessageText(){
	cypherEdit -> setPlainText( QString() );
	emit sendText( messageEdit -> toPlainText() );
}

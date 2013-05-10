#include <QApplication>

#include "SimpleCypherWindow.h"

int main( int argc, char* argv[] ){
	QApplication app( argc, argv );
	SimpleCypherWindow window;
	
	window.setAttribute( Qt::WA_QuitOnClose );
	window.show();
	
	return app.exec();
}

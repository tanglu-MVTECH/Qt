#include "booleanwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BooleanWindow w;
	w.resize(QSize(600,400));
	w.show();
	return a.exec();
}
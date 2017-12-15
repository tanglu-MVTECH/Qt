#include "directoryviewer.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DirectoryViewer *w = new DirectoryViewer;
	w->resize(QSize(600,400));
	w->show();
	return a.exec();
}
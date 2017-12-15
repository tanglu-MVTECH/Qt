#include "colornamesdialog.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ColorNamesDialog *w = new ColorNamesDialog;
	w->resize(QSize(600,400));
	w->show();
	return a.exec();
}
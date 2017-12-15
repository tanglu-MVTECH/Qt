#include "coordinatesetter.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QList<QPointF> list;
	list << QPointF(0.0, 0.9)
		<< QPointF(0.2, 11.0)
		<< QPointF(0.4, 15.4)
		<< QPointF(0.6, 12.9)
		<< QPointF(0.8, 8.5)
		<< QPointF(1.0, 7.1)
		<< QPointF(1.2, 4.0)
		<< QPointF(1.4, 13.6)
		<< QPointF(1.6, 22.2)
		<< QPointF(1.8, 22.2);
		
	CoordinateSetter w(&list);
	w.resize(QSize(600,400));
	w.show();
	return a.exec();
}
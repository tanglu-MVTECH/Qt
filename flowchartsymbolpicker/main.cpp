#include "flowchartsymbolpicker.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QMap<int, QString> symbolMap;
	symbolMap.insert(132, QObject::tr("Data"));
	symbolMap.insert(135, QObject::tr("Decision"));
	symbolMap.insert(137, QObject::tr("Document"));
	symbolMap.insert(138, QObject::tr("Manual Input"));
	symbolMap.insert(139, QObject::tr("Manual Operation"));
	symbolMap.insert(141, QObject::tr("On Page Reference"));
	symbolMap.insert(142, QObject::tr("Predefined Process"));
	symbolMap.insert(145, QObject::tr("Predefined"));
	symbolMap.insert(150, QObject::tr("Printer"));
	symbolMap.insert(152, QObject::tr("Process"));
	

	FlowChartSymbolPicker w(symbolMap);	
	w.resize(QSize(300,300));
	w.show();
	return a.exec();
}
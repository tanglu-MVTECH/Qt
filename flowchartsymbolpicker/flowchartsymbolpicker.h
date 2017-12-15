#ifndef FLOWCHARTSYMBOLPICKER_H
#define FLOWCHARTSYMBOLPICKER_H

#include <QtGui>
#include <QMap>
#include <QIcon>
#include <QDialog>
#include <QListWidget>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QDialogButtonBox>

class FlowChartSymbolPicker :public QDialog
{
	Q_OBJECT

public:
	FlowChartSymbolPicker(const QMap<int, QString>&symbolMap, QWidget *parent = 0);
	~FlowChartSymbolPicker();

	int selectedId() const { return id; }
	void done(int result);

private:
	QIcon iconForSymbol(const QString &symbolName);

	QListWidget *listWidget;
	QListWidgetItem *item;
	QDialogButtonBox *buttonBox;
	QVBoxLayout *mainLayout;
	int id;
};

#endif //FLOWCHARTSYMBOLPICKER_H

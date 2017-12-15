#ifndef BOOLEANWINDOW_H
#define BOOLEANWINDOW_H

#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QTreeView>
#include <QGridLayout>
#include "booleanmodel.h"
#include "booleanparser.h"

class BooleanWindow :public QWidget
{
	Q_OBJECT

public:
	BooleanWindow(QWidget *parent = 0);
	~BooleanWindow();

private slots:
	void booleanExpressionChanged(const QString &expr);

private:
	QLabel *label;
	QLineEdit *lineEdit;
	QTreeView *treeView;
	QGridLayout *mianLayout;
	BooleanModel *booleanModel;
};

#endif //BOOLEANWINDOW_H

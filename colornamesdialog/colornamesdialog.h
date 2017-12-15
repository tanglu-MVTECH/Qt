#ifndef COLORNAMESDIALOG_H
#define COLORNAMESDIALOG_H

#include <QtGui>
#include <QDialog>
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <QListView>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>

class ColorNamesDialog :public QDialog
{
	Q_OBJECT

public:
	ColorNamesDialog(QWidget *parent = 0);
	~ColorNamesDialog();

private slots:
	void reapplyFilter();

private:
	QStringListModel *sourceModel;
	QSortFilterProxyModel *proxyModel;
	QListView *listView;
	QLabel *filterLabel;
	QLabel *syntaxLabel;
	QLineEdit *filterLineEdit;
	QComboBox *syntaxComboBox;
	QGridLayout *mainLayout;
};

#endif //COLORNAMESDIALOG_H

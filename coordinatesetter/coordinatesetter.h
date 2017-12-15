#ifndef COORDINATESETTER_H
#define COORDINATESETTER_H

#include <QtGui>
#include <QDialog>
#include <QList>
#include <QString>
#include <QStringList>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDialogButtonBox>

class CoordinateSetter :public QDialog
{
	Q_OBJECT

public:
	CoordinateSetter(QList<QPointF> *coords, QWidget *parent = 0);
	~CoordinateSetter();

	void done(int result);

private slots:
	void addRow();

private:
	QList<QPointF> *coordinates;
	QTableWidget *tableWidget;
	QDialogButtonBox *buttonBox;
	QPushButton *addRowButton;
	QVBoxLayout *mainLayout;
	QTableWidgetItem *item0;
	QTableWidgetItem *item1;
};

#endif //COORDINATESETTER_H

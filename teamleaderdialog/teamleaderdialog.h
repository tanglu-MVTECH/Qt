#ifndef TEAMLEADERDIALOG_H
#define TEAMLEADERDIALOG_H

#include <QtGui>
#include <QDialog>
#include <QListView>
#include <QDialogButtonBox>
#include <QStringListModel>
#include <QPushButton>
#include <QVBoxLayout>

class TeamLeaderDialog :public QDialog
{
	Q_OBJECT

public:
	TeamLeaderDialog(const QStringList &leaders, QWidget *parent = 0);
	~TeamLeaderDialog();

	QStringList leaders() const;

private slots:
	void insert();
	void del();

private:
	QListView *listView;
	QDialogButtonBox *buttonBox;
	QStringListModel *model;
	QPushButton *insertButton;
	QPushButton *deleteButton;
	QVBoxLayout *mainLayout;
};

#endif //TEAMLEADERDIALOG_H

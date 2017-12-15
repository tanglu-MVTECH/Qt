#ifndef TEAMLEADERSDIALOG_H
#define TEAMLEADERSDIALOG_H

#include <QtGui>
#include <QDialog>
#include <QListView>
#include <QDialogButtonBox>
#include <QStringListModel>
#include <QPushButton>
#include <QVBoxLayout>

class TeamLeadersDialog :public QDialog
{
	Q_OBJECT

public:
	TeamLeadersDialog(const QStringList &leaders, QWidget *parent = 0);
	~TeamLeadersDialog();

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

#endif //TEAMLEADERSDIALOG_H

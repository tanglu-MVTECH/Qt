#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <QtGui>
#include <QDialog>
#include <QDirModel>
#include <QTreeView>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QMessageBox>

class DirectoryViewer :public QDialog
{
	Q_OBJECT

public:
	DirectoryViewer(QWidget *parent = 0);
	~DirectoryViewer();

private slots:
	void createDirectory();
	void remove();

private:
	QDirModel *model;
	QTreeView *treeView;
	QDialogButtonBox *buttonBox;
	QVBoxLayout *mainLayout;
	QPushButton *mkdirButton;
	QPushButton *removeButton;
	QModelIndex index;
};

#endif //TEMPLATE_H

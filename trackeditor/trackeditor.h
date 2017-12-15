#ifndef TRACKEDITOR_H
#define TRACKEDITOR_H

#include <QtGui>
#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QVBoxLayout>
#include "trackdelegate.h"

class Track
{
public:
	Track(const QString &title = "", int duration = 0);

	QString title;
	int duration;
};

class TrackEditor :public QDialog
{
	Q_OBJECT

public:
	TrackEditor(QList<Track> *tracks, QWidget *parent = 0);
	~TrackEditor();

	void done(int result);

private slots:
	void addTrack();

private:
	QTableWidget *tableWidget;
	QDialogButtonBox *buttonBox;
	QList<Track> *tracks;
	QTableWidgetItem *item0;
	QTableWidgetItem *item1;
	QPushButton *addTrackButton;
	QVBoxLayout *mainLayout;
};

#endif //TRACKEDITOR_H

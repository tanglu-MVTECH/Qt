#include "citymodel.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QStringList cities;
	cities << "Arvika" << "Boden" << "Eskilstuna" << "Falun"
			<< "Filipstad" << "Halmstad" << "Helsingborg" << "Karlstad"
			<< "Kiruna" << "Kramfors" << "Motala" << "Sandviken"
			<< "Skara" << "Stockholm" << "Sundsvall" << "Trelleborg";

	CityModel w;
	w.setCities(cities);

	QTableView tableView;
	tableView.setModel(&w);
	tableView.setAlternatingRowColors(true);

	tableView.setWindowTitle(QObject::tr("Cities"));
	tableView.resize(QSize(600,400));
	tableView.show();
	return a.exec();
}
#include "flowchartsymbolpicker.h"

FlowChartSymbolPicker::FlowChartSymbolPicker(
	const QMap<int, QString>&symbolMap, QWidget *parent)
	: QDialog(parent)
{
	id = -1;

	//��ͼ
	listWidget = new QListWidget;
	listWidget->setIconSize(QSize(60, 60));
	listWidget->setEditTriggers(QAbstractItemView::AnyKeyPressed);

	//����һ������ͼ�����鿴����
	QMapIterator<int, QString> i(symbolMap);
	while(i.hasNext())
	{
		i.next();

		//Ϊÿһ�����ݹ���һ������ͼ��MV�ṹ��MΪģ�����ݣ�i.value()����VΪ��ͼ��listWidget��
		item = new QListWidgetItem(i.value(), listWidget);

		//�趨һ����ͼ
		item->setIcon(iconForSymbol(i.value()));

		//��ID���浽QListWidgetItem��ȥ---Qt::UserRoleΪ�Զ����ɫ(ģ������)
		item->setData(Qt::UserRole, i.key());
	}
	buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

	mainLayout = new QVBoxLayout;
	mainLayout->addWidget(listWidget);
	mainLayout->addWidget(buttonBox);
	setLayout(mainLayout);
	setWindowTitle(tr("Flowchart Symbol Picker"));
}

void FlowChartSymbolPicker::done(int result)
{
	id = -1;
	if (result == QDialog::Accepted)
	{
		item = listWidget->currentItem();
		if(item)
			id = item->data(Qt::UserRole).toInt();
	}
	QDialog::done(result);
}

QIcon FlowChartSymbolPicker::iconForSymbol(const QString &symbolName)
{
	QString fileName = ":/images/" + symbolName.toLower();
	fileName.replace(' ', '-');
	return QIcon(fileName);
}

FlowChartSymbolPicker::~FlowChartSymbolPicker()
{

}

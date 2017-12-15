#include "teamleaderdialog.h"

TeamLeaderDialog::TeamLeaderDialog(const QStringList &leaders, QWidget *parent)
	: QDialog(parent)
{
	//�½�һ��QStringListModelģ��
	model = new QStringListModel(this);

	//��ʼ��ģ������
	model->setStringList(leaders);

	//listViewΪ��ͼ�����ݴ�ģ��model�л�ȡ
	listView = new QListView;
	listView->setModel(model);
	listView->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);

	buttonBox = new QDialogButtonBox;
	insertButton = buttonBox->addButton(tr("Insert"), QDialogButtonBox::ActionRole);
	deleteButton = buttonBox->addButton(tr("Delete"), QDialogButtonBox::ActionRole);
	buttonBox->addButton(QDialogButtonBox::Ok);
	buttonBox->addButton(QDialogButtonBox::Cancel);

	connect(insertButton, SIGNAL(clicked()), this, SLOT(insert()));
	connect(deleteButton, SIGNAL(clicked()), this, SLOT(del()));
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

	mainLayout = new QVBoxLayout;
	mainLayout->addWidget(listView);
	mainLayout->addWidget(buttonBox);
	setLayout(mainLayout);

	setWindowTitle("Team Leaders");
}

QStringList TeamLeaderDialog::leaders() const
{
	return model->stringList();
}

void TeamLeaderDialog::insert()
{
	//ģ�����ڲ���ʵ�ʵ�����---������һ�У�ɾ��һ�У�Ȼ��ͨ����ͼ����ʾ
	int row = listView->currentIndex().row();
	model->insertRows(row,1);

	//��������һ�е����ݱ�������ͼ�Ͻ�����д
	QModelIndex index = model->index(row);
	listView->setCurrentIndex(index);
	listView->edit(index);
}

void TeamLeaderDialog::del()
{
	model->removeRows(listView->currentIndex().row(), 1);
}

TeamLeaderDialog::~TeamLeaderDialog()
{

}
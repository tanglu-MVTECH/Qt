#include "directoryviewer.h"

DirectoryViewer::DirectoryViewer(QWidget *parent)
	: QDialog(parent)
{
	//�½�ģ��QDirModel,��������ֻ�����ԣ�������Ŀ¼���ȣ������ִ�Сд������������
	model = new QDirModel;
	model->setReadOnly(false);
	model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);

	//�½���ͼ
	treeView = new QTreeView;

	//����ͼ��ģ�͹�������
	treeView->setModel(model);

	//������ͼ����
	treeView->header()->setStretchLastSection(true);
	treeView->header()->setSortIndicator(0, Qt::AscendingOrder);
	treeView->header()->setSortIndicatorShown(true);
	treeView->header()->setClickable(true);

	index = model->index(QDir::currentPath());

	//�趨ģ�����ݿ���չ
	treeView->expand(index);
	treeView->scrollTo(index);
	treeView->resizeColumnToContents(0);

	buttonBox = new QDialogButtonBox(Qt::Horizontal);
	mkdirButton = buttonBox->addButton(tr("&Create Directory..."), QDialogButtonBox::ActionRole);
	removeButton = buttonBox->addButton(tr("&Remove"), QDialogButtonBox::ActionRole);
	buttonBox->addButton(tr("&Quit"), QDialogButtonBox::AcceptRole);

	connect(mkdirButton, SIGNAL(clicked()), this, SLOT(createDirectory()));
	connect(removeButton, SIGNAL(clicked()), this, SLOT(remove()));
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));

	mainLayout = new QVBoxLayout;
	mainLayout->addWidget(treeView);
	mainLayout->addWidget(buttonBox);
	setLayout(mainLayout);

	setWindowTitle("Directory Viewer");
}

void DirectoryViewer::createDirectory()
{
	//�ҵ�Ҫ�����ļ��е�λ��
	index = treeView->currentIndex();
	if(!index.isValid())
		return;

	QString dirName = QInputDialog::getText(this, tr("Create Directory"), tr("Directory name"));

	if (!dirName.isEmpty())
	{
		//�����ļ���
		if(!model->mkdir(index, dirName).isValid())
			QMessageBox::information(this, tr("Create Directory"), 
					tr("Failed to create the directory"));
	}
}

void DirectoryViewer::remove()
{
	index = treeView->currentIndex();
	if(!index.isValid())
		return;

	bool ok;

	//�ж����ļ��л����ļ�
	if (model->fileInfo(index).isDir())
	{
		ok = model->rmdir(index);
	} 
	else
	{
		ok = model->remove(index);
	}
	if(!ok)
		QMessageBox::information(this, tr("Remove"),
				tr("Failed to remove %1").arg(model->fileName(index)));
}

DirectoryViewer::~DirectoryViewer()
{

}
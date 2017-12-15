#include "booleanwindow.h"

BooleanWindow::BooleanWindow(QWidget *parent)
	: QWidget(parent)
{
	label = new QLabel(tr("Boolean expression:"));
	lineEdit = new QLineEdit;

	booleanModel = new BooleanModel(this);

	treeView = new QTreeView;
	treeView->setModel(booleanModel);

	mianLayout = new QGridLayout;
	mianLayout->addWidget(label, 0, 0);
	mianLayout->addWidget(lineEdit, 0, 1);
	mianLayout->addWidget(treeView, 1, 0, 1, 2);
	setLayout(mianLayout);

	connect(lineEdit, SIGNAL(textChanged(const QString &)),
			this, SLOT(booleanExpressionChanged(const QString &)));

	setWindowTitle(tr("Boolean Parser"));
}

void BooleanWindow::booleanExpressionChanged(const QString &expr)
{
	BooleanParser parser;
	Node *rootNode = parser.parse(expr);
	booleanModel->setRootNode(rootNode);
}

BooleanWindow::~BooleanWindow()
{

}
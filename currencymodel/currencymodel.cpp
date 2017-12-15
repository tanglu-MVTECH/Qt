#include "currencymodel.h"

CurrencyModel::CurrencyModel(QWidget *parent)
	: QAbstractTableModel(parent)
{

}

int CurrencyModel::rowCount(const QModelIndex & /* parent */) const
{
	return currencyMap.count();
}

int CurrencyModel::columnCount(const QModelIndex & /* parent */) const
{
	return currencyMap.count();
}

//roleΪ��ɫ����ͬ�Ľ�ɫִ�в�ͬ�Ķ�����ͨ������index���������ݵĶ�ȡ
QVariant CurrencyModel::data(const QModelIndex &index, int role) const
{
	if(!index.isValid())
		return QVariant();

	//����������ƥ��Ķ���ģʽ
	if (role == Qt::TextAlignmentRole)
	{
		return int(Qt::AlignRight | Qt::AlignVCenter);
	} 
	else if(role == Qt::DisplayRole)//���򷵻�����
	{
		QString rowCurrency = currencyAt(index.row());
		QString columnCurrency = currencyAt(index.column());

		//0���ܱ���
		if(currencyMap.value(rowCurrency) == 0.0)
			return "####";

		double amount = currencyMap.value(columnCurrency) / currencyMap.value(rowCurrency);

		return QString("%1").arg(amount, 0, 'f', 4);
	}
	return QVariant();
}

//���ڶ���߿��ͷ�к�ͷ��
QVariant CurrencyModel::headerData(int section, Qt::Orientation /*orientation*/, int role) const
{
	if(role != Qt::DisplayRole)
		return QVariant();
	return currencyAt(section);
}

void CurrencyModel::setCurrencyMap(const QMap<QString, double>&map)
{
	currencyMap = map;
	reset();
}

QString CurrencyModel::currencyAt(int offset) const
{
	return (currencyMap.begin() + offset).key();
}

CurrencyModel::~CurrencyModel()
{

}
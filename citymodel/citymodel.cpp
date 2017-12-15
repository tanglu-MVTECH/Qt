#include "citymodel.h"

CityModel::CityModel(QWidget *parent)
	: QAbstractTableModel(parent)
{

}

int CityModel::rowCount(const QModelIndex & /* parent */) const
{
	return cities.count();
}

int CityModel::columnCount(const QModelIndex & /* parent */) const
{
	return cities.count();
}

//role为角色，不同的角色执行不同的动作，通过索引index来进行数据的读取
QVariant CityModel::data(const QModelIndex &index, int role) const
{
	if(!index.isValid())
		return QVariant();

	//返回于数字匹配的对其模式
	if (role == Qt::TextAlignmentRole)
	{
		return int(Qt::AlignRight | Qt::AlignVCenter);
	} 
	else if(role == Qt::DisplayRole)//否则返回数据
	{
		if(index.row() == index.column())
			return 0;
		int offset = offsetOf(index.row(), index.column());
		return distances[offset];
	}
	return QVariant();
}

QVariant CityModel::headerData(int section, Qt::Orientation /*orientation*/, int role) const
{
	if(role != Qt::DisplayRole)
		return QVariant();
	return cities[section];
}

void CityModel::setCities(const QStringList &cityNames)
{
	cities = cityNames;
	distances.resize(cities.count() * (cities.count() - 1) / 2);
	distances.fill(0);
	reset();
}

bool CityModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (index.isValid() && index.row() != index.column() && role == Qt::EditRole)
	{
		int offset = offsetOf(index.row(), index.column());
		distances[offset] = value.toInt();

		QModelIndex transposedIndex = createIndex(index.column(), index.row());

		emit dataChanged(index, index);
		emit dataChanged(transposedIndex, transposedIndex);
		return true;
	}
	return false;
}

Qt::ItemFlags CityModel::flags(const QModelIndex &index) const
{
	Qt::ItemFlags flags = QAbstractTableModel::flags(index);
	if(index.row() != index.column())
		flags |= Qt::ItemIsEditable;
	return flags;
}

int CityModel::offsetOf(int row, int column) const
{
	if(row < column)
		qSwap(row, column);
	return (row * (row - 1) / 2) + column;
}

CityModel::~CityModel()
{

}
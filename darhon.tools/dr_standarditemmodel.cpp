//Release 3
#include "dr_standarditemmodel.h"

CStandardItemModel::CStandardItemModel(QObject *pObject)
    : QStandardItemModel(pObject)
{
    m_hashRoles.clear();
}

QVariant CStandardItemModel::data(const QModelIndex &Index, int iRole) const
{
    if (iRole >= Qt::UserRole)
        return QStandardItemModel::data(index(Index.row(), iRole - Qt::UserRole));

    return QStandardItemModel::data(Index, iRole);
}

bool CStandardItemModel::setData(const QModelIndex &Index, const QVariant &Value, int iRole)
{
    if (iRole >= Qt::UserRole) {
        QStandardItemModel::setData(index(Index.row(), iRole - Qt::UserRole), Value);
        emit dataChanged(Index, Index, {Qt::EditRole, Qt::DisplayRole});
    }

    return QStandardItemModel::setData(Index, Value, iRole);
}

QHash<int, QByteArray> CStandardItemModel::roleNames() const
{
    return m_hashRoles;
}

void CStandardItemModel::setProxyModel(int iCols)
{
    m_hashRoles.clear();
    for (int i = 0; i < iCols; i++)
        m_hashRoles.insert(Qt::UserRole + i, QByteArray("role_c") + QByteArray::number(i));
}

void CStandardItemModel::refreshQMLModel()
{
    emit layoutChanged();
}

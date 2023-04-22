#ifndef STANDARDITEMMODEL_H
#define STANDARDITEMMODEL_H

#include <QStandardItemModel>

class CStandardItemModel : public QStandardItemModel
{
    Q_OBJECT

    QHash<int, QByteArray> m_hashRoles;

public:
    explicit CStandardItemModel(QObject *pObject = nullptr);
    QVariant data(const QModelIndex &Index, int iRole = Qt::DisplayRole) const;
    bool setData(const QModelIndex &Index, const QVariant &Value, int iRole = Qt::EditRole);
    QHash<int, QByteArray> roleNames() const;
    void setProxyModel(int iCols);
    void refreshQMLModel();

signals:

public slots:
};

#endif // STANDARDITEMMODEL_H

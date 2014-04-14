#ifndef RGBHISTOGRAMMODEL_H
#define RGBHISTOGRAMMODEL_H

#include <QAbstractItemModel>
#include "rgbhistogram.h"

class RgbHistogramModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum HistogramRoles {
        BinNumberRole = Qt::UserRole + 1,
        RedCountRole,
        GreenCountRole,
        BlueCountRole
    };

    RgbHistogramModel(RgbHistogram *histogram):
        QAbstractListModel(histogram), m_histogram(histogram)
    { }

    QHash<int, QByteArray> roleNames() const {
        QHash<int, QByteArray> roles;
        roles[BinNumberRole] = "binNumber";
        roles[RedCountRole] = "redCount";
        roles[GreenCountRole] = "greenCount";
        roles[BlueCountRole] = "blueCount";
        return roles;
    }

    int rowCount(const QModelIndex &) const {
        return m_histogram->binCount();
    }

    QVariant data(const QModelIndex &index, int role) const {
        int bin = index.row();
        switch (role) {
        case BinNumberRole:
            return bin;
        case RedCountRole:
            return m_histogram->redCount(bin);
        case GreenCountRole:
            return m_histogram->greenCount(bin);
        case BlueCountRole:
            return m_histogram->blueCount(bin);
        }
        return 0;
    }

private:
    RgbHistogram *m_histogram;
};

#endif // RGBHISTOGRAMMODEL_H

#ifndef RGBHISTOGRAM_H
#define RGBHISTOGRAM_H

#include <QObject>

class RgbHistogram : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString imageSource READ imageSource WRITE setImageSource NOTIFY imageSourceChanged)

public:
    explicit RgbHistogram(QObject *parent = 0);

    QString imageSource() const
    {
        return m_imageSource;
    }

signals:
    void imageSourceChanged(QString arg);

public slots:

    void setImageSource(QString arg)
    {
        if (m_imageSource != arg) {
            m_imageSource = arg;
            emit imageSourceChanged(arg);
        }
    }

private:
    QString m_imageSource;
};

#endif // RGBHISTOGRAM_H

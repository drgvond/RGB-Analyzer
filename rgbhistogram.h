#ifndef RGBHISTOGRAM_H
#define RGBHISTOGRAM_H

#include <QObject>
#include <QUrl>

class RgbHistogram : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl imageSource READ imageSource WRITE setImageSource NOTIFY imageSourceChanged)
    Q_PROPERTY(int binSize READ binSize WRITE setBinSize NOTIFY binSizeChanged)

public:
    explicit RgbHistogram(QObject *parent = 0);

    QUrl imageSource() const
    {
        return m_imageSource;
    }

    int binSize() const
    {
        return m_binSize;
    }

    Q_INVOKABLE void compute();

signals:
    void imageSourceChanged(QUrl arg);
    void binSizeChanged(int arg);

public slots:

    void setImageSource(QUrl arg)
    {
        if (m_imageSource != arg) {
            m_imageSource = arg;
            emit imageSourceChanged(arg);
        }
    }

    void setBinSize(int arg)
    {
        if (m_binSize != arg) {
            m_binSize = arg;
            emit binSizeChanged(arg);
        }
    }

private:
    QUrl m_imageSource;
    int m_binSize;
};

#endif // RGBHISTOGRAM_H

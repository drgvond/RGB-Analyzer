#ifndef RGBHISTOGRAM_H
#define RGBHISTOGRAM_H

#include <QObject>
#include <QUrl>

class RgbHistogram : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl imageSource READ imageSource WRITE setImageSource NOTIFY imageSourceChanged)
    Q_PROPERTY(int binCount READ binCount WRITE setBinCount NOTIFY binCountChanged)

public:
    explicit RgbHistogram(QObject *parent = 0);

    QUrl imageSource() const
    {
        return m_imageSource;
    }

    int binCount() const
    {
        return m_binCount;
    }

    Q_INVOKABLE void compute();

signals:
    void imageSourceChanged(QUrl arg);
    void binCountChanged(int arg);

public slots:

    void setImageSource(QUrl arg)
    {
        if (m_imageSource != arg) {
            m_imageSource = arg;
            emit imageSourceChanged(arg);
        }
    }

    void setBinCount(int arg)
    {
        if (m_binCount != arg) {
            m_binCount = arg;
            emit binCountChanged(arg);
        }
    }

private:
    QUrl m_imageSource;
    int m_binCount;
};

#endif // RGBHISTOGRAM_H

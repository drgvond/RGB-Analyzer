#ifndef RGBHISTOGRAM_H
#define RGBHISTOGRAM_H

#include <QObject>
#include <QUrl>

class RgbHistogramModel;

class RgbHistogram : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl imageSource READ imageSource WRITE setImageSource NOTIFY imageSourceChanged)
    Q_PROPERTY(int binCount READ binCount WRITE setBinCount NOTIFY binCountChanged)
    Q_PROPERTY(RgbHistogramModel *histogramData READ histogramData NOTIFY histogramDataChanged)

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

    RgbHistogramModel *histogramData() const
    {
        return m_histogramData;
    }

    Q_INVOKABLE void compute();

    int redCount(int bin);
    int greenCount(int bin);
    int blueCount(int bin);

signals:
    void imageSourceChanged(QUrl arg);
    void binCountChanged(int arg);

    void histogramDataChanged(RgbHistogramModel * arg);

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
    RgbHistogramModel *m_histogramData;
};

#endif // RGBHISTOGRAM_H

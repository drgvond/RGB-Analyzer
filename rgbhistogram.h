#ifndef RGBHISTOGRAM_H
#define RGBHISTOGRAM_H

#include <QObject>
#include <QUrl>
#include <QVector>

class RgbHistogramModel;

class RgbHistogram : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl imageSource READ imageSource WRITE setImageSource NOTIFY imageSourceChanged)
    Q_PROPERTY(int binCount READ binCount WRITE setBinCount NOTIFY binCountChanged)
    Q_PROPERTY(RgbHistogramModel *histogramData READ histogramData NOTIFY histogramDataChanged)
    Q_PROPERTY(int maxValue READ maxValue NOTIFY maxValueChanged)

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

    int maxValue() const
    {
        return m_maxValue;
    }

signals:
    void imageSourceChanged(QUrl arg);
    void binCountChanged(int arg);

    void histogramDataChanged(RgbHistogramModel * arg);

    void maxValueChanged(int arg);

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
            m_bins.resize(m_binCount);
            m_bins.fill(RgbHistogram::RgbBin());
            emit binCountChanged(arg);
        }
    }

private:
    inline int binForValue(int v)
    {
        return v * m_binCount / 256;
    }

    struct RgbBin {
        int red;
        int green;
        int blue;
    };

    QUrl m_imageSource;
    int m_binCount;
    RgbHistogramModel *m_histogramData;
    QVector<RgbBin> m_bins;
    int m_maxValue;
};

#endif // RGBHISTOGRAM_H

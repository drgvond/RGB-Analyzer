#include "rgbhistogram.h"
#include "rgbhistogrammodel.h"
#include <QImage>
#include <QClipboard>
#include <QGuiApplication>

RgbHistogram::RgbHistogram(QObject *parent) :
    QObject(parent), m_binCount(1), m_maxValue(1)
{
    m_histogramData = new RgbHistogramModel(this);
}

void RgbHistogram::compute()
{
    QImage img(m_imageSource.toLocalFile());
    if (img.isNull())
        return;

    m_bins.clear();
    m_bins.resize(m_binCount);

    for (int i = 0; i < img.height(); ++i) {
        const QRgb *pixels = reinterpret_cast<const QRgb *>(img.constScanLine(i));
        for (int j = 0; j < img.width(); ++j) {
            m_bins[binForValue(qRed(*pixels))].red++;
            m_bins[binForValue(qGreen(*pixels))].green++;
            m_bins[binForValue(qBlue(*pixels))].blue++;
            ++pixels;
        }
    }

    m_maxValue = 0;
    foreach (const RgbBin &bin, m_bins) {
        if (bin.red > m_maxValue)
            m_maxValue = bin.red;
        if (bin.green > m_maxValue)
            m_maxValue = bin.green;
        if (bin.blue > m_maxValue)
            m_maxValue = bin.blue;
    }
    emit maxValueChanged(m_maxValue);

    m_histogramData->histogramUpdated();
}

int RgbHistogram::redCount(int bin) const
{
    return m_bins[bin].red;
}

int RgbHistogram::greenCount(int bin) const
{
    return m_bins[bin].green;
}

int RgbHistogram::blueCount(int bin) const
{
    return m_bins[bin].blue;
}

void RgbHistogram::copyBinsToClipboard(const QVariantList &indices) const
{
    QStringList csvData;
    foreach (const QVariant &v, indices) {
        int bin = v.toInt();
        csvData << QString().sprintf("%d, %d, %d, %d", bin, redCount(bin), greenCount(bin), blueCount(bin));
    }
    QClipboard *cb = QGuiApplication::clipboard();
    cb->setText(csvData.join(QLatin1Char('\n')));
}

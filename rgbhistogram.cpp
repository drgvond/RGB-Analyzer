#include "rgbhistogram.h"
#include "rgbhistogrammodel.h"
#include <QImage>

RgbHistogram::RgbHistogram(QObject *parent) :
    QObject(parent), m_binCount(1)
{
    m_histogramData = new RgbHistogramModel(this);
}

void RgbHistogram::compute()
{
    QImage img(m_imageSource.toLocalFile());
    Q_ASSERT(!img.isNull());

    m_bins.resize(m_binCount);
    m_bins.fill(RgbHistogram::RgbBin());

    for (int i = 0; i < img.height(); ++i) {
        const QRgb *pixels = reinterpret_cast<const QRgb *>(img.constScanLine(i));
        for (int j = 0; j < img.width(); ++j) {
            m_bins[binForValue(qRed(*pixels))].red++;
            m_bins[binForValue(qGreen(*pixels))].green++;
            m_bins[binForValue(qBlue(*pixels))].blue++;
            ++pixels;
        }
    }

    emit m_histogramData->dataChanged(m_histogramData->index(0, 0),
                                      m_histogramData->index(binCount() - 1, 0));
}

int RgbHistogram::redCount(int bin)
{
    return m_bins[bin].red;
}

int RgbHistogram::greenCount(int bin)
{
    return m_bins[bin].green;
}

int RgbHistogram::blueCount(int bin)
{
    return m_bins[bin].blue;
}

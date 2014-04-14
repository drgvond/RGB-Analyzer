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
    for (int i = 0; i < img.height(); ++i) {
        const QRgb *pixels = reinterpret_cast<const QRgb *>(img.constScanLine(i));
        for (int j = 0; j < img.width(); ++j) {

            ++pixels;
        }
    }

    emit m_histogramData->dataChanged(m_histogramData->index(0, 0),
                                      m_histogramData->index(binCount() - 1, 0));
}

int RgbHistogram::redCount(int bin)
{
    return bin * 3;
}

int RgbHistogram::greenCount(int bin)
{
    return bin * 4;
}

int RgbHistogram::blueCount(int bin)
{
    return bin * 5;
}

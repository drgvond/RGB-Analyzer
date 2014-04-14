#include "rgbhistogram.h"
#include <QImage>

RgbHistogram::RgbHistogram(QObject *parent) :
    QObject(parent), m_binCount(1)
{
}

void RgbHistogram::compute()
{
    QImage img(m_imageSource.toLocalFile());
    Q_ASSERT(!img.isNull());
    for (int i = 0; i < img.height(); ++i) {
        const QRgb *pixels = reinterpret_cast<const QRgb *>(img.constScanLine(i));
        for (int j = 0; j < img.width(); ++j) {
            // ...
            ++pixels;
        }
    }
}

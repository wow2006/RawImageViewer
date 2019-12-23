// Qt5
#include <QPainter>
// Internal
#include "ImageView.hpp"
#include "ImageModel.hpp"

ImageView::ImageView(ImageModel* pModel, QWidget *pParent)
  : QFrame(pParent), m_pImageModel{pModel} {}

ImageView::~ImageView() = default;

void ImageView::paintEvent(QPaintEvent *pEvent) {
  Q_UNUSED(pEvent)
  //QPainter painter{this};
  //const auto& fullScaleImage = m_pImageModel->image();
  //QSize size = fullScaleImage.size().scaled(this->size(), Qt::KeepAspectRatio);
  //painter.drawImage(QRect(0, 0, size.width(), size.height()), fullScaleImage);
}

void ImageView::resizeEvent(QResizeEvent *event) {
  QFrame::resizeEvent(event);
}

void ImageView::contextMenuEvent(QContextMenuEvent *event) {
  QFrame::contextMenuEvent(event);
}

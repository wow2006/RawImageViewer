#pragma once
// Qt5
#include <QFrame>

QT_FORWARD_DECLARE_CLASS(ImageModel)

class ImageView : public QFrame {
Q_OBJECT
public:
  explicit ImageView(ImageModel *pModel, QWidget *pParent = nullptr);

  ~ImageView() override;

protected:
  void paintEvent(QPaintEvent *event) override;

  void resizeEvent(QResizeEvent *event) override;

  void contextMenuEvent(QContextMenuEvent *event) override;

private:
  ImageModel *m_pImageModel;
};

#pragma once
// Qt5
#include <QDialog>

QT_FORWARD_DECLARE_CLASS(QLayout)
QT_FORWARD_DECLARE_CLASS(QSpinBox)
QT_FORWARD_DECLARE_CLASS(QComboBox)
QT_FORWARD_DECLARE_CLASS(QGraphicsView)
QT_FORWARD_DECLARE_CLASS(QGraphicsScene)
QT_FORWARD_DECLARE_CLASS(QGraphicsPixmapItem)

QT_FORWARD_DECLARE_CLASS(ImageView)

class MainWidget : public QDialog {
  Q_OBJECT
public:
  explicit MainWidget(QWidget *pParent = nullptr) noexcept;

  ~MainWidget() override;

  void createGroup(QLayout *pLayout);

  void createScene();

  void updateGradient();

  /*
  void updateGradient() {
    QLinearGradient gradient;
    gradient.setStart(0, 0);
    gradient.setFinalStop(0, m_pView->rect().height());
    QColor grey1(0, 0, 0, 125);
    QColor grey2(255, 255, 255, 125);
    gradient.setColorAt(0, grey1);
    gradient.setColorAt(1, grey2);
    m_pScene->setBackgroundBrush(gradient);
  }
*/

private:
  QSpinBox *m_pWidthSpin = nullptr;
  QSpinBox *m_pHeightSpin = nullptr;

  QComboBox *m_pFormatCombo = nullptr;
  ImageView *m_pImageView = nullptr;
};

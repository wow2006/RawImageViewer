// Qt5
#include <QComboBox>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>
// Internal
#include "ImageModel.hpp"
#include "ImageView.hpp"
#include "MainWidget.hpp"

MainWidget::MainWidget(QWidget *pParent) noexcept :
    QDialog{pParent}, m_pWidthSpin{new QSpinBox}, m_pHeightSpin{new QSpinBox}, m_pFormatCombo{new QComboBox} {
  auto pLayout1 = new QHBoxLayout;
  auto pLayout2 = new QVBoxLayout;

  const QString imageName = "/home/ahussein/Documents/sourceCode/images/sequence_37/images/00000.jpg";
  //auto m_pImageModel = new ImageModel(imageName);
  //m_pImageView = new ImageView(m_pImageModel, this);

  setLayout(pLayout1);
  pLayout1->addWidget(m_pImageView);
  pLayout1->addLayout(pLayout2);

  createGroup(pLayout2);
  pLayout2->addStretch();

  setMinimumSize({640, 480});

  QStringList supportedFormats;
  supportedFormats << "RGB";

  m_pFormatCombo->addItems(supportedFormats);
}

MainWidget::~MainWidget() = default;

void MainWidget::createGroup(QLayout *pLayout) {
  auto pLayout1 = new QHBoxLayout;
  auto pWidthLabel = new QLabel{"Width"};
  pLayout1->addWidget(pWidthLabel);
  pLayout1->addWidget(m_pWidthSpin);

  auto pLayout2 = new QHBoxLayout;
  auto pHeightLabel = new QLabel{"Height"};
  pLayout2->addWidget(pHeightLabel);
  pLayout2->addWidget(m_pHeightSpin);

  auto pLayout3 = new QHBoxLayout;
  auto pComboLabel = new QLabel{"Formats"};
  pLayout3->addWidget(pComboLabel);
  pLayout3->addWidget(m_pFormatCombo);

  auto pLayout4 = new QVBoxLayout;
  pLayout4->addLayout(pLayout1);
  pLayout4->addLayout(pLayout2);
  pLayout4->addLayout(pLayout3);

  auto pImageInfoGroup = new QGroupBox("Image info");
  pImageInfoGroup->setLayout(pLayout4);

  pLayout->addWidget(pImageInfoGroup);
}

#pragma once
// Qt5
#include <QObject>

/*
 * The porpoise of this model
 *
 *
 *
 */

class ImageModel {
public:
  bool loaded() const {
    return false;
  }

  bool load(std::istream& inputStream);

private:
  std::vector<std::uint8_t> m_vBuffer;
};


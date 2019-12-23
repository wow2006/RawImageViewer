// STL
#include <iostream>
// Internal
#include "ImageModel.hpp"

bool ImageModel::load(std::istream& inputStream) {
  //inputStream.seekg(0, std::ios::end);
  const auto streamSize = inputStream.tellg();
  std::cout << "streamsize: " << streamSize << std::endl;
  if(streamSize <= 0) {
    return false;
  }
  inputStream.seekg(0, std::ios::beg);
  m_vBuffer.resize(streamSize);
  inputStream.read(reinterpret_cast<char*>(m_vBuffer.data()), streamSize);
  return m_vBuffer.size() > 0;
}

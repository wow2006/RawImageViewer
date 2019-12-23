// STL
#include <iostream>
// Qt5
#include <QTest>
#include <QSignalSpy>
// Internal
#include "ImageModel.hpp"

class DummyBuffer : public std::streambuf {
public:
  explicit DummyBuffer(std::vector<std::uint8_t>* pBuffer) noexcept;

  ~DummyBuffer() override;

protected:
  pos_type seekoff(off_type off, std::ios_base::seekdir dir,
                   std::ios_base::openmode which = std::ios_base::in | std::ios_base::out) override;

private:
  int_type underflow() override;

  int_type uflow() override;

  int_type pbackfail(int_type ch) override;

  std::streamsize showmanyc() override;

  std::vector<std::uint8_t>* m_pBuffer;

  const std::uint8_t* m_pCurrent;
};

DummyBuffer::DummyBuffer(std::vector<std::uint8_t>* pBuffer) noexcept
  : m_pBuffer{pBuffer}, m_pCurrent{m_pBuffer->data()} {}

DummyBuffer::~DummyBuffer() = default;

DummyBuffer::pos_type DummyBuffer::seekoff(off_type off, std::ios_base::seekdir dir,
                   std::ios_base::openmode which) {
  std::cout << __PRETTY_FUNCTION__ << " "
            << off << ", " << dir << ", " << which << std::endl;
  return pos_type(off_type(-1));
}


DummyBuffer::int_type DummyBuffer::underflow() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return -1;
}

DummyBuffer::int_type DummyBuffer::uflow() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return -1;
}

DummyBuffer::int_type DummyBuffer::pbackfail(int_type ch) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return -1;
}

std::streamsize DummyBuffer::showmanyc() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return -1;
}

class TestModel : public QObject {
Q_OBJECT
private Q_SLOTS:
  void test_defaultConstructor();
  void test_loadFromStream();
};

void TestModel::test_defaultConstructor() {
  ImageModel model;
  QCOMPARE(model.loaded(), false);
}

void TestModel::test_loadFromStream() {
  std::vector<std::uint8_t> buffer(8, 255);
  DummyBuffer dummyBuffer{&buffer};
  std::istream dummyStream(&dummyBuffer);
  ImageModel model;
  QCOMPARE(model.load(dummyStream), true);
}

QTEST_MAIN(TestModel)
#include "test_model.moc"


// Qt5
#include <QApplication>
// Internal
#include "MainWidget.hpp"

int main(int argc, char* argv[]) {
  QApplication app{argc, argv};

  MainWidget widget;
  widget.show();

  return QApplication::exec();
}

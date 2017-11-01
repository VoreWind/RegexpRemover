#include <QCoreApplication>

#include <filecleaner.h>
#include <QRegExp>

int main(int argc, char *argv[]) {
  if (argc > 1) {
    QString file_path = argv[1];
    FileCleaner::ClearRegExpFromFile(file_path,
                                     QRegExp("[ \\]*TRACE\\(.+\\);\n"));
  }
  return 0;
}

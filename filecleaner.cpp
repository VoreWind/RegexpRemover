#include "filecleaner.h"

#include <QFile>
#include <QRegExp>
#include <QString>
#include <QTextStream>

void FileCleaner::ClearRegExpFromFile(const QString &file_path,
                                      const QRegExp &regexp) {
  QFile source_file(file_path);
  source_file.open(QIODevice::ReadWrite);

  QTextStream in_out(&source_file);
  in_out.setCodec("UTF-8");
  QString file_contents = in_out.readAll();

  file_contents.remove(regexp);
  source_file.resize(0);
  in_out << file_contents;
}

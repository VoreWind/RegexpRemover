#include "filecleaner.h"

#include <QFile>
#include <QRegExp>
#include <QString>
#include <QTextStream>

#include <QDebug>

void FileCleaner::ClearRegExpFromFile(const QString &file_path,
                                      const QString &regexp_string) {
  QRegExp regexp(regexp_string);
  if (!regexp.isValid()) {
    return;
  }

  QFile source_file(file_path);
  source_file.open(QIODevice::ReadWrite);

  regexp.setMinimal(true);
  QTextStream in_out(&source_file);
  in_out.setCodec("UTF-8");
  QString file_contents = in_out.readAll();

  if (file_contents.indexOf(regexp) == -1) {
    return;
  }

  file_contents.remove(regexp);
  source_file.resize(0);
  in_out << file_contents;
}

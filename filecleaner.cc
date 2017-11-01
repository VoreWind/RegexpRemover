#include "filecleaner.h"

#include <unistd.h>

#include <QFile>
#include <QRegExp>
#include <QString>
#include <QTextStream>

#include <QDebug>

void FileCleaner::ClearRegExpFromFile(const QString &file_path,
                                      const QString &regexp_string) {
  QFile source_file(file_path);
  source_file.open(QIODevice::ReadWrite);

  QRegExp regexp(regexp_string);
  regexp.setMinimal(true);
  QTextStream in_out(&source_file);
  in_out.setCodec("UTF-8");
  QString file_contents = in_out.readAll();

  qDebug() << file_contents.indexOf(regexp) << regexp.isValid();
  file_contents.remove(regexp);
  source_file.resize(0);
  in_out << file_contents;
}

#include <QCoreApplication>

#include <filecleaner.h>
#include <QRegExp>
#include <QStringList>

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);
  QStringList arguments = app.arguments();
  arguments.pop_front();
  QString regexp_string;
  QStringList file_paths;

  for (auto argument : arguments) {
    QString regexp_key = "--regexp=";
    if (argument.startsWith(regexp_key)) {
      regexp_string = argument.right(regexp_key.count());
    }

    else
      file_paths.append(argument);
  }

  if (regexp_string.isEmpty()) {
    regexp_string = "[ ]+TRACE\\(.+\\);\n";
  }

  for (auto file_path : file_paths) {
    FileCleaner::ClearRegExpFromFile(file_path, regexp_string);
  }
  return 0;
}

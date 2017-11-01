#ifndef FILECLEANER_H
#define FILECLEANER_H

class QString;
class QRegExp;

class FileCleaner {
 public:
  static void ClearRegExpFromFile(const QString& file_path,
                                  const QRegExp& regexp);
};

#endif  // FILECLEANER_H

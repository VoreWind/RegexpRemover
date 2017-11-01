#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QRegExp>
#include <QString>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->purge_button, SIGNAL(pressed()), SLOT(RemoveRegexp()));
  connect(ui->file_button, SIGNAL(pressed()), SLOT(ChooseFile()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::RemoveRegexp() {
  QRegExp regexp(ui->regexp_line->text());
  regexp.setMinimal(true);

  if (ui->file_path_line->text().isEmpty()) {
    QString text_string = ui->text_edit->toPlainText();
    text_string.remove(regexp);
    ui->text_edit->setText(text_string);
  } else {
    QString file_path = ui->file_path_line->text();
    QFile source_file(file_path);
    source_file.open(QIODevice::ReadWrite);

    QTextStream in_out(&source_file);
    in_out.setCodec("UTF-8");
    QString file_contents = in_out.readAll();

    file_contents.remove(regexp);
    source_file.resize(0);
    in_out << file_contents;
  }
}

void MainWindow::ChooseFile() {
  QString file_name = QFileDialog::getOpenFileName(
      this, tr("Open file"), "/home/", tr("Source files (*.cc *.c *.h)"));
  ui->file_path_line->setText(file_name);
}

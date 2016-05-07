#include "path.h"
#include "ui_path.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <iostream>

Path::Path(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Path)
{
    ui->setupUi(this);
}

Path::~Path()
{
    delete ui;
}

void Path::on_pushButton_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("模型位置"));
    fileDialog->setDirectory(".");
    QString fpath = fileDialog->getExistingDirectory();
    std::cout << fpath.toStdString() << std::endl;
    if(fpath.length() != 0) {
        QMessageBox::information(NULL, tr("路径"), fpath);
        ui->pathlabel->setText(fpath);
    }
    else {
        QMessageBox::information(NULL, tr("错误"), "您没有选择任何文件夹！");
    }
}

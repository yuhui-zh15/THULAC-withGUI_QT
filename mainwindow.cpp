#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "./src/thulac.h"
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <string>
#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonRun_clicked()
{
    //用UI初始化
    bool isSegOnly = ui->isSegOnly->isChecked();
    bool isT2S = ui->isT2S->isChecked();
    bool isFilter = ui->isFilter->isChecked();
    //判断模型位置
    QString filePath = ui->pathLabel->text();
    if(filePath.length()==0) {
        QMessageBox::information(NULL, "错误", "请先设置模型位置！");
        return;
    }
    filePath += '/';
    //判断分隔符
    QString para = ui->paraText->toPlainText();
    if(para.length()!=1 && isSegOnly) {
        QMessageBox::information(NULL, "错误", "请设置词性分隔符，长度为1！");
        return;
    }
    char para_c = para.toStdString().c_str()[0];
    //将文本输出到in.txt
    std::ofstream fout("in.txt");
    QString iText = ui->plainTextEdit->toPlainText();
    fout << iText.toStdString();
    fout.close();
    //处理文本
    THULAC *thc = new THULAC();
    thc->IOtoTHULAC(filePath.toStdString().c_str(), isT2S, !isSegOnly, isFilter, para_c);
    //从out.txt得到文本
    std::string oText = "";
    std::ifstream fin("out.txt");
    std::string tmp = "";
    while(std::getline(fin, tmp))
    {
        oText += tmp;
        oText += '\n';
    }
    QString qs_oText = oText.c_str();
    ui->label->setWordWrap(true);
    ui->label->setAlignment(Qt::AlignTop);
    ui->label->setText(qs_oText);
    ui->label->setScaledContents(true);
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("模型位置"));
    fileDialog->setDirectory(".");
    QString fpath = fileDialog->getExistingDirectory();
    std::cout << fpath.toStdString() << std::endl;
    if(fpath.length() != 0) {
        QMessageBox::information(NULL, tr("路径"), fpath);
        ui->pathLabel->setText(fpath);
    }
    else {
        QMessageBox::information(NULL, tr("错误"), "您没有选择任何文件夹！");
    }
}


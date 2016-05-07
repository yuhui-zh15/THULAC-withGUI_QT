#include "about.h"
#include "ui_about.h"
#include <qpixmap.h>

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    QPixmap pic;
    pic.load("1.png");
    ui->label_11->setPixmap(pic);
    ui->label_11->setScaledContents(true);
}

About::~About()
{
    delete ui;
}

void About::on_pushButton_clicked()
{
    this -> ~About();
}

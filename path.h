#ifndef PATH_H
#define PATH_H

#include <QDialog>

namespace Ui {
class Path;
}

class Path : public QDialog
{
    Q_OBJECT

public:
    explicit Path(QWidget *parent = 0);
    ~Path();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Path *ui;
};

#endif // PATH_H

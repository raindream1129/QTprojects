#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_LDN_LE_returnPressed();

    void on_OK_Btn_clicked();

private:
    Ui::MainWindow *ui;

    void save2Excel(QStringList&);

    void save2Db(QStringList&);

    QString sFileName;
};

#endif // MAINWINDOW_H

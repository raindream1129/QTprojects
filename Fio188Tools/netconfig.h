#ifndef NETCONFIG_H
#define NETCONFIG_H

#include <QWidget>
#include "cjt188_general.h"
#include <QTimer>

namespace Ui {
class NetConfig;
}

class NetConfig : public QWidget
{
    Q_OBJECT

public:
    explicit NetConfig(QWidget *parent = 0);
    ~NetConfig();

private slots:
    void on_NETBTN_clicked();

    void TTimeout();

private:
    Ui::NetConfig *ui;
    QString IPtoString(QString );
    QString PORTtostring(QString );

    bool IPFalg;
    bool PortFlag;
    bool IPChanged;
    bool portChanged;

    CJT188Obj cjt188ob_tmp;

    QTimer     *Timer;
    int i;

signals:

    void NetCfgSet(CJT188Obj);
};

#endif // NETCONFIG_H

#ifndef RDCFG_H
#define RDCFG_H

#include <QWidget>

class RdCFG : public QWidget
{
    Q_OBJECT
public:
    explicit RdCFG(QWidget *parent = 0);

    int RdCom();

signals:

public slots:
};

#endif // RDCFG_H

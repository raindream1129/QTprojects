/********************************************************************************
** Form generated from reading UI file 'netconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETCONFIG_H
#define UI_NETCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetConfig
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *LEIP1;
    QLabel *label_2;
    QLineEdit *LEPT2;
    QLineEdit *LEPT1;
    QLineEdit *LEIP2;
    QLineEdit *LEIP3;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *LEPT3;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_8;
    QLineEdit *LEIP4;
    QLabel *label_9;
    QLineEdit *LEPT4;
    QPushButton *NETBTN;

    void setupUi(QWidget *NetConfig)
    {
        if (NetConfig->objectName().isEmpty())
            NetConfig->setObjectName(QStringLiteral("NetConfig"));
        NetConfig->resize(378, 230);
        gridLayoutWidget = new QWidget(NetConfig);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 351, 161));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        LEIP1 = new QLineEdit(gridLayoutWidget);
        LEIP1->setObjectName(QStringLiteral("LEIP1"));

        gridLayout->addWidget(LEIP1, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        LEPT2 = new QLineEdit(gridLayoutWidget);
        LEPT2->setObjectName(QStringLiteral("LEPT2"));

        gridLayout->addWidget(LEPT2, 1, 3, 1, 1);

        LEPT1 = new QLineEdit(gridLayoutWidget);
        LEPT1->setObjectName(QStringLiteral("LEPT1"));

        gridLayout->addWidget(LEPT1, 0, 3, 1, 1);

        LEIP2 = new QLineEdit(gridLayoutWidget);
        LEIP2->setObjectName(QStringLiteral("LEIP2"));

        gridLayout->addWidget(LEIP2, 1, 1, 1, 1);

        LEIP3 = new QLineEdit(gridLayoutWidget);
        LEIP3->setObjectName(QStringLiteral("LEIP3"));

        gridLayout->addWidget(LEIP3, 2, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        LEPT3 = new QLineEdit(gridLayoutWidget);
        LEPT3->setObjectName(QStringLiteral("LEPT3"));

        gridLayout->addWidget(LEPT3, 2, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        LEIP4 = new QLineEdit(gridLayoutWidget);
        LEIP4->setObjectName(QStringLiteral("LEIP4"));

        gridLayout->addWidget(LEIP4, 3, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 3, 2, 1, 1);

        LEPT4 = new QLineEdit(gridLayoutWidget);
        LEPT4->setObjectName(QStringLiteral("LEPT4"));

        gridLayout->addWidget(LEPT4, 3, 3, 1, 1);

        NETBTN = new QPushButton(NetConfig);
        NETBTN->setObjectName(QStringLiteral("NETBTN"));
        NETBTN->setGeometry(QRect(290, 190, 81, 31));
        QWidget::setTabOrder(LEIP1, LEPT1);
        QWidget::setTabOrder(LEPT1, LEIP2);
        QWidget::setTabOrder(LEIP2, LEPT2);
        QWidget::setTabOrder(LEPT2, LEIP3);
        QWidget::setTabOrder(LEIP3, LEPT3);
        QWidget::setTabOrder(LEPT3, LEIP4);
        QWidget::setTabOrder(LEIP4, LEPT4);
        QWidget::setTabOrder(LEPT4, NETBTN);

        retranslateUi(NetConfig);

        QMetaObject::connectSlotsByName(NetConfig);
    } // setupUi

    void retranslateUi(QWidget *NetConfig)
    {
        NetConfig->setWindowTitle(QApplication::translate("NetConfig", "Form", 0));
        label_6->setText(QApplication::translate("NetConfig", "\345\215\207\347\272\247\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", 0));
        label_2->setText(QApplication::translate("NetConfig", "\345\272\224\347\224\250\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", 0));
        label_4->setText(QApplication::translate("NetConfig", "\345\272\224\347\224\250\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", 0));
        label_3->setText(QApplication::translate("NetConfig", "\345\215\207\347\272\247\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        label_5->setText(QApplication::translate("NetConfig", "\345\244\207\344\273\275\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        label->setText(QApplication::translate("NetConfig", "\345\272\224\347\224\250\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        label_8->setText(QApplication::translate("NetConfig", "\345\271\263\345\217\260\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", 0));
        label_9->setText(QApplication::translate("NetConfig", "\345\271\263\345\217\260\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", 0));
        NETBTN->setText(QApplication::translate("NetConfig", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class NetConfig: public Ui_NetConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETCONFIG_H

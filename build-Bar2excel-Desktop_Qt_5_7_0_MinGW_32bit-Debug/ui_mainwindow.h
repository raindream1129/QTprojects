/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_3;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *Operator_LE;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *WorkOder_LE;
    QPushButton *OK_Btn;
    QLineEdit *LDN_LE;
    QTextEdit *All_LDN_LE;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(227, 297);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 90, 31, 21));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 201, 71));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Operator_LE = new QLineEdit(gridLayoutWidget);
        Operator_LE->setObjectName(QStringLiteral("Operator_LE"));
        Operator_LE->setEnabled(false);

        gridLayout->addWidget(Operator_LE, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        WorkOder_LE = new QLineEdit(gridLayoutWidget);
        WorkOder_LE->setObjectName(QStringLiteral("WorkOder_LE"));
        WorkOder_LE->setEnabled(false);

        gridLayout->addWidget(WorkOder_LE, 1, 1, 1, 1);

        OK_Btn = new QPushButton(centralWidget);
        OK_Btn->setObjectName(QStringLiteral("OK_Btn"));
        OK_Btn->setGeometry(QRect(140, 110, 75, 23));
        LDN_LE = new QLineEdit(centralWidget);
        LDN_LE->setObjectName(QStringLiteral("LDN_LE"));
        LDN_LE->setGeometry(QRect(10, 110, 113, 20));
        All_LDN_LE = new QTextEdit(centralWidget);
        All_LDN_LE->setObjectName(QStringLiteral("All_LDN_LE"));
        All_LDN_LE->setGeometry(QRect(10, 140, 201, 121));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(LDN_LE, Operator_LE);
        QWidget::setTabOrder(Operator_LE, OK_Btn);
        QWidget::setTabOrder(OK_Btn, WorkOder_LE);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\273\252\350\241\250\347\274\226\345\217\267\345\257\274\345\205\245\345\267\245\345\205\267", 0));
        label_3->setText(QApplication::translate("MainWindow", "LDN", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\223\215\344\275\234\345\221\230\345\217\267", 0));
        label->setText(QApplication::translate("MainWindow", "\345\267\245\344\275\234\344\273\244", 0));
        OK_Btn->setText(QApplication::translate("MainWindow", "\345\256\214\346\210\220", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

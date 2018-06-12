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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *Port_box;
    QPushButton *Open_Port;
    QPushButton *Close_Port;
    QLabel *label_3;
    QLineEdit *APP_IP;
    QLabel *label_5;
    QLineEdit *Test_IP;
    QLabel *label_4;
    QLineEdit *APP_Port;
    QLabel *label_6;
    QLineEdit *Test_Port;
    QTextEdit *txtLog;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_10;
    QComboBox *SupportCB;
    QLineEdit *LDN_LE;
    QLabel *label_2;
    QLabel *label_8;
    QLineEdit *Backup_Port;
    QLabel *label_7;
    QLineEdit *Backup_IP;
    QLineEdit *AllFlowLE;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1082, 402);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        Port_box = new QComboBox(frame);
        Port_box->setObjectName(QStringLiteral("Port_box"));

        horizontalLayout->addWidget(Port_box);


        verticalLayout->addLayout(horizontalLayout);

        Open_Port = new QPushButton(frame);
        Open_Port->setObjectName(QStringLiteral("Open_Port"));
        Open_Port->setEnabled(true);

        verticalLayout->addWidget(Open_Port);

        Close_Port = new QPushButton(frame);
        Close_Port->setObjectName(QStringLiteral("Close_Port"));

        verticalLayout->addWidget(Close_Port);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        APP_IP = new QLineEdit(frame);
        APP_IP->setObjectName(QStringLiteral("APP_IP"));

        gridLayout->addWidget(APP_IP, 1, 2, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 3, 1, 1);

        Test_IP = new QLineEdit(frame);
        Test_IP->setObjectName(QStringLiteral("Test_IP"));

        gridLayout->addWidget(Test_IP, 1, 4, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        APP_Port = new QLineEdit(frame);
        APP_Port->setObjectName(QStringLiteral("APP_Port"));

        gridLayout->addWidget(APP_Port, 2, 2, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 3, 1, 1);

        Test_Port = new QLineEdit(frame);
        Test_Port->setObjectName(QStringLiteral("Test_Port"));

        gridLayout->addWidget(Test_Port, 2, 4, 1, 1);

        txtLog = new QTextEdit(frame);
        txtLog->setObjectName(QStringLiteral("txtLog"));

        gridLayout->addWidget(txtLog, 3, 2, 1, 3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 62, 14);"));

        verticalLayout_2->addWidget(pushButton_2);


        gridLayout->addLayout(verticalLayout_2, 3, 6, 1, 1);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 0, 1, 1, 1);

        SupportCB = new QComboBox(frame);
        SupportCB->setObjectName(QStringLiteral("SupportCB"));

        gridLayout->addWidget(SupportCB, 0, 2, 1, 1);

        LDN_LE = new QLineEdit(frame);
        LDN_LE->setObjectName(QStringLiteral("LDN_LE"));

        gridLayout->addWidget(LDN_LE, 0, 4, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 2, 5, 1, 1);

        Backup_Port = new QLineEdit(frame);
        Backup_Port->setObjectName(QStringLiteral("Backup_Port"));

        gridLayout->addWidget(Backup_Port, 2, 6, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 1, 5, 1, 1);

        Backup_IP = new QLineEdit(frame);
        Backup_IP->setObjectName(QStringLiteral("Backup_IP"));

        gridLayout->addWidget(Backup_IP, 1, 6, 1, 1);

        AllFlowLE = new QLineEdit(frame);
        AllFlowLE->setObjectName(QStringLiteral("AllFlowLE"));
        AllFlowLE->setEnabled(false);
        AllFlowLE->setStyleSheet(QStringLiteral("background-color: rgb(255, 161, 197);"));

        gridLayout->addWidget(AllFlowLE, 0, 6, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243", 0));
        Open_Port->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        Close_Port->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\272\224\347\224\250\346\234\215\345\212\241\345\231\250IP", 0));
        APP_IP->setText(QApplication::translate("MainWindow", "101.89.201.204", 0));
        label_5->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\346\234\215\345\212\241\345\231\250IP", 0));
        Test_IP->setText(QApplication::translate("MainWindow", "101.89.201.204", 0));
        label_4->setText(QApplication::translate("MainWindow", "\345\272\224\347\224\250\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", 0));
        APP_Port->setText(QApplication::translate("MainWindow", "2239", 0));
        label_6->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", 0));
        Test_Port->setText(QApplication::translate("MainWindow", "2239", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\344\270\200\351\224\256\346\265\213\350\257\225", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\347\264\247\346\200\245\345\201\234\346\255\242", 0));
        label_10->setText(QApplication::translate("MainWindow", "\350\277\220\350\220\245\345\225\206", 0));
        SupportCB->clear();
        SupportCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\255\345\233\275\347\247\273\345\212\250", 0)
         << QApplication::translate("MainWindow", "\344\270\255\345\233\275\350\201\224\351\200\232", 0)
         << QApplication::translate("MainWindow", "\344\270\255\345\233\275\347\224\265\344\277\241", 0)
        );
        label_2->setText(QApplication::translate("MainWindow", "\344\273\252\350\241\250\347\274\226\345\217\267", 0));
        label_8->setText(QApplication::translate("MainWindow", "\345\244\207\344\273\275\346\234\215\345\212\241\345\231\250port", 0));
        Backup_Port->setText(QApplication::translate("MainWindow", "0", 0));
        label_7->setText(QApplication::translate("MainWindow", "\345\244\207\344\273\275\346\234\215\345\212\241\345\231\250IP", 0));
        Backup_IP->setText(QApplication::translate("MainWindow", "0.0.0.0", 0));
        AllFlowLE->setText(QApplication::translate("MainWindow", "\347\264\257\347\247\257\351\207\217", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

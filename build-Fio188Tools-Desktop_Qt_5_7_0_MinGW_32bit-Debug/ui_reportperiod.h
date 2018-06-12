/********************************************************************************
** Form generated from reading UI file 'reportperiod.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTPERIOD_H
#define UI_REPORTPERIOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportPeriod
{
public:
    QGridLayout *gridLayout_8;
    QFrame *frame;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLineEdit *lineERdCycle;
    QLabel *label_4;
    QLabel *label;
    QPushButton *ACC_SAMP_BTN;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QLabel *label_26;
    QLineEdit *lineETmpSmplF;
    QLabel *label_27;
    QPushButton *TMP_SAMP_BTN;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_15;
    QDateTimeEdit *StartRpTime;
    QLabel *label_6;
    QLineEdit *lineEPushCyc;
    QLabel *label_3;
    QLabel *label_7;
    QLineEdit *lineEUploadTout;
    QLabel *label_9;
    QLabel *label_8;
    QLineEdit *lineReT;
    QPushButton *PushByNetBTN;
    QLabel *label_21;
    QLabel *label_19;

    void setupUi(QWidget *ReportPeriod)
    {
        if (ReportPeriod->objectName().isEmpty())
            ReportPeriod->setObjectName(QStringLiteral("ReportPeriod"));
        ReportPeriod->resize(439, 428);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ReportPeriod->sizePolicy().hasHeightForWidth());
        ReportPeriod->setSizePolicy(sizePolicy);
        gridLayout_8 = new QGridLayout(ReportPeriod);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        frame = new QFrame(ReportPeriod);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        groupBox_4 = new QGroupBox(frame);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        groupBox_4->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineERdCycle = new QLineEdit(groupBox_4);
        lineERdCycle->setObjectName(QStringLiteral("lineERdCycle"));
        sizePolicy.setHeightForWidth(lineERdCycle->sizePolicy().hasHeightForWidth());
        lineERdCycle->setSizePolicy(sizePolicy);
        lineERdCycle->setMinimumSize(QSize(0, 0));
        lineERdCycle->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineERdCycle, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        ACC_SAMP_BTN = new QPushButton(groupBox_4);
        ACC_SAMP_BTN->setObjectName(QStringLiteral("ACC_SAMP_BTN"));
        sizePolicy.setHeightForWidth(ACC_SAMP_BTN->sizePolicy().hasHeightForWidth());
        ACC_SAMP_BTN->setSizePolicy(sizePolicy);

        gridLayout->addWidget(ACC_SAMP_BTN, 0, 3, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_4, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(frame);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        sizePolicy.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy);
        groupBox_5->setFont(font);
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_26 = new QLabel(groupBox_5);
        label_26->setObjectName(QStringLiteral("label_26"));
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);
        label_26->setFont(font1);

        gridLayout_2->addWidget(label_26, 0, 2, 1, 1);

        lineETmpSmplF = new QLineEdit(groupBox_5);
        lineETmpSmplF->setObjectName(QStringLiteral("lineETmpSmplF"));
        sizePolicy.setHeightForWidth(lineETmpSmplF->sizePolicy().hasHeightForWidth());
        lineETmpSmplF->setSizePolicy(sizePolicy);
        lineETmpSmplF->setMinimumSize(QSize(0, 0));
        lineETmpSmplF->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(lineETmpSmplF, 0, 1, 1, 1);

        label_27 = new QLabel(groupBox_5);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setFont(font1);

        gridLayout_2->addWidget(label_27, 0, 0, 1, 1);

        TMP_SAMP_BTN = new QPushButton(groupBox_5);
        TMP_SAMP_BTN->setObjectName(QStringLiteral("TMP_SAMP_BTN"));
        sizePolicy.setHeightForWidth(TMP_SAMP_BTN->sizePolicy().hasHeightForWidth());
        TMP_SAMP_BTN->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(TMP_SAMP_BTN, 0, 3, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_5, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        label_15->setFont(font2);

        gridLayout_3->addWidget(label_15, 0, 0, 1, 1);

        StartRpTime = new QDateTimeEdit(groupBox_3);
        StartRpTime->setObjectName(QStringLiteral("StartRpTime"));
        sizePolicy.setHeightForWidth(StartRpTime->sizePolicy().hasHeightForWidth());
        StartRpTime->setSizePolicy(sizePolicy);
        StartRpTime->setMinimumSize(QSize(0, 0));
        StartRpTime->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        StartRpTime->setFont(font3);
        StartRpTime->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));
        StartRpTime->setCalendarPopup(true);

        gridLayout_3->addWidget(StartRpTime, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font1);

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        lineEPushCyc = new QLineEdit(groupBox_3);
        lineEPushCyc->setObjectName(QStringLiteral("lineEPushCyc"));
        sizePolicy.setHeightForWidth(lineEPushCyc->sizePolicy().hasHeightForWidth());
        lineEPushCyc->setSizePolicy(sizePolicy);
        lineEPushCyc->setMinimumSize(QSize(0, 0));
        lineEPushCyc->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(lineEPushCyc, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout_3->addWidget(label_3, 1, 2, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font1);

        gridLayout_3->addWidget(label_7, 2, 0, 1, 1);

        lineEUploadTout = new QLineEdit(groupBox_3);
        lineEUploadTout->setObjectName(QStringLiteral("lineEUploadTout"));
        sizePolicy.setHeightForWidth(lineEUploadTout->sizePolicy().hasHeightForWidth());
        lineEUploadTout->setSizePolicy(sizePolicy);
        lineEUploadTout->setMinimumSize(QSize(0, 0));
        lineEUploadTout->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(lineEUploadTout, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        gridLayout_3->addWidget(label_9, 2, 2, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setFont(font1);

        gridLayout_3->addWidget(label_8, 3, 0, 1, 1);

        lineReT = new QLineEdit(groupBox_3);
        lineReT->setObjectName(QStringLiteral("lineReT"));
        sizePolicy.setHeightForWidth(lineReT->sizePolicy().hasHeightForWidth());
        lineReT->setSizePolicy(sizePolicy);
        lineReT->setMinimumSize(QSize(0, 0));
        lineReT->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(lineReT, 3, 1, 1, 1);

        PushByNetBTN = new QPushButton(groupBox_3);
        PushByNetBTN->setObjectName(QStringLiteral("PushByNetBTN"));
        sizePolicy.setHeightForWidth(PushByNetBTN->sizePolicy().hasHeightForWidth());
        PushByNetBTN->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(PushByNetBTN, 4, 2, 1, 1);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        gridLayout_3->addWidget(label_21, 3, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_3, 2, 0, 1, 1);

        label_19 = new QLabel(frame);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setScaledContents(false);
        label_19->setWordWrap(true);

        gridLayout_7->addWidget(label_19, 3, 0, 1, 1);


        gridLayout_8->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(ReportPeriod);

        QMetaObject::connectSlotsByName(ReportPeriod);
    } // setupUi

    void retranslateUi(QWidget *ReportPeriod)
    {
        ReportPeriod->setWindowTitle(QApplication::translate("ReportPeriod", "Form", 0));
        groupBox_4->setTitle(QApplication::translate("ReportPeriod", "\347\264\257\345\212\240\345\231\250\351\207\207\346\240\267\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        label_4->setText(QApplication::translate("ReportPeriod", "\351\207\207\346\240\267\345\221\250\346\234\237\357\274\232", 0));
        label->setText(QApplication::translate("ReportPeriod", "\345\210\206\351\222\237", 0));
        ACC_SAMP_BTN->setText(QApplication::translate("ReportPeriod", "\347\241\256\345\256\232", 0));
        groupBox_5->setTitle(QApplication::translate("ReportPeriod", "\346\270\251\345\272\246\351\207\207\346\240\267\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        label_26->setText(QApplication::translate("ReportPeriod", "\345\210\206\351\222\237", 0));
        label_27->setText(QApplication::translate("ReportPeriod", "\346\270\251\345\272\246\351\207\207\346\240\267\351\242\221\347\216\207\357\274\232", 0));
        TMP_SAMP_BTN->setText(QApplication::translate("ReportPeriod", "\347\241\256\345\256\232", 0));
        groupBox_3->setTitle(QApplication::translate("ReportPeriod", "\347\275\221\347\273\234\344\270\212\346\212\245\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        label_15->setText(QApplication::translate("ReportPeriod", "\345\274\200\345\247\213\344\270\212\346\212\245\346\227\266\351\227\264\357\274\232", 0));
        StartRpTime->setDisplayFormat(QApplication::translate("ReportPeriod", "yyyy-MM-dd HH:mm:ss", 0));
        label_6->setText(QApplication::translate("ReportPeriod", "\344\270\212\346\212\245\345\221\250\346\234\237\357\274\232", 0));
        label_3->setText(QApplication::translate("ReportPeriod", "\345\260\217\346\227\266", 0));
        label_7->setText(QApplication::translate("ReportPeriod", "\344\270\212\346\212\245\350\266\205\346\227\266\357\274\232", 0));
        label_9->setText(QApplication::translate("ReportPeriod", "\347\247\222", 0));
        label_8->setText(QApplication::translate("ReportPeriod", "\351\207\215\344\274\240\346\254\241\346\225\260\357\274\232", 0));
        PushByNetBTN->setText(QApplication::translate("ReportPeriod", "\347\241\256\345\256\232", 0));
        label_21->setText(QApplication::translate("ReportPeriod", "\346\254\241", 0));
        label_19->setText(QApplication::translate("ReportPeriod", "\346\263\250\346\204\217\357\274\2321.\347\273\223\346\235\237\346\227\266\351\227\264\345\222\214\345\274\200\345\247\213\346\227\266\351\227\264\344\271\213\351\227\264\347\232\204\346\227\266\351\227\264\345\267\256\344\270\215\350\203\275\350\266\205\350\277\20724\345\260\217\346\227\266;2.\351\207\215\344\274\240\346\254\241\346\225\260\345\260\217\344\272\216\347\255\211\344\272\2163\346\254\241;3.\347\275\221\347\273\234\344\270\212\346\212\245\345\221\250\346\234\237\346\234\211\346\225\210\345\200\274\344\270\27224\347\232\204\347\272\246\346\225\260\345\217\21224*(2-7)\347\232\204\346\225\264\346\225\260\345\200\215\357\274\214\350\214\203\345\233\264[1-24];4.\347\264\257\345\212\240\345\231\250\351\207\207\346\240\267\344\270\216\346\270\251\345\272\246\351\207\207\346\240\267\345\221\250\346\234\237\346\234\211\346\225\210\345\200\274\344\270\27260\347\232\204\346\225\264\346\225\260\345\200\215\357\274\214\350\214\203\345\233\264[60-60*24]", 0));
    } // retranslateUi

};

namespace Ui {
    class ReportPeriod: public Ui_ReportPeriod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTPERIOD_H

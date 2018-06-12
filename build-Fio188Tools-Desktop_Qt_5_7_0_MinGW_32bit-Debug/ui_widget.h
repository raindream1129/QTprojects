/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_14;
    QFrame *frame;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_2;
    QComboBox *CBComMeter;
    QLabel *label_9;
    QComboBox *CBBaudMeter;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_7;
    QComboBox *CBParityMeter;
    QPushButton *BtnConn;
    QComboBox *CBDataMeter;
    QLabel *label_6;
    QComboBox *CBStopMeter;
    QTextEdit *txtLog;
    QFrame *frame_2;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *label_27;
    QPushButton *pushButton_2;
    QPushButton *BtnSetT;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label;
    QPushButton *RdReportPeriodBtn;
    QPushButton *SetLDN;
    QPushButton *BtnRDAddr;
    QLineEdit *LetSn;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QLabel *label_39;
    QLineEdit *Device_timeLE;
    QLabel *label_13;
    QComboBox *ModleChgCBB;
    QPushButton *ModleBTN;
    QLabel *label_23;
    QLineEdit *AllFlowLE;
    QLabel *label_4;
    QLineEdit *lineEVTh;
    QLabel *label_3;
    QPushButton *BtnVth;
    QLabel *label_14;
    QLineEdit *SYS_ST_LE;
    QLabel *label_18;
    QLineEdit *MAX_FLOW_LE;
    QLabel *label_24;
    QPushButton *MaxFlowBTN;
    QLabel *label_5;
    QLineEdit *lineEV;
    QLabel *label_20;
    QLineEdit *Min_Flow_LE;
    QLabel *label_25;
    QPushButton *MinFlow_BTN;
    QLabel *label_19;
    QLineEdit *WorkingT_LE;
    QLabel *label_35;
    QLineEdit *IdledTs_LE;
    QLabel *label_38;
    QLabel *label_17;
    QLineEdit *SEV_Version_LE;
    QLabel *label_21;
    QLineEdit *IdleT_LE;
    QLabel *label_26;
    QPushButton *IdleT_BTN;
    QLabel *label_22;
    QLineEdit *Temp_LE;
    QLabel *label_15;
    QLineEdit *Alarm_Bal_LE;
    QPushButton *AlarmFlow_BTN;
    QLabel *label_28;
    QLineEdit *DropTimeLE;
    QLabel *label_16;
    QLineEdit *Alarm_Gas_LE;
    QLabel *label_10;
    QPushButton *Balance_BTN;
    QLabel *label_40;
    QLabel *label_41;
    QLineEdit *lineEdit;
    QLabel *label_42;
    QLabel *label_43;
    QLineEdit *lineEdit_2;
    QFrame *frame_3;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_15;
    QGridLayout *gridLayout_3;
    QPushButton *BtnOpenV;
    QPushButton *BtnClsV;
    QLabel *label_11;
    QGridLayout *gridLayout_4;
    QPushButton *Check_Normal_BTN;
    QPushButton *pushButton_3;
    QPushButton *Clear_NormalBTN;
    QPushButton *pushButton_5;
    QDateTimeEdit *Wakeup_time_LE;
    QSpacerItem *verticalSpacer;
    QFrame *frame_4;
    QGridLayout *gridLayout_13;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_5;
    QLabel *label_37;
    QLabel *label_34;
    QLineEdit *BackUpSevPortLE;
    QLineEdit *BackUpIPLE;
    QLineEdit *AppSevPortLE;
    QLineEdit *AvoidPeakAbleST;
    QLabel *label_33;
    QLineEdit *AvoidPeakTimeLE;
    QLabel *label_32;
    QLabel *label_36;
    QPushButton *AvoidPeakClouseBTN;
    QPushButton *PLMN_BTN;
    QPushButton *APPSevIPBTN;
    QPushButton *BACKSevIPBTN;
    QPushButton *AvoidPeakOpenBTN;
    QLabel *label_31;
    QLineEdit *BandWidthLE;
    QLineEdit *AppSevIPLE;
    QLineEdit *PLMN_LE;
    QLabel *label_29;
    QPushButton *BandWidthBTN;
    QLabel *label_30;
    QGridLayout *gridLayout_12;
    QLabel *ModleInf;
    QPushButton *pushButton_4;
    QTextEdit *AbnormalST;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->setEnabled(true);
        Widget->resize(1025, 441);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setContextMenuPolicy(Qt::ActionsContextMenu);
        Widget->setAutoFillBackground(true);
        gridLayout_14 = new QGridLayout(Widget);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        frame = new QFrame(Widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(180, 250));
        groupBox->setMaximumSize(QSize(210, 16777215));
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        CBComMeter = new QComboBox(groupBox);
        CBComMeter->setObjectName(QStringLiteral("CBComMeter"));
        CBComMeter->setEnabled(true);
        CBComMeter->setMinimumSize(QSize(80, 0));
        CBComMeter->setMaximumSize(QSize(60, 16777215));
        CBComMeter->setLayoutDirection(Qt::LeftToRight);
        CBComMeter->setEditable(false);

        gridLayout_2->addWidget(CBComMeter, 0, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMaximumSize(QSize(70, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        CBBaudMeter = new QComboBox(groupBox);
        CBBaudMeter->setObjectName(QStringLiteral("CBBaudMeter"));
        CBBaudMeter->setMinimumSize(QSize(80, 0));
        CBBaudMeter->setMaximumSize(QSize(60, 16777215));
        CBBaudMeter->setLayoutDirection(Qt::LeftToRight);
        CBBaudMeter->setMaxVisibleItems(10);

        gridLayout_2->addWidget(CBBaudMeter, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMaximumSize(QSize(70, 16777215));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 4, 0, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMinimumSize(QSize(60, 0));
        label_12->setMaximumSize(QSize(60, 16777215));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMaximumSize(QSize(70, 16777215));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 3, 0, 1, 1);

        CBParityMeter = new QComboBox(groupBox);
        CBParityMeter->setObjectName(QStringLiteral("CBParityMeter"));
        CBParityMeter->setMinimumSize(QSize(80, 0));
        CBParityMeter->setMaximumSize(QSize(70, 16777215));

        gridLayout_2->addWidget(CBParityMeter, 3, 1, 1, 1);

        BtnConn = new QPushButton(groupBox);
        BtnConn->setObjectName(QStringLiteral("BtnConn"));
        BtnConn->setMinimumSize(QSize(80, 30));

        gridLayout_2->addWidget(BtnConn, 5, 0, 1, 2);

        CBDataMeter = new QComboBox(groupBox);
        CBDataMeter->setObjectName(QStringLiteral("CBDataMeter"));
        CBDataMeter->setMinimumSize(QSize(80, 0));
        CBDataMeter->setMaximumSize(QSize(50, 16777215));
        CBDataMeter->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(CBDataMeter, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(60, 0));
        label_6->setMaximumSize(QSize(50, 16777215));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        CBStopMeter = new QComboBox(groupBox);
        CBStopMeter->setObjectName(QStringLiteral("CBStopMeter"));
        CBStopMeter->setMinimumSize(QSize(0, 0));
        CBStopMeter->setMaximumSize(QSize(80, 16777215));

        gridLayout_2->addWidget(CBStopMeter, 4, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_8->addWidget(groupBox, 0, 0, 1, 1);

        txtLog = new QTextEdit(frame);
        txtLog->setObjectName(QStringLiteral("txtLog"));
        txtLog->setMaximumSize(QSize(210, 16777215));
        txtLog->setStyleSheet(QStringLiteral("background-color: rgb(239, 239, 239);"));
        txtLog->setReadOnly(true);

        gridLayout_8->addWidget(txtLog, 1, 0, 1, 1);


        gridLayout_14->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(Widget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frame_2);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(0, 0));
        pushButton->setMaximumSize(QSize(16777215, 16777215));
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 1, 5, 1, 1);

        label_27 = new QLabel(frame_2);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setMaximumSize(QSize(20, 16777215));
        label_27->setStyleSheet(QStringLiteral("border-image: url(:/aa.jpg);"));

        gridLayout->addWidget(label_27, 1, 4, 1, 1);

        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        pushButton_2->setFont(font1);
        pushButton_2->setAutoFillBackground(true);
        pushButton_2->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(pushButton_2, 1, 3, 1, 1);

        BtnSetT = new QPushButton(frame_2);
        BtnSetT->setObjectName(QStringLiteral("BtnSetT"));
        sizePolicy.setHeightForWidth(BtnSetT->sizePolicy().hasHeightForWidth());
        BtnSetT->setSizePolicy(sizePolicy);
        BtnSetT->setFont(font);

        gridLayout->addWidget(BtnSetT, 1, 2, 1, 1);

        dateTimeEdit = new QDateTimeEdit(frame_2);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        sizePolicy.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy);
        dateTimeEdit->setKeyboardTracking(true);
        dateTimeEdit->setDateTime(QDateTime(QDate(2017, 12, 28), QTime(7, 0, 0)));
        dateTimeEdit->setCalendarPopup(false);
        dateTimeEdit->setCurrentSectionIndex(0);
        dateTimeEdit->setTimeSpec(Qt::UTC);

        gridLayout->addWidget(dateTimeEdit, 1, 1, 1, 1);

        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        RdReportPeriodBtn = new QPushButton(frame_2);
        RdReportPeriodBtn->setObjectName(QStringLiteral("RdReportPeriodBtn"));
        sizePolicy.setHeightForWidth(RdReportPeriodBtn->sizePolicy().hasHeightForWidth());
        RdReportPeriodBtn->setSizePolicy(sizePolicy);
        RdReportPeriodBtn->setMinimumSize(QSize(0, 0));
        RdReportPeriodBtn->setMaximumSize(QSize(16777215, 16777215));
        RdReportPeriodBtn->setFont(font);

        gridLayout->addWidget(RdReportPeriodBtn, 0, 5, 1, 1);

        SetLDN = new QPushButton(frame_2);
        SetLDN->setObjectName(QStringLiteral("SetLDN"));
        sizePolicy.setHeightForWidth(SetLDN->sizePolicy().hasHeightForWidth());
        SetLDN->setSizePolicy(sizePolicy);
        SetLDN->setFont(font);

        gridLayout->addWidget(SetLDN, 0, 3, 1, 1);

        BtnRDAddr = new QPushButton(frame_2);
        BtnRDAddr->setObjectName(QStringLiteral("BtnRDAddr"));
        sizePolicy.setHeightForWidth(BtnRDAddr->sizePolicy().hasHeightForWidth());
        BtnRDAddr->setSizePolicy(sizePolicy);
        BtnRDAddr->setFont(font);

        gridLayout->addWidget(BtnRDAddr, 0, 2, 1, 1);

        LetSn = new QLineEdit(frame_2);
        LetSn->setObjectName(QStringLiteral("LetSn"));
        sizePolicy.setHeightForWidth(LetSn->sizePolicy().hasHeightForWidth());
        LetSn->setSizePolicy(sizePolicy);
        LetSn->setMaximumSize(QSize(123, 16777215));
        LetSn->setFont(font);
        LetSn->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LetSn, 0, 1, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(40, 16777215));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(frame_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(11);
        groupBox_3->setFont(font2);
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_39 = new QLabel(groupBox_3);
        label_39->setObjectName(QStringLiteral("label_39"));
        sizePolicy.setHeightForWidth(label_39->sizePolicy().hasHeightForWidth());
        label_39->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_39, 0, 0, 1, 1);

        Device_timeLE = new QLineEdit(groupBox_3);
        Device_timeLE->setObjectName(QStringLiteral("Device_timeLE"));
        sizePolicy.setHeightForWidth(Device_timeLE->sizePolicy().hasHeightForWidth());
        Device_timeLE->setSizePolicy(sizePolicy);
        Device_timeLE->setStyleSheet(QStringLiteral("background-color: rgb(232, 232, 232);"));

        gridLayout_7->addWidget(Device_timeLE, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_7->addWidget(label_13, 0, 2, 1, 1);

        ModleChgCBB = new QComboBox(groupBox_3);
        ModleChgCBB->setObjectName(QStringLiteral("ModleChgCBB"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ModleChgCBB->sizePolicy().hasHeightForWidth());
        ModleChgCBB->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setPointSize(10);
        ModleChgCBB->setFont(font3);

        gridLayout_7->addWidget(ModleChgCBB, 0, 3, 1, 1);

        ModleBTN = new QPushButton(groupBox_3);
        ModleBTN->setObjectName(QStringLiteral("ModleBTN"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ModleBTN->sizePolicy().hasHeightForWidth());
        ModleBTN->setSizePolicy(sizePolicy2);

        gridLayout_7->addWidget(ModleBTN, 0, 5, 1, 1);

        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_23, 1, 0, 1, 1);

        AllFlowLE = new QLineEdit(groupBox_3);
        AllFlowLE->setObjectName(QStringLiteral("AllFlowLE"));
        sizePolicy.setHeightForWidth(AllFlowLE->sizePolicy().hasHeightForWidth());
        AllFlowLE->setSizePolicy(sizePolicy);
        AllFlowLE->setStyleSheet(QStringLiteral("background-color: rgb(232, 232, 232);"));

        gridLayout_7->addWidget(AllFlowLE, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_7->addWidget(label_4, 1, 2, 1, 1);

        lineEVTh = new QLineEdit(groupBox_3);
        lineEVTh->setObjectName(QStringLiteral("lineEVTh"));
        sizePolicy.setHeightForWidth(lineEVTh->sizePolicy().hasHeightForWidth());
        lineEVTh->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(lineEVTh, 1, 3, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_3, 1, 4, 1, 1);

        BtnVth = new QPushButton(groupBox_3);
        BtnVth->setObjectName(QStringLiteral("BtnVth"));
        sizePolicy.setHeightForWidth(BtnVth->sizePolicy().hasHeightForWidth());
        BtnVth->setSizePolicy(sizePolicy);
        BtnVth->setMinimumSize(QSize(0, 0));
        BtnVth->setMaximumSize(QSize(100, 25));

        gridLayout_7->addWidget(BtnVth, 1, 5, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_14, 2, 0, 1, 1);

        SYS_ST_LE = new QLineEdit(groupBox_3);
        SYS_ST_LE->setObjectName(QStringLiteral("SYS_ST_LE"));
        sizePolicy.setHeightForWidth(SYS_ST_LE->sizePolicy().hasHeightForWidth());
        SYS_ST_LE->setSizePolicy(sizePolicy);
        SYS_ST_LE->setMinimumSize(QSize(0, 0));
        SYS_ST_LE->setStyleSheet(QStringLiteral("background-color: rgb(232, 232, 232);"));
        SYS_ST_LE->setReadOnly(true);

        gridLayout_7->addWidget(SYS_ST_LE, 2, 1, 1, 1);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_18, 2, 2, 1, 1);

        MAX_FLOW_LE = new QLineEdit(groupBox_3);
        MAX_FLOW_LE->setObjectName(QStringLiteral("MAX_FLOW_LE"));
        sizePolicy.setHeightForWidth(MAX_FLOW_LE->sizePolicy().hasHeightForWidth());
        MAX_FLOW_LE->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(MAX_FLOW_LE, 2, 3, 1, 1);

        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QStringLiteral("label_24"));
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_24, 2, 4, 1, 1);

        MaxFlowBTN = new QPushButton(groupBox_3);
        MaxFlowBTN->setObjectName(QStringLiteral("MaxFlowBTN"));
        sizePolicy.setHeightForWidth(MaxFlowBTN->sizePolicy().hasHeightForWidth());
        MaxFlowBTN->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(MaxFlowBTN, 2, 5, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_5, 3, 0, 1, 1);

        lineEV = new QLineEdit(groupBox_3);
        lineEV->setObjectName(QStringLiteral("lineEV"));
        sizePolicy.setHeightForWidth(lineEV->sizePolicy().hasHeightForWidth());
        lineEV->setSizePolicy(sizePolicy);
        lineEV->setMaximumSize(QSize(16777215, 16777215));
        lineEV->setStyleSheet(QStringLiteral("background-color: rgb(232, 232, 232);"));
        lineEV->setReadOnly(true);

        gridLayout_7->addWidget(lineEV, 3, 1, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_20, 3, 2, 1, 1);

        Min_Flow_LE = new QLineEdit(groupBox_3);
        Min_Flow_LE->setObjectName(QStringLiteral("Min_Flow_LE"));
        sizePolicy.setHeightForWidth(Min_Flow_LE->sizePolicy().hasHeightForWidth());
        Min_Flow_LE->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(Min_Flow_LE, 3, 3, 1, 1);

        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QStringLiteral("label_25"));
        sizePolicy.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_25, 3, 4, 1, 1);

        MinFlow_BTN = new QPushButton(groupBox_3);
        MinFlow_BTN->setObjectName(QStringLiteral("MinFlow_BTN"));
        sizePolicy.setHeightForWidth(MinFlow_BTN->sizePolicy().hasHeightForWidth());
        MinFlow_BTN->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(MinFlow_BTN, 3, 5, 1, 1);

        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_19, 4, 0, 1, 1);

        WorkingT_LE = new QLineEdit(groupBox_3);
        WorkingT_LE->setObjectName(QStringLiteral("WorkingT_LE"));
        sizePolicy.setHeightForWidth(WorkingT_LE->sizePolicy().hasHeightForWidth());
        WorkingT_LE->setSizePolicy(sizePolicy);
        WorkingT_LE->setStyleSheet(QStringLiteral("background-color: rgb(232, 232, 232);"));
        WorkingT_LE->setReadOnly(true);

        gridLayout_7->addWidget(WorkingT_LE, 4, 1, 1, 1);

        label_35 = new QLabel(groupBox_3);
        label_35->setObjectName(QStringLiteral("label_35"));
        sizePolicy.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_35, 4, 2, 1, 1);

        IdledTs_LE = new QLineEdit(groupBox_3);
        IdledTs_LE->setObjectName(QStringLiteral("IdledTs_LE"));
        sizePolicy.setHeightForWidth(IdledTs_LE->sizePolicy().hasHeightForWidth());
        IdledTs_LE->setSizePolicy(sizePolicy);
        IdledTs_LE->setStyleSheet(QStringLiteral("background-color: rgb(232, 232, 232);"));
        IdledTs_LE->setReadOnly(true);

        gridLayout_7->addWidget(IdledTs_LE, 4, 3, 1, 1);

        label_38 = new QLabel(groupBox_3);
        label_38->setObjectName(QStringLiteral("label_38"));
        sizePolicy.setHeightForWidth(label_38->sizePolicy().hasHeightForWidth());
        label_38->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_38, 4, 4, 1, 1);

        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_17, 5, 0, 1, 1);

        SEV_Version_LE = new QLineEdit(groupBox_3);
        SEV_Version_LE->setObjectName(QStringLiteral("SEV_Version_LE"));
        sizePolicy.setHeightForWidth(SEV_Version_LE->sizePolicy().hasHeightForWidth());
        SEV_Version_LE->setSizePolicy(sizePolicy);
        SEV_Version_LE->setStyleSheet(QStringLiteral("background-color: rgb(232, 232, 232);"));
        SEV_Version_LE->setReadOnly(true);

        gridLayout_7->addWidget(SEV_Version_LE, 5, 1, 1, 1);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_21, 5, 2, 1, 1);

        IdleT_LE = new QLineEdit(groupBox_3);
        IdleT_LE->setObjectName(QStringLiteral("IdleT_LE"));
        sizePolicy.setHeightForWidth(IdleT_LE->sizePolicy().hasHeightForWidth());
        IdleT_LE->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(IdleT_LE, 5, 3, 1, 1);

        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QStringLiteral("label_26"));
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_26, 5, 4, 1, 1);

        IdleT_BTN = new QPushButton(groupBox_3);
        IdleT_BTN->setObjectName(QStringLiteral("IdleT_BTN"));
        sizePolicy.setHeightForWidth(IdleT_BTN->sizePolicy().hasHeightForWidth());
        IdleT_BTN->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(IdleT_BTN, 5, 5, 1, 1);

        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QStringLiteral("label_22"));
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_22, 6, 0, 1, 1);

        Temp_LE = new QLineEdit(groupBox_3);
        Temp_LE->setObjectName(QStringLiteral("Temp_LE"));
        sizePolicy.setHeightForWidth(Temp_LE->sizePolicy().hasHeightForWidth());
        Temp_LE->setSizePolicy(sizePolicy);
        Temp_LE->setStyleSheet(QStringLiteral("background-color: rgb(232, 232, 232);"));
        Temp_LE->setReadOnly(true);

        gridLayout_7->addWidget(Temp_LE, 6, 1, 1, 1);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_15, 6, 2, 1, 1);

        Alarm_Bal_LE = new QLineEdit(groupBox_3);
        Alarm_Bal_LE->setObjectName(QStringLiteral("Alarm_Bal_LE"));
        sizePolicy.setHeightForWidth(Alarm_Bal_LE->sizePolicy().hasHeightForWidth());
        Alarm_Bal_LE->setSizePolicy(sizePolicy);
        Alarm_Bal_LE->setStyleSheet(QStringLiteral(""));
        Alarm_Bal_LE->setReadOnly(false);

        gridLayout_7->addWidget(Alarm_Bal_LE, 6, 3, 1, 1);

        AlarmFlow_BTN = new QPushButton(groupBox_3);
        AlarmFlow_BTN->setObjectName(QStringLiteral("AlarmFlow_BTN"));
        sizePolicy.setHeightForWidth(AlarmFlow_BTN->sizePolicy().hasHeightForWidth());
        AlarmFlow_BTN->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(AlarmFlow_BTN, 6, 5, 1, 1);

        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QStringLiteral("label_28"));
        sizePolicy.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_28, 7, 0, 1, 1);

        DropTimeLE = new QLineEdit(groupBox_3);
        DropTimeLE->setObjectName(QStringLiteral("DropTimeLE"));
        sizePolicy.setHeightForWidth(DropTimeLE->sizePolicy().hasHeightForWidth());
        DropTimeLE->setSizePolicy(sizePolicy);
        DropTimeLE->setStyleSheet(QStringLiteral("background-color: rgb(232, 232, 232);"));
        DropTimeLE->setReadOnly(true);

        gridLayout_7->addWidget(DropTimeLE, 7, 1, 1, 1);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_16, 7, 2, 1, 1);

        Alarm_Gas_LE = new QLineEdit(groupBox_3);
        Alarm_Gas_LE->setObjectName(QStringLiteral("Alarm_Gas_LE"));
        sizePolicy.setHeightForWidth(Alarm_Gas_LE->sizePolicy().hasHeightForWidth());
        Alarm_Gas_LE->setSizePolicy(sizePolicy);
        Alarm_Gas_LE->setStyleSheet(QStringLiteral(""));
        Alarm_Gas_LE->setReadOnly(false);

        gridLayout_7->addWidget(Alarm_Gas_LE, 7, 3, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_10, 7, 4, 1, 1);

        Balance_BTN = new QPushButton(groupBox_3);
        Balance_BTN->setObjectName(QStringLiteral("Balance_BTN"));
        sizePolicy.setHeightForWidth(Balance_BTN->sizePolicy().hasHeightForWidth());
        Balance_BTN->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(Balance_BTN, 7, 5, 1, 1);

        label_40 = new QLabel(groupBox_3);
        label_40->setObjectName(QStringLiteral("label_40"));

        gridLayout_7->addWidget(label_40, 6, 4, 1, 1);

        label_41 = new QLabel(groupBox_3);
        label_41->setObjectName(QStringLiteral("label_41"));

        gridLayout_7->addWidget(label_41, 8, 2, 1, 1);

        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_7->addWidget(lineEdit, 8, 3, 1, 1);

        label_42 = new QLabel(groupBox_3);
        label_42->setObjectName(QStringLiteral("label_42"));

        gridLayout_7->addWidget(label_42, 8, 4, 1, 1);

        label_43 = new QLabel(groupBox_3);
        label_43->setObjectName(QStringLiteral("label_43"));

        gridLayout_7->addWidget(label_43, 8, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout_7->addWidget(lineEdit_2, 8, 1, 1, 1);


        gridLayout_10->addWidget(groupBox_3, 2, 0, 1, 1);

        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_9 = new QGridLayout(frame_3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        gridLayout_15 = new QGridLayout(groupBox_2);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        BtnOpenV = new QPushButton(groupBox_2);
        BtnOpenV->setObjectName(QStringLiteral("BtnOpenV"));
        sizePolicy.setHeightForWidth(BtnOpenV->sizePolicy().hasHeightForWidth());
        BtnOpenV->setSizePolicy(sizePolicy);
        BtnOpenV->setMinimumSize(QSize(0, 0));
        BtnOpenV->setFont(font);

        gridLayout_3->addWidget(BtnOpenV, 0, 0, 1, 1);

        BtnClsV = new QPushButton(groupBox_2);
        BtnClsV->setObjectName(QStringLiteral("BtnClsV"));
        sizePolicy.setHeightForWidth(BtnClsV->sizePolicy().hasHeightForWidth());
        BtnClsV->setSizePolicy(sizePolicy);
        BtnClsV->setMinimumSize(QSize(0, 0));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        BtnClsV->setFont(font4);
        BtnClsV->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        gridLayout_3->addWidget(BtnClsV, 0, 1, 1, 1);


        gridLayout_15->addLayout(gridLayout_3, 0, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_2, 0, 0, 2, 1);

        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        gridLayout_9->addWidget(label_11, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        Check_Normal_BTN = new QPushButton(frame_3);
        Check_Normal_BTN->setObjectName(QStringLiteral("Check_Normal_BTN"));
        sizePolicy2.setHeightForWidth(Check_Normal_BTN->sizePolicy().hasHeightForWidth());
        Check_Normal_BTN->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(Check_Normal_BTN, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(frame_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(pushButton_3, 0, 0, 1, 1);

        Clear_NormalBTN = new QPushButton(frame_3);
        Clear_NormalBTN->setObjectName(QStringLiteral("Clear_NormalBTN"));
        sizePolicy2.setHeightForWidth(Clear_NormalBTN->sizePolicy().hasHeightForWidth());
        Clear_NormalBTN->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(Clear_NormalBTN, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(frame_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pushButton_5, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_4, 0, 2, 2, 1);

        Wakeup_time_LE = new QDateTimeEdit(frame_3);
        Wakeup_time_LE->setObjectName(QStringLiteral("Wakeup_time_LE"));
        sizePolicy.setHeightForWidth(Wakeup_time_LE->sizePolicy().hasHeightForWidth());
        Wakeup_time_LE->setSizePolicy(sizePolicy);
        Wakeup_time_LE->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));
        Wakeup_time_LE->setCalendarPopup(true);

        gridLayout_9->addWidget(Wakeup_time_LE, 1, 1, 1, 1);


        gridLayout_10->addWidget(frame_3, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_14->addWidget(frame_2, 0, 1, 1, 1);

        frame_4 = new QFrame(Widget);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(frame_4);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        groupBox_4 = new QGroupBox(frame_4);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_11 = new QGridLayout(groupBox_4);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_37 = new QLabel(groupBox_4);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setFont(font2);

        gridLayout_5->addWidget(label_37, 7, 0, 1, 1);

        label_34 = new QLabel(groupBox_4);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setFont(font2);

        gridLayout_5->addWidget(label_34, 3, 0, 1, 1);

        BackUpSevPortLE = new QLineEdit(groupBox_4);
        BackUpSevPortLE->setObjectName(QStringLiteral("BackUpSevPortLE"));
        sizePolicy.setHeightForWidth(BackUpSevPortLE->sizePolicy().hasHeightForWidth());
        BackUpSevPortLE->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(BackUpSevPortLE, 3, 1, 1, 1);

        BackUpIPLE = new QLineEdit(groupBox_4);
        BackUpIPLE->setObjectName(QStringLiteral("BackUpIPLE"));
        sizePolicy.setHeightForWidth(BackUpIPLE->sizePolicy().hasHeightForWidth());
        BackUpIPLE->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(BackUpIPLE, 2, 1, 1, 1);

        AppSevPortLE = new QLineEdit(groupBox_4);
        AppSevPortLE->setObjectName(QStringLiteral("AppSevPortLE"));
        sizePolicy.setHeightForWidth(AppSevPortLE->sizePolicy().hasHeightForWidth());
        AppSevPortLE->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(AppSevPortLE, 1, 1, 1, 1);

        AvoidPeakAbleST = new QLineEdit(groupBox_4);
        AvoidPeakAbleST->setObjectName(QStringLiteral("AvoidPeakAbleST"));
        sizePolicy.setHeightForWidth(AvoidPeakAbleST->sizePolicy().hasHeightForWidth());
        AvoidPeakAbleST->setSizePolicy(sizePolicy);
        AvoidPeakAbleST->setStyleSheet(QStringLiteral("background-color: rgb(232, 232, 232);"));
        AvoidPeakAbleST->setReadOnly(true);

        gridLayout_5->addWidget(AvoidPeakAbleST, 6, 1, 1, 1);

        label_33 = new QLabel(groupBox_4);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setFont(font2);

        gridLayout_5->addWidget(label_33, 2, 0, 1, 1);

        AvoidPeakTimeLE = new QLineEdit(groupBox_4);
        AvoidPeakTimeLE->setObjectName(QStringLiteral("AvoidPeakTimeLE"));
        sizePolicy.setHeightForWidth(AvoidPeakTimeLE->sizePolicy().hasHeightForWidth());
        AvoidPeakTimeLE->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(AvoidPeakTimeLE, 7, 1, 1, 1);

        label_32 = new QLabel(groupBox_4);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setFont(font2);

        gridLayout_5->addWidget(label_32, 1, 0, 1, 1);

        label_36 = new QLabel(groupBox_4);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setFont(font2);

        gridLayout_5->addWidget(label_36, 6, 0, 1, 1);

        AvoidPeakClouseBTN = new QPushButton(groupBox_4);
        AvoidPeakClouseBTN->setObjectName(QStringLiteral("AvoidPeakClouseBTN"));
        sizePolicy2.setHeightForWidth(AvoidPeakClouseBTN->sizePolicy().hasHeightForWidth());
        AvoidPeakClouseBTN->setSizePolicy(sizePolicy2);
        AvoidPeakClouseBTN->setFont(font2);

        gridLayout_5->addWidget(AvoidPeakClouseBTN, 6, 2, 1, 1);

        PLMN_BTN = new QPushButton(groupBox_4);
        PLMN_BTN->setObjectName(QStringLiteral("PLMN_BTN"));
        sizePolicy2.setHeightForWidth(PLMN_BTN->sizePolicy().hasHeightForWidth());
        PLMN_BTN->setSizePolicy(sizePolicy2);
        PLMN_BTN->setFont(font2);

        gridLayout_5->addWidget(PLMN_BTN, 5, 2, 1, 1);

        APPSevIPBTN = new QPushButton(groupBox_4);
        APPSevIPBTN->setObjectName(QStringLiteral("APPSevIPBTN"));

        gridLayout_5->addWidget(APPSevIPBTN, 1, 2, 1, 1);

        BACKSevIPBTN = new QPushButton(groupBox_4);
        BACKSevIPBTN->setObjectName(QStringLiteral("BACKSevIPBTN"));
        sizePolicy2.setHeightForWidth(BACKSevIPBTN->sizePolicy().hasHeightForWidth());
        BACKSevIPBTN->setSizePolicy(sizePolicy2);
        BACKSevIPBTN->setFont(font2);

        gridLayout_5->addWidget(BACKSevIPBTN, 3, 2, 1, 1);

        AvoidPeakOpenBTN = new QPushButton(groupBox_4);
        AvoidPeakOpenBTN->setObjectName(QStringLiteral("AvoidPeakOpenBTN"));
        sizePolicy2.setHeightForWidth(AvoidPeakOpenBTN->sizePolicy().hasHeightForWidth());
        AvoidPeakOpenBTN->setSizePolicy(sizePolicy2);
        AvoidPeakOpenBTN->setFont(font2);

        gridLayout_5->addWidget(AvoidPeakOpenBTN, 7, 2, 1, 1);

        label_31 = new QLabel(groupBox_4);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setFont(font2);

        gridLayout_5->addWidget(label_31, 0, 0, 1, 1);

        BandWidthLE = new QLineEdit(groupBox_4);
        BandWidthLE->setObjectName(QStringLiteral("BandWidthLE"));
        sizePolicy.setHeightForWidth(BandWidthLE->sizePolicy().hasHeightForWidth());
        BandWidthLE->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(BandWidthLE, 4, 1, 1, 1);

        AppSevIPLE = new QLineEdit(groupBox_4);
        AppSevIPLE->setObjectName(QStringLiteral("AppSevIPLE"));

        gridLayout_5->addWidget(AppSevIPLE, 0, 1, 1, 1);

        PLMN_LE = new QLineEdit(groupBox_4);
        PLMN_LE->setObjectName(QStringLiteral("PLMN_LE"));
        sizePolicy.setHeightForWidth(PLMN_LE->sizePolicy().hasHeightForWidth());
        PLMN_LE->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(PLMN_LE, 5, 1, 1, 1);

        label_29 = new QLabel(groupBox_4);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font2);

        gridLayout_5->addWidget(label_29, 4, 0, 1, 1);

        BandWidthBTN = new QPushButton(groupBox_4);
        BandWidthBTN->setObjectName(QStringLiteral("BandWidthBTN"));
        sizePolicy2.setHeightForWidth(BandWidthBTN->sizePolicy().hasHeightForWidth());
        BandWidthBTN->setSizePolicy(sizePolicy2);
        BandWidthBTN->setFont(font2);

        gridLayout_5->addWidget(BandWidthBTN, 4, 2, 1, 1);

        label_30 = new QLabel(groupBox_4);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font2);

        gridLayout_5->addWidget(label_30, 5, 0, 1, 1);


        gridLayout_11->addLayout(gridLayout_5, 1, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        ModleInf = new QLabel(groupBox_4);
        ModleInf->setObjectName(QStringLiteral("ModleInf"));
        sizePolicy.setHeightForWidth(ModleInf->sizePolicy().hasHeightForWidth());
        ModleInf->setSizePolicy(sizePolicy);

        gridLayout_12->addWidget(ModleInf, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMaximumSize(QSize(120, 40));

        gridLayout_12->addWidget(pushButton_4, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_12, 0, 0, 1, 1);


        gridLayout_13->addWidget(groupBox_4, 0, 0, 1, 1);

        AbnormalST = new QTextEdit(frame_4);
        AbnormalST->setObjectName(QStringLiteral("AbnormalST"));
        AbnormalST->setMaximumSize(QSize(16777215, 80));
        AbnormalST->setStyleSheet(QStringLiteral("background-color: rgb(241, 241, 241);"));

        gridLayout_13->addWidget(AbnormalST, 1, 0, 1, 1);


        gridLayout_14->addWidget(frame_4, 0, 2, 1, 1);

        frame_4->raise();
        frame->raise();
        frame_2->raise();

        retranslateUi(Widget);

        CBComMeter->setCurrentIndex(-1);
        CBBaudMeter->setCurrentIndex(2);
        CBParityMeter->setCurrentIndex(0);
        CBDataMeter->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        groupBox->setTitle(QString());
        CBComMeter->setCurrentText(QString());
        label_9->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267", 0));
        CBBaudMeter->clear();
        CBBaudMeter->insertItems(0, QStringList()
         << QApplication::translate("Widget", "2400", 0)
         << QApplication::translate("Widget", "4800", 0)
         << QApplication::translate("Widget", "9600", 0)
         << QApplication::translate("Widget", "19200", 0)
         << QApplication::translate("Widget", "115200", 0)
         << QApplication::translate("Widget", "custom", 0)
        );
        CBBaudMeter->setCurrentText(QApplication::translate("Widget", "9600", 0));
        label_8->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", 0));
        label_12->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", 0));
        label_7->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", 0));
        CBParityMeter->clear();
        CBParityMeter->insertItems(0, QStringList()
         << QApplication::translate("Widget", "NONE", 0)
         << QApplication::translate("Widget", "EVEN", 0)
         << QApplication::translate("Widget", "ODD", 0)
         << QApplication::translate("Widget", "MARK", 0)
         << QApplication::translate("Widget", "SPACE", 0)
        );
        BtnConn->setText(QApplication::translate("Widget", "Connect", 0));
        CBDataMeter->clear();
        CBDataMeter->insertItems(0, QStringList()
         << QApplication::translate("Widget", "5", 0)
         << QApplication::translate("Widget", "6", 0)
         << QApplication::translate("Widget", "7", 0)
         << QApplication::translate("Widget", "8", 0)
        );
        CBDataMeter->setCurrentText(QApplication::translate("Widget", "8", 0));
        label_6->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", 0));
        CBStopMeter->clear();
        CBStopMeter->insertItems(0, QStringList()
         << QApplication::translate("Widget", "1", 0)
         << QApplication::translate("Widget", "2", 0)
         << QApplication::translate("Widget", "1.5", 0)
        );
        pushButton->setText(QApplication::translate("Widget", "\346\237\245\347\234\213\345\216\206\345\217\262\346\225\260\346\215\256", 0));
        label_27->setText(QString());
        pushButton_2->setText(QApplication::translate("Widget", "\350\257\273\345\217\226\345\237\272\347\241\200\351\205\215\347\275\256", 0));
        BtnSetT->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\346\227\266\351\227\264", 0));
        dateTimeEdit->setDisplayFormat(QApplication::translate("Widget", "yyyy/M/d H:mm:ss", 0));
        label->setText(QApplication::translate("Widget", "\346\227\266\351\227\264", 0));
        RdReportPeriodBtn->setText(QApplication::translate("Widget", "\344\270\212\346\212\245\344\270\216\351\207\207\346\240\267\345\217\202\346\225\260", 0));
        SetLDN->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\350\241\250\345\217\267", 0));
        BtnRDAddr->setText(QApplication::translate("Widget", "\350\257\273\350\241\250\345\217\267", 0));
        LetSn->setText(QString());
        label_2->setText(QApplication::translate("Widget", "LDN", 0));
        groupBox_3->setTitle(QString());
        label_39->setText(QApplication::translate("Widget", "\344\273\252\350\241\250\346\227\266\351\227\264", 0));
        Device_timeLE->setText(QString());
        label_13->setText(QApplication::translate("Widget", "\346\250\241\345\274\217\345\210\207\346\215\242", 0));
        ModleChgCBB->clear();
        ModleChgCBB->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\345\267\245\345\216\202\346\250\241\345\274\217(0)", 0)
         << QApplication::translate("Widget", "\345\207\272\345\216\202\346\250\241\345\274\217(1)", 0)
         << QApplication::translate("Widget", "\347\224\250\346\210\267\346\250\241\345\274\217(2)", 0)
        );
        ModleBTN->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", 0));
        label_23->setText(QApplication::translate("Widget", "\347\264\257\347\247\257\347\224\250\351\207\217", 0));
        label_4->setText(QApplication::translate("Widget", "\347\224\265\345\216\213\351\230\210\345\200\274", 0));
        label_3->setText(QApplication::translate("Widget", "mV", 0));
        BtnVth->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", 0));
        label_14->setText(QApplication::translate("Widget", "\347\263\273\347\273\237\347\212\266\346\200\201", 0));
        label_18->setText(QApplication::translate("Widget", "\346\234\200\345\244\247\346\265\201\351\207\217", 0));
        label_24->setText(QApplication::translate("Widget", "m3/h", 0));
        MaxFlowBTN->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", 0));
        label_5->setText(QApplication::translate("Widget", "\345\244\226\347\224\265\347\224\265\345\216\213", 0));
        label_20->setText(QApplication::translate("Widget", "\346\234\200\345\260\217\346\265\201\351\207\217", 0));
        label_25->setText(QApplication::translate("Widget", "m3/h", 0));
        MinFlow_BTN->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", 0));
        label_19->setText(QApplication::translate("Widget", "\350\256\276\345\244\207\350\277\220\350\241\214\346\227\266\351\227\264", 0));
        label_35->setText(QApplication::translate("Widget", "\345\267\262\351\227\262\346\227\266\351\225\277", 0));
        label_38->setText(QApplication::translate("Widget", "\345\244\251", 0));
        label_17->setText(QApplication::translate("Widget", "\347\211\210\346\234\254\345\217\267", 0));
        label_21->setText(QApplication::translate("Widget", "\351\227\262\347\275\256\350\266\205\346\227\266", 0));
        label_26->setText(QApplication::translate("Widget", "\345\244\251", 0));
        IdleT_BTN->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", 0));
        label_22->setText(QApplication::translate("Widget", "\346\270\251\345\272\246", 0));
        label_15->setText(QApplication::translate("Widget", "\344\275\231\351\242\235", 0));
        AlarmFlow_BTN->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", 0));
        label_28->setText(QApplication::translate("Widget", "\350\277\236\347\273\255\346\216\211\347\272\277\346\227\266\351\225\277", 0));
        label_16->setText(QApplication::translate("Widget", "\344\275\231\351\207\217", 0));
        label_10->setText(QApplication::translate("Widget", "m3", 0));
        Balance_BTN->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", 0));
        label_40->setText(QApplication::translate("Widget", "\350\247\222", 0));
        label_41->setText(QApplication::translate("Widget", "\350\255\246\347\244\272\351\242\235\345\272\246", 0));
        label_42->setText(QApplication::translate("Widget", "\350\247\222", 0));
        label_43->setText(QApplication::translate("Widget", "\351\200\217\346\224\257\351\242\235\345\272\246", 0));
        groupBox_2->setTitle(QApplication::translate("Widget", "\351\230\200\351\227\250\346\216\247\345\210\266", 0));
        BtnOpenV->setText(QApplication::translate("Widget", "\345\274\200\351\230\200", 0));
        BtnClsV->setText(QApplication::translate("Widget", "\345\205\263\351\230\200", 0));
        label_11->setText(QApplication::translate("Widget", "\350\207\252\345\212\250\345\224\244\351\206\222\346\227\266\351\227\264", 0));
        Check_Normal_BTN->setText(QApplication::translate("Widget", "\346\237\245\347\234\213\345\274\202\345\270\270", 0));
        pushButton_3->setText(QApplication::translate("Widget", "\346\211\213\345\212\250\344\270\212\346\212\245", 0));
        Clear_NormalBTN->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\345\274\202\345\270\270", 0));
        pushButton_5->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", 0));
        groupBox_4->setTitle(QApplication::translate("Widget", "\347\275\221\347\273\234\351\205\215\347\275\256", 0));
        label_37->setText(QApplication::translate("Widget", "\351\224\231\345\263\260\346\227\266\351\227\264", 0));
        label_34->setText(QApplication::translate("Widget", "\345\244\207\344\273\275\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", 0));
        label_33->setText(QApplication::translate("Widget", "\345\244\207\344\273\275\346\234\215\345\212\241\345\231\250IP", 0));
        label_32->setText(QApplication::translate("Widget", "\345\272\224\347\224\250\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", 0));
        label_36->setText(QApplication::translate("Widget", "\351\224\231\345\263\260\344\275\277\350\203\275\347\212\266\346\200\201", 0));
        AvoidPeakClouseBTN->setText(QApplication::translate("Widget", "\344\275\277\350\203\275\345\205\263\351\227\255", 0));
        PLMN_BTN->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", 0));
        APPSevIPBTN->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", 0));
        BACKSevIPBTN->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", 0));
        AvoidPeakOpenBTN->setText(QApplication::translate("Widget", "\344\275\277\350\203\275\346\211\223\345\274\200", 0));
        label_31->setText(QApplication::translate("Widget", "\345\272\224\347\224\250\346\234\215\345\212\241\345\231\250IP", 0));
        label_29->setText(QApplication::translate("Widget", "\351\242\221\345\256\275", 0));
        BandWidthBTN->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", 0));
        label_30->setText(QApplication::translate("Widget", "PLMN", 0));
        ModleInf->setText(QString());
        pushButton_4->setText(QApplication::translate("Widget", "\350\257\273\347\275\221\347\273\234\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

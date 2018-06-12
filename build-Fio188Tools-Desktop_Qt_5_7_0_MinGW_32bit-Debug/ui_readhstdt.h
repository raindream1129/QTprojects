/********************************************************************************
** Form generated from reading UI file 'readhstdt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READHSTDT_H
#define UI_READHSTDT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReadHstDt
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabW_History;
    QWidget *tab_3;
    QGridLayout *gridLayout_6;
    QFrame *frame;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QDateTimeEdit *DTEMonthStart;
    QLabel *label;
    QPushButton *MonthBtn;
    QLabel *label_3;
    QDateTimeEdit *DTEMonthEnd;
    QLabel *labelRecordNumMon;
    QTableWidget *TBHistMonth;
    QWidget *tab_4;
    QGridLayout *gridLayout_8;
    QFrame *frame_2;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QDateTimeEdit *DTEDateStart;
    QLabel *label_13;
    QPushButton *DateBtn;
    QLabel *label_14;
    QDateTimeEdit *DTEDateEnd;
    QLabel *labelRecordNumdate;
    QTableWidget *TBHistDate;
    QWidget *tab_5;
    QGridLayout *gridLayout_10;
    QFrame *frame_3;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QDateTimeEdit *DTETimeStart;
    QLabel *label_16;
    QPushButton *TimeBtn;
    QLabel *label_17;
    QDateTimeEdit *DTETimeEnd;
    QLabel *labelRecordNumTime;
    QTableWidget *TBHistTime;

    void setupUi(QWidget *ReadHstDt)
    {
        if (ReadHstDt->objectName().isEmpty())
            ReadHstDt->setObjectName(QStringLiteral("ReadHstDt"));
        ReadHstDt->resize(480, 404);
        gridLayout = new QGridLayout(ReadHstDt);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabW_History = new QTabWidget(ReadHstDt);
        tabW_History->setObjectName(QStringLiteral("tabW_History"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_6 = new QGridLayout(tab_3);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        frame = new QFrame(tab_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        DTEMonthStart = new QDateTimeEdit(frame);
        DTEMonthStart->setObjectName(QStringLiteral("DTEMonthStart"));
        DTEMonthStart->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));
        DTEMonthStart->setCalendarPopup(true);

        horizontalLayout->addWidget(DTEMonthStart);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        MonthBtn = new QPushButton(frame);
        MonthBtn->setObjectName(QStringLiteral("MonthBtn"));

        gridLayout_2->addWidget(MonthBtn, 1, 2, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 1, 1, 1);

        DTEMonthEnd = new QDateTimeEdit(frame);
        DTEMonthEnd->setObjectName(QStringLiteral("DTEMonthEnd"));
        DTEMonthEnd->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));
        DTEMonthEnd->setCalendarPopup(true);

        gridLayout_2->addWidget(DTEMonthEnd, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);

        labelRecordNumMon = new QLabel(frame);
        labelRecordNumMon->setObjectName(QStringLiteral("labelRecordNumMon"));

        gridLayout_5->addWidget(labelRecordNumMon, 1, 0, 1, 1);

        TBHistMonth = new QTableWidget(frame);
        if (TBHistMonth->columnCount() < 4)
            TBHistMonth->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TBHistMonth->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TBHistMonth->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TBHistMonth->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TBHistMonth->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        TBHistMonth->setObjectName(QStringLiteral("TBHistMonth"));
        TBHistMonth->horizontalHeader()->setMinimumSectionSize(25);
        TBHistMonth->verticalHeader()->setDefaultSectionSize(30);

        gridLayout_5->addWidget(TBHistMonth, 2, 0, 1, 1);


        gridLayout_6->addWidget(frame, 0, 0, 1, 1);

        tabW_History->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_8 = new QGridLayout(tab_4);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        frame_2 = new QFrame(tab_4);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_2);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        DTEDateStart = new QDateTimeEdit(frame_2);
        DTEDateStart->setObjectName(QStringLiteral("DTEDateStart"));
        DTEDateStart->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));
        DTEDateStart->setCalendarPopup(true);

        horizontalLayout_2->addWidget(DTEDateStart);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 0, 0, 1, 1);

        DateBtn = new QPushButton(frame_2);
        DateBtn->setObjectName(QStringLiteral("DateBtn"));

        gridLayout_3->addWidget(DateBtn, 1, 2, 1, 1);

        label_14 = new QLabel(frame_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_3->addWidget(label_14, 0, 1, 1, 1);

        DTEDateEnd = new QDateTimeEdit(frame_2);
        DTEDateEnd->setObjectName(QStringLiteral("DTEDateEnd"));
        DTEDateEnd->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));
        DTEDateEnd->setCalendarPopup(true);

        gridLayout_3->addWidget(DTEDateEnd, 1, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 0, 0, 1, 1);

        labelRecordNumdate = new QLabel(frame_2);
        labelRecordNumdate->setObjectName(QStringLiteral("labelRecordNumdate"));

        gridLayout_7->addWidget(labelRecordNumdate, 1, 0, 1, 1);

        TBHistDate = new QTableWidget(frame_2);
        if (TBHistDate->columnCount() < 4)
            TBHistDate->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TBHistDate->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        TBHistDate->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        TBHistDate->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        TBHistDate->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        TBHistDate->setObjectName(QStringLiteral("TBHistDate"));

        gridLayout_7->addWidget(TBHistDate, 2, 0, 1, 1);


        gridLayout_8->addWidget(frame_2, 0, 0, 1, 1);

        tabW_History->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_10 = new QGridLayout(tab_5);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        frame_3 = new QFrame(tab_5);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_9 = new QGridLayout(frame_3);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        DTETimeStart = new QDateTimeEdit(frame_3);
        DTETimeStart->setObjectName(QStringLiteral("DTETimeStart"));
        DTETimeStart->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));
        DTETimeStart->setCalendarPopup(true);

        horizontalLayout_3->addWidget(DTETimeStart);


        gridLayout_4->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        label_16 = new QLabel(frame_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_4->addWidget(label_16, 0, 0, 1, 1);

        TimeBtn = new QPushButton(frame_3);
        TimeBtn->setObjectName(QStringLiteral("TimeBtn"));

        gridLayout_4->addWidget(TimeBtn, 1, 2, 1, 1);

        label_17 = new QLabel(frame_3);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_4->addWidget(label_17, 0, 1, 1, 1);

        DTETimeEnd = new QDateTimeEdit(frame_3);
        DTETimeEnd->setObjectName(QStringLiteral("DTETimeEnd"));
        DTETimeEnd->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));
        DTETimeEnd->setCalendarPopup(true);

        gridLayout_4->addWidget(DTETimeEnd, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_4, 0, 0, 1, 1);

        labelRecordNumTime = new QLabel(frame_3);
        labelRecordNumTime->setObjectName(QStringLiteral("labelRecordNumTime"));

        gridLayout_9->addWidget(labelRecordNumTime, 1, 0, 1, 1);

        TBHistTime = new QTableWidget(frame_3);
        if (TBHistTime->columnCount() < 4)
            TBHistTime->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        TBHistTime->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        TBHistTime->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        TBHistTime->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        TBHistTime->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        TBHistTime->setObjectName(QStringLiteral("TBHistTime"));

        gridLayout_9->addWidget(TBHistTime, 2, 0, 1, 1);


        gridLayout_10->addWidget(frame_3, 0, 0, 1, 1);

        tabW_History->addTab(tab_5, QString());

        gridLayout->addWidget(tabW_History, 0, 0, 1, 1);


        retranslateUi(ReadHstDt);

        tabW_History->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ReadHstDt);
    } // setupUi

    void retranslateUi(QWidget *ReadHstDt)
    {
        ReadHstDt->setWindowTitle(QApplication::translate("ReadHstDt", "Form", 0));
        DTEMonthStart->setDisplayFormat(QApplication::translate("ReadHstDt", "yyyy\345\271\264MM\346\234\210", 0));
        label->setText(QApplication::translate("ReadHstDt", "\346\237\245\350\257\242\347\232\204\345\274\200\345\247\213\346\227\266\351\227\264", 0));
        MonthBtn->setText(QApplication::translate("ReadHstDt", "\347\241\256\345\256\232", 0));
        label_3->setText(QApplication::translate("ReadHstDt", "\346\237\245\350\257\242\347\232\204\347\273\223\346\235\237\346\227\266\351\227\264", 0));
        DTEMonthEnd->setDisplayFormat(QApplication::translate("ReadHstDt", "yyyy\345\271\264MM\346\234\210", 0));
        labelRecordNumMon->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = TBHistMonth->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ReadHstDt", "\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem1 = TBHistMonth->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ReadHstDt", "\347\264\257\350\256\241\347\224\250\346\260\224\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem2 = TBHistMonth->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ReadHstDt", "\347\263\273\347\273\237\347\212\266\346\200\201", 0));
        QTableWidgetItem *___qtablewidgetitem3 = TBHistMonth->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ReadHstDt", "\346\270\251\345\272\246", 0));
        tabW_History->setTabText(tabW_History->indexOf(tab_3), QApplication::translate("ReadHstDt", "\346\234\210\350\256\260\345\275\225", 0));
        DTEDateStart->setDisplayFormat(QApplication::translate("ReadHstDt", "yy\345\271\264MM\346\234\210dd\346\227\245", 0));
        label_13->setText(QApplication::translate("ReadHstDt", "\346\237\245\350\257\242\347\232\204\345\274\200\345\247\213\346\227\266\351\227\264", 0));
        DateBtn->setText(QApplication::translate("ReadHstDt", "\347\241\256\345\256\232", 0));
        label_14->setText(QApplication::translate("ReadHstDt", "\346\237\245\350\257\242\347\232\204\347\273\223\346\235\237\346\227\266\351\227\264", 0));
        DTEDateEnd->setDisplayFormat(QApplication::translate("ReadHstDt", "yy\345\271\264MM\346\234\210dd\346\227\245", 0));
        labelRecordNumdate->setText(QString());
        QTableWidgetItem *___qtablewidgetitem4 = TBHistDate->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("ReadHstDt", "\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem5 = TBHistDate->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("ReadHstDt", "\347\264\257\350\256\241\347\224\250\346\260\224\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem6 = TBHistDate->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("ReadHstDt", "\347\263\273\347\273\237\347\212\266\346\200\201", 0));
        QTableWidgetItem *___qtablewidgetitem7 = TBHistDate->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("ReadHstDt", "\346\270\251\345\272\246", 0));
        tabW_History->setTabText(tabW_History->indexOf(tab_4), QApplication::translate("ReadHstDt", "\346\227\245\350\256\260\345\275\225", 0));
        DTETimeStart->setDisplayFormat(QApplication::translate("ReadHstDt", "MM\346\234\210dd\346\227\245HH\346\227\266", 0));
        label_16->setText(QApplication::translate("ReadHstDt", "\346\237\245\350\257\242\347\232\204\345\274\200\345\247\213\346\227\266\351\227\264", 0));
        TimeBtn->setText(QApplication::translate("ReadHstDt", "\347\241\256\345\256\232", 0));
        label_17->setText(QApplication::translate("ReadHstDt", "\346\237\245\350\257\242\347\232\204\347\273\223\346\235\237\346\227\266\351\227\264", 0));
        DTETimeEnd->setDisplayFormat(QApplication::translate("ReadHstDt", "MM\346\234\210dd\346\227\245HH\346\227\266", 0));
        labelRecordNumTime->setText(QString());
        QTableWidgetItem *___qtablewidgetitem8 = TBHistTime->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("ReadHstDt", "\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem9 = TBHistTime->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("ReadHstDt", "\347\264\257\350\256\241\347\224\250\346\260\224\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem10 = TBHistTime->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("ReadHstDt", "\347\263\273\347\273\237\347\212\266\346\200\201", 0));
        QTableWidgetItem *___qtablewidgetitem11 = TBHistTime->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("ReadHstDt", "\346\270\251\345\272\246", 0));
        tabW_History->setTabText(tabW_History->indexOf(tab_5), QApplication::translate("ReadHstDt", "\346\227\266\350\256\260\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class ReadHstDt: public Ui_ReadHstDt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READHSTDT_H

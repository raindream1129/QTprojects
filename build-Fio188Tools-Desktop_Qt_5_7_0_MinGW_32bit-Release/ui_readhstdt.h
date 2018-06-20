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
    QPushButton *MonthBtn;
    QLabel *labelRecordNumMon;
    QTableWidget *TBHistMonth;
    QWidget *tab_4;
    QGridLayout *gridLayout_8;
    QFrame *frame_2;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *DateBtn;
    QLabel *labelRecordNumdate;
    QTableWidget *TBHistDate;
    QWidget *tab_5;
    QGridLayout *gridLayout_10;
    QFrame *frame_3;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *TimeBtn;
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

        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        MonthBtn = new QPushButton(frame);
        MonthBtn->setObjectName(QStringLiteral("MonthBtn"));

        gridLayout_2->addWidget(MonthBtn, 0, 1, 1, 1);


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

        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        DateBtn = new QPushButton(frame_2);
        DateBtn->setObjectName(QStringLiteral("DateBtn"));

        gridLayout_3->addWidget(DateBtn, 0, 1, 1, 1);


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

        gridLayout_4->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        TimeBtn = new QPushButton(frame_3);
        TimeBtn->setObjectName(QStringLiteral("TimeBtn"));

        gridLayout_4->addWidget(TimeBtn, 0, 1, 1, 1);


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

        tabW_History->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ReadHstDt);
    } // setupUi

    void retranslateUi(QWidget *ReadHstDt)
    {
        ReadHstDt->setWindowTitle(QApplication::translate("ReadHstDt", "Form", 0));
        MonthBtn->setText(QApplication::translate("ReadHstDt", "\347\241\256\345\256\232", 0));
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
        DateBtn->setText(QApplication::translate("ReadHstDt", "\347\241\256\345\256\232", 0));
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
        TimeBtn->setText(QApplication::translate("ReadHstDt", "\347\241\256\345\256\232", 0));
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

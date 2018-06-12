/********************************************************************************
** Form generated from reading UI file 'readjldata.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READJLDATA_H
#define UI_READJLDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReadJLdata
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *TimeLineE;
    QLineEdit *CurrentTotalFlowLineE;
    QLabel *label_4;
    QLineEdit *SYSState;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *TMP_LE;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *ReadJLdata)
    {
        if (ReadJLdata->objectName().isEmpty())
            ReadJLdata->setObjectName(QStringLiteral("ReadJLdata"));
        ReadJLdata->resize(339, 230);
        gridLayoutWidget = new QWidget(ReadJLdata);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 40, 281, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        TimeLineE = new QLineEdit(gridLayoutWidget);
        TimeLineE->setObjectName(QStringLiteral("TimeLineE"));

        gridLayout->addWidget(TimeLineE, 0, 1, 1, 1);

        CurrentTotalFlowLineE = new QLineEdit(gridLayoutWidget);
        CurrentTotalFlowLineE->setObjectName(QStringLiteral("CurrentTotalFlowLineE"));

        gridLayout->addWidget(CurrentTotalFlowLineE, 1, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        SYSState = new QLineEdit(gridLayoutWidget);
        SYSState->setObjectName(QStringLiteral("SYSState"));

        gridLayout->addWidget(SYSState, 2, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setScaledContents(false);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        TMP_LE = new QLineEdit(gridLayoutWidget);
        TMP_LE->setObjectName(QStringLiteral("TMP_LE"));

        gridLayout->addWidget(TMP_LE, 3, 1, 1, 1);

        label_5 = new QLabel(ReadJLdata);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(320, 100, 54, 12));
        label_5->setFont(font);
        label_7 = new QLabel(ReadJLdata);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 10, 191, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(16);
        label_7->setFont(font1);
        label_8 = new QLabel(ReadJLdata);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(320, 180, 21, 16));

        retranslateUi(ReadJLdata);

        QMetaObject::connectSlotsByName(ReadJLdata);
    } // setupUi

    void retranslateUi(QWidget *ReadJLdata)
    {
        ReadJLdata->setWindowTitle(QApplication::translate("ReadJLdata", "Form", 0));
        label_6->setText(QApplication::translate("ReadJLdata", "\346\270\251\345\272\246", 0));
        label_4->setText(QApplication::translate("ReadJLdata", "\347\263\273\347\273\237\347\212\266\346\200\201:", 0));
        label_3->setText(QApplication::translate("ReadJLdata", "\346\227\266\351\227\264:", 0));
        label->setText(QApplication::translate("ReadJLdata", "\345\275\223\345\211\215\347\264\257\347\247\257\346\265\201\351\207\217:", 0));
        label_5->setText(QApplication::translate("ReadJLdata", "m3", 0));
        label_7->setText(QApplication::translate("ReadJLdata", "\350\256\241\351\207\217\346\225\260\346\215\256\344\270\216\347\263\273\347\273\237\347\212\266\346\200\201", 0));
        label_8->setText(QApplication::translate("ReadJLdata", "\342\204\203", 0));
    } // retranslateUi

};

namespace Ui {
    class ReadJLdata: public Ui_ReadJLdata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READJLDATA_H

/********************************************************************************
** Form generated from reading UI file 'totalizer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTALIZER_H
#define UI_TOTALIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_totalizer
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *totalizer)
    {
        if (totalizer->objectName().isEmpty())
            totalizer->setObjectName(QStringLiteral("totalizer"));
        totalizer->resize(305, 132);
        buttonBox = new QDialogButtonBox(totalizer);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 60, 221, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::No|QDialogButtonBox::Yes);
        label = new QLabel(totalizer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 0, 121, 31));

        retranslateUi(totalizer);
        QObject::connect(buttonBox, SIGNAL(accepted()), totalizer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), totalizer, SLOT(reject()));

        QMetaObject::connectSlotsByName(totalizer);
    } // setupUi

    void retranslateUi(QDialog *totalizer)
    {
        totalizer->setWindowTitle(QApplication::translate("totalizer", "\347\264\257\345\212\240\345\231\250\346\243\200\346\237\245", 0));
        label->setText(QApplication::translate("totalizer", "\347\264\257\347\247\257\351\207\217\346\230\257\345\220\246\346\255\243\347\241\256", 0));
    } // retranslateUi

};

namespace Ui {
    class totalizer: public Ui_totalizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALIZER_H

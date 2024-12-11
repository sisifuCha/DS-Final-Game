/********************************************************************************
** Form generated from reading UI file 'rankdlg.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKDLG_H
#define UI_RANKDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_RankDlg
{
public:
    QLabel *label;

    void setupUi(QDialog *RankDlg)
    {
        if (RankDlg->objectName().isEmpty())
            RankDlg->setObjectName("RankDlg");
        RankDlg->resize(400, 359);
        label = new QLabel(RankDlg);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 60, 301, 31));

        retranslateUi(RankDlg);

        QMetaObject::connectSlotsByName(RankDlg);
    } // setupUi

    void retranslateUi(QDialog *RankDlg)
    {
        RankDlg->setWindowTitle(QCoreApplication::translate("RankDlg", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RankDlg", "\350\277\231\345\235\227\344\270\215\351\234\200\350\246\201\344\272\244\346\215\242\357\274\214\350\256\276\350\256\241\344\275\240\347\232\204\346\216\222\350\241\214\346\246\234\346\240\267\345\274\217\345\260\261\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RankDlg: public Ui_RankDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKDLG_H

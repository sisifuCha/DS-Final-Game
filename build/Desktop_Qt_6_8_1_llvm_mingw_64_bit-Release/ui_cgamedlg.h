/********************************************************************************
** Form generated from reading UI file 'cgamedlg.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGAMEDLG_H
#define UI_CGAMEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CGameDlg
{
public:
    QProgressBar *progressBar;
    QPushButton *settingButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QGraphicsView *graphicsView;
    QPushButton *SwapButton;
    QLabel *timesLabel;

    void setupUi(QDialog *CGameDlg)
    {
        if (CGameDlg->objectName().isEmpty())
            CGameDlg->setObjectName("CGameDlg");
        CGameDlg->resize(907, 659);
        progressBar = new QProgressBar(CGameDlg);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(50, 620, 371, 23));
        progressBar->setValue(24);
        settingButton = new QPushButton(CGameDlg);
        settingButton->setObjectName("settingButton");
        settingButton->setGeometry(QRect(770, 380, 92, 28));
        label = new QLabel(CGameDlg);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 10, 111, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        pushButton_2 = new QPushButton(CGameDlg);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(770, 420, 92, 28));
        label_2 = new QLabel(CGameDlg);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(440, 620, 69, 19));
        graphicsView = new QGraphicsView(CGameDlg);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(30, 60, 681, 531));
        SwapButton = new QPushButton(CGameDlg);
        SwapButton->setObjectName("SwapButton");
        SwapButton->setGeometry(QRect(770, 340, 92, 28));
        timesLabel = new QLabel(CGameDlg);
        timesLabel->setObjectName("timesLabel");
        timesLabel->setGeometry(QRect(530, 610, 121, 31));

        retranslateUi(CGameDlg);

        QMetaObject::connectSlotsByName(CGameDlg);
    } // setupUi

    void retranslateUi(QDialog *CGameDlg)
    {
        CGameDlg->setWindowTitle(QCoreApplication::translate("CGameDlg", "Dialog", nullptr));
        settingButton->setText(QCoreApplication::translate("CGameDlg", "Setting", nullptr));
        label->setText(QCoreApplication::translate("CGameDlg", "GAME", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CGameDlg", "Pause", nullptr));
        label_2->setText(QCoreApplication::translate("CGameDlg", "BLOOD", nullptr));
        SwapButton->setText(QCoreApplication::translate("CGameDlg", "Swap", nullptr));
        timesLabel->setText(QCoreApplication::translate("CGameDlg", "\345\211\251\344\275\231\346\227\266\351\227\264 120\347\247\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGameDlg: public Ui_CGameDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGAMEDLG_H

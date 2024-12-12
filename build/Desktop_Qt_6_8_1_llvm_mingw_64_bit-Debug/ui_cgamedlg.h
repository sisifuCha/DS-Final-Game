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

    void setupUi(QDialog *CGameDlg)
    {
        if (CGameDlg->objectName().isEmpty())
            CGameDlg->setObjectName("CGameDlg");
        CGameDlg->resize(800, 621);
        progressBar = new QProgressBar(CGameDlg);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(50, 560, 371, 23));
        progressBar->setValue(24);
        settingButton = new QPushButton(CGameDlg);
        settingButton->setObjectName("settingButton");
        settingButton->setGeometry(QRect(650, 370, 92, 28));
        label = new QLabel(CGameDlg);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 10, 111, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        pushButton_2 = new QPushButton(CGameDlg);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(650, 410, 92, 28));
        label_2 = new QLabel(CGameDlg);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(440, 560, 69, 19));
        graphicsView = new QGraphicsView(CGameDlg);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(30, 80, 481, 421));
        SwapButton = new QPushButton(CGameDlg);
        SwapButton->setObjectName("SwapButton");
        SwapButton->setGeometry(QRect(650, 330, 92, 28));

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
    } // retranslateUi

};

namespace Ui {
    class CGameDlg: public Ui_CGameDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGAMEDLG_H

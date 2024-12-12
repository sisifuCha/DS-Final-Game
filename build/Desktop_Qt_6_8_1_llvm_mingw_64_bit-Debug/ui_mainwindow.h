/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *nameLabel;
    QPushButton *startGameButton;
    QPushButton *checkInfoButton;
    QLabel *guideLabel;
    QPushButton *signInButton;
    QPushButton *checkRankButton;
    QPushButton *checkRankButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(240, 50, 301, 101));
        QFont font;
        font.setPointSize(36);
        nameLabel->setFont(font);
        nameLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        startGameButton = new QPushButton(centralwidget);
        startGameButton->setObjectName("startGameButton");
        startGameButton->setGeometry(QRect(310, 250, 171, 41));
        startGameButton->setIconSize(QSize(30, 30));
        checkInfoButton = new QPushButton(centralwidget);
        checkInfoButton->setObjectName("checkInfoButton");
        checkInfoButton->setGeometry(QRect(310, 510, 171, 31));
        guideLabel = new QLabel(centralwidget);
        guideLabel->setObjectName("guideLabel");
        guideLabel->setGeometry(QRect(280, 170, 221, 51));
        guideLabel->setFont(font);
        guideLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        signInButton = new QPushButton(centralwidget);
        signInButton->setObjectName("signInButton");
        signInButton->setGeometry(QRect(310, 320, 171, 41));
        signInButton->setIconSize(QSize(30, 30));
        checkRankButton = new QPushButton(centralwidget);
        checkRankButton->setObjectName("checkRankButton");
        checkRankButton->setGeometry(QRect(310, 390, 171, 41));
        checkRankButton->setIconSize(QSize(30, 30));
        checkRankButton_2 = new QPushButton(centralwidget);
        checkRankButton_2->setObjectName("checkRankButton_2");
        checkRankButton_2->setGeometry(QRect(310, 470, 171, 31));
        checkRankButton_2->setIconSize(QSize(30, 30));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "\345\256\235\347\237\263\350\277\267\351\230\265", nullptr));
        startGameButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        checkInfoButton->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        guideLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">\350\257\267\345\234\250\347\231\273\345\275\225\345\220\216\350\277\233\350\241\214\346\270\270\346\210\217</span></p></body></html>", nullptr));
        signInButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        checkRankButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\346\216\222\350\241\214\346\246\234", nullptr));
        checkRankButton_2->setText(QCoreApplication::translate("MainWindow", "\346\270\270\346\210\217\350\257\264\346\230\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'Setgamedlg.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETGAMEDLG_H
#define UI_SETGAMEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setGameDlg
{
public:
    QTabWidget *tabWidget;
    QWidget *tabWidgetPage1;
    QRadioButton *modeChoseButton;
    QRadioButton *modeChoseButton_2;
    QLabel *label_2;
    QComboBox *chooseDimensionBox;
    QComboBox *chooseStoneNumBox;
    QLabel *label_3;
    QWidget *tab;
    QRadioButton *DefaltMusicButton;
    QRadioButton *tailorMusicButton;
    QLineEdit *musicFileChooseEdit;
    QPushButton *chooseMusicFileButton;
    QSlider *volumeSlider;
    QLabel *label;
    QWidget *tab_2;
    QLineEdit *picFileChooseEdit;
    QPushButton *pushButton;
    QPushButton *startButton;
    QPushButton *backButton;

    void setupUi(QDialog *setGameDlg)
    {
        if (setGameDlg->objectName().isEmpty())
            setGameDlg->setObjectName("setGameDlg");
        setGameDlg->resize(502, 320);
        tabWidget = new QTabWidget(setGameDlg);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(40, 40, 421, 181));
        tabWidgetPage1 = new QWidget();
        tabWidgetPage1->setObjectName("tabWidgetPage1");
        tabWidgetPage1->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        modeChoseButton = new QRadioButton(tabWidgetPage1);
        modeChoseButton->setObjectName("modeChoseButton");
        modeChoseButton->setGeometry(QRect(20, 20, 81, 24));
        modeChoseButton_2 = new QRadioButton(tabWidgetPage1);
        modeChoseButton_2->setObjectName("modeChoseButton_2");
        modeChoseButton_2->setGeometry(QRect(170, 20, 81, 24));
        label_2 = new QLabel(tabWidgetPage1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 80, 63, 18));
        chooseDimensionBox = new QComboBox(tabWidgetPage1);
        chooseDimensionBox->addItem(QString());
        chooseDimensionBox->addItem(QString());
        chooseDimensionBox->setObjectName("chooseDimensionBox");
        chooseDimensionBox->setGeometry(QRect(90, 80, 80, 26));
        chooseStoneNumBox = new QComboBox(tabWidgetPage1);
        chooseStoneNumBox->addItem(QString());
        chooseStoneNumBox->addItem(QString());
        chooseStoneNumBox->setObjectName("chooseStoneNumBox");
        chooseStoneNumBox->setGeometry(QRect(270, 80, 80, 26));
        label_3 = new QLabel(tabWidgetPage1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(190, 80, 63, 18));
        tabWidget->addTab(tabWidgetPage1, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        DefaltMusicButton = new QRadioButton(tab);
        DefaltMusicButton->setObjectName("DefaltMusicButton");
        DefaltMusicButton->setGeometry(QRect(30, 20, 110, 24));
        tailorMusicButton = new QRadioButton(tab);
        tailorMusicButton->setObjectName("tailorMusicButton");
        tailorMusicButton->setGeometry(QRect(220, 20, 131, 24));
        musicFileChooseEdit = new QLineEdit(tab);
        musicFileChooseEdit->setObjectName("musicFileChooseEdit");
        musicFileChooseEdit->setGeometry(QRect(30, 60, 201, 26));
        chooseMusicFileButton = new QPushButton(tab);
        chooseMusicFileButton->setObjectName("chooseMusicFileButton");
        chooseMusicFileButton->setGeometry(QRect(270, 60, 91, 26));
        volumeSlider = new QSlider(tab);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(130, 110, 231, 21));
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 110, 71, 18));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        picFileChooseEdit = new QLineEdit(tab_2);
        picFileChooseEdit->setObjectName("picFileChooseEdit");
        picFileChooseEdit->setGeometry(QRect(50, 60, 211, 26));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 60, 86, 26));
        tabWidget->addTab(tab_2, QString());
        startButton = new QPushButton(setGameDlg);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(380, 260, 86, 26));
        backButton = new QPushButton(setGameDlg);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(40, 260, 86, 26));

        retranslateUi(setGameDlg);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(setGameDlg);
    } // setupUi

    void retranslateUi(QDialog *setGameDlg)
    {
        setGameDlg->setWindowTitle(QCoreApplication::translate("setGameDlg", "Dialog", nullptr));
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QCoreApplication::translate("setGameDlg", "<html><head/><body><p>\350\256\276\347\275\256\346\270\270\346\210\217\346\250\241\345\274\217</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        modeChoseButton->setText(QCoreApplication::translate("setGameDlg", "\345\270\270\350\247\204\346\250\241\345\274\217", nullptr));
        modeChoseButton_2->setText(QCoreApplication::translate("setGameDlg", "\345\271\263\350\241\241\346\250\241\345\274\217", nullptr));
        label_2->setText(QCoreApplication::translate("setGameDlg", "\351\232\276\345\272\246\351\200\211\346\213\251", nullptr));
        chooseDimensionBox->setItemText(0, QCoreApplication::translate("setGameDlg", "8\303\2278", nullptr));
        chooseDimensionBox->setItemText(1, QCoreApplication::translate("setGameDlg", "10\303\22710", nullptr));

        chooseStoneNumBox->setItemText(0, QCoreApplication::translate("setGameDlg", "4", nullptr));
        chooseStoneNumBox->setItemText(1, QCoreApplication::translate("setGameDlg", "5", nullptr));

        label_3->setText(QCoreApplication::translate("setGameDlg", "\351\232\276\345\272\246\351\200\211\346\213\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabWidgetPage1), QCoreApplication::translate("setGameDlg", "\346\270\270\346\210\217\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));
        DefaltMusicButton->setText(QCoreApplication::translate("setGameDlg", "\344\275\277\347\224\250\351\273\230\350\256\244\351\237\263\344\271\220", nullptr));
        tailorMusicButton->setText(QCoreApplication::translate("setGameDlg", "\344\275\277\347\224\250\350\207\252\345\256\232\344\271\211\351\237\263\344\271\220", nullptr));
        chooseMusicFileButton->setText(QCoreApplication::translate("setGameDlg", "\351\200\211\346\213\251\351\237\263\344\271\220\346\226\207\344\273\266", nullptr));
        label->setText(QCoreApplication::translate("setGameDlg", "\350\256\276\347\275\256\351\237\263\351\207\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("setGameDlg", "\346\270\270\346\210\217\345\243\260\351\237\263\351\200\211\346\213\251", nullptr));
        pushButton->setText(QCoreApplication::translate("setGameDlg", "\351\200\211\346\213\251\350\203\214\346\231\257\345\233\276\347\211\207", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("setGameDlg", "\350\203\214\346\231\257\345\233\276\347\211\207\350\256\276\347\275\256", nullptr));
        startButton->setText(QCoreApplication::translate("setGameDlg", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        backButton->setText(QCoreApplication::translate("setGameDlg", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setGameDlg: public Ui_setGameDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETGAMEDLG_H

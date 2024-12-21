/********************************************************************************
** Form generated from reading UI file 'signindlg.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINDLG_H
#define UI_SIGNINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SignInDialog
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *SignInDialog)
    {
        if (SignInDialog->objectName().isEmpty())
            SignInDialog->setObjectName("SignInDialog");
        SignInDialog->resize(400, 300);
        pushButton = new QPushButton(SignInDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 200, 86, 26));
        lineEdit = new QLineEdit(SignInDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(70, 80, 221, 26));
        label = new QLabel(SignInDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 60, 63, 18));
        label_2 = new QLabel(SignInDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 120, 63, 18));
        lineEdit_2 = new QLineEdit(SignInDialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(70, 140, 221, 26));

        retranslateUi(SignInDialog);

        QMetaObject::connectSlotsByName(SignInDialog);
    } // setupUi

    void retranslateUi(QDialog *SignInDialog)
    {
        SignInDialog->setWindowTitle(QCoreApplication::translate("SignInDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("SignInDialog", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("SignInDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("SignInDialog", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignInDialog: public Ui_SignInDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINDLG_H

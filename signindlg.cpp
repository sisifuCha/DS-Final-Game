#include "signindlg.h"
#include "ui_signindlg.h"

SignInDialog::SignInDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignInDialog)
{
    ui->setupUi(this);
}

SignInDialog::~SignInDialog()
{
    delete ui;
}

void SignInDialog::on_pushButton_clicked()
{
    //输入用户名以及密码，  打开文件    匹配用户名，如果用户名一样，那么匹配密码是否正确
    //如果用户名不一样，那么根据用户名和密码创建新账户


    //需要设计文件的行和列代表什么内容
    //需要返回一个bool参数，表示是否成功登录给Mainwindow
}


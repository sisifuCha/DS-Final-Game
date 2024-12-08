#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),setGameDialog(nullptr),signInDialog(nullptr),rankDlg(nullptr)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signInButton_clicked()
{
    //弹出窗口让玩家登录————syf
    signInDialog = new SignInDialog(this);
    signInDialog->show();
    //输入用户名以及密码，  打开文件    匹配用户名，如果用户名一样，那么匹配密码是否正确
    //如果用户名不一样，那么根据用户名和密码创建新账户


    //需要设计文件的行和列代表什么内容
    return;//返回之前需要改变MainWindow中的布尔变量hasSignIn值
}


void MainWindow::on_startGameButton_clicked()
{
    //判断是否已经登录，已经登录则弹出窗口
    if(hasSignIn){

        setGameDialog = new setGameDlg(this);  // 创建 CSetGameWidget 对象
        setGameDialog->show();
    }else{
        hasSignIn=true;//这行注释掉，为了演示可以过写的
    }
}


void MainWindow::on_checkRankButton_clicked()
{
    //查看排行榜————syf
    rankDlg = new RankDlg(this);
    rankDlg->show();
}


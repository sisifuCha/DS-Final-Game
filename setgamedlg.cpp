#include "Setgamedlg.h"
#include "ui_Setgamedlg.h"

setGameDlg::setGameDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::setGameDlg)
{
    ui->setupUi(this);
}

setGameDlg::~setGameDlg()
{
    delete ui;
}

void setGameDlg::on_chooseMusicFileButton_clicked()
{
    //打开文件资源管理器，选择特定格式的背景音乐进行播放————hzr
    //QT实现背景音乐的播放建议自己先试试。
}


void setGameDlg::on_volumeSlider_sliderMoved(int position)
{
   //滑动音量调，改变音量参数
}


void setGameDlg::on_pushButton_clicked()
{
     //打开文件，选择背景图片，地址传递到QMainwindow中
}


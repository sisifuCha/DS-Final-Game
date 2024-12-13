#include "Setgamedlg.h"
#include "ui_Setgamedlg.h"
#include "QButtonGroup"
#include <QStringList>
#include "cgamedlg.h"

setGameDlg::setGameDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::setGameDlg)
{
    ui->setupUi(this);
    //————————————————变量初始化——————————————//
    gameMode=0;//0代表默认模式

    //————————————————界面初始化——————————————//
    //模式选择radiobut放在一个按钮组里面
    QButtonGroup* group = new QButtonGroup(this);
    group->addButton(ui->modeChoseButton);
    group->addButton(ui->modeChoseButton_2);

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

void setGameDlg::on_startButton_clicked()
{
    //开始游戏界面
    QString dim=ui->chooseDimensionBox->currentText();
    QStringList strList=dim.split("×");
    int dimension=strList[0].toInt();
    int numOfStone=ui->chooseStoneNumBox->currentText().toInt();
    int gemType=ui->comboBox_gemtype->currentIndex();
    int backChoice=ui->comboBox_background->currentIndex();
    //gameMode是成员变量

    int volume=ui->volumeSlider->value();//音量是最小为0最大为99的一个数值，表示比例
    bool useDefaultMusic=true;
    QString musicFileAdd=ui->musicFileChooseEdit->text();
    //QString picFileAdd=ui->picFileChooseEdit->text();

    //如果不相等，那么useuseDefaultMusic=false
    if(QString::compare(musicFileAdd,"",Qt::CaseSensitive)){
        useDefaultMusic=false;
    }

    //qDebug()<<"测试点1";
    CGameDlg* cgameDlg=new CGameDlg(this,dimension,numOfStone,gemType,backChoice);
    cgameDlg->show();
}

//选择默认模式
void setGameDlg::on_modeChoseButton_clicked()
{
    gameMode=0;
}

//选择平衡模式
void setGameDlg::on_modeChoseButton_2_clicked()
{
    gameMode=1;
}


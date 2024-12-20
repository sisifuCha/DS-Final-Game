#ifndef CGAMEDLG_H
#define CGAMEDLG_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include "gamelogic.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPair>

//版本更新于12.19 以作区分

namespace Ui {
class CGameDlg;
}

class CGameDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CGameDlg(QWidget *parent = nullptr,int dimension=8,int numOfStone=4,int gemtype=1,int backChoice=1);
    ~CGameDlg();
    GameLogic* gLogic;

    int dimension;//表示矩阵的维度
    int numOfStone;//宝石种类
    int volume;
    QString musicFileAdd;
    QString bcakGroundPicAdd;//背景图片地址
    QVector<QString> stonePic;//存放四种宝石图片地址的数组

    //随机生成一个dimension维度矩阵，并做好点击事件
    QVector<QVector<Stone>> matrix;

    //计时器
    QTimer* timer;
    int secCount;
    void updateLabel();
    int timeLimit;

    //设置背景图片
    int gemType;
    int backChoice;
    void iniPicRescource();//初始化的设置，避免构造函数写一堆if else
    QPixmap backGround;

    /*——————————判断相邻，消子————————————*/
    //由left/rightChooseStone储存交换信息
    Stone* leftChooseStone ;
    Stone* rightChooseStone;
    QPair<int,int> leftChoosePair;
    QPair<int,int> rightChoosePair;
    //显示选中信息
    QGraphicsRectItem* lborderItem;//用来显示选中宝石的边框
    QGraphicsRectItem* rborderItem;

    //存放消去的子
    QVector<Stone*> collection1;
    QVector<Stone*> collection2;

    int ClickedTimes=0;
protected:
    void mousePressEvent(QMouseEvent* event) override;

private slots:
    void on_SwapButton_clicked();

private:
    Ui::CGameDlg *ui;
    int lclicktime;
    int rclicktime;
};

#endif // CGAMEDLG_H

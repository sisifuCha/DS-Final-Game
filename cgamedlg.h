#ifndef CGAMEDLG_H
#define CGAMEDLG_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include "gamelogic.h"
#include <QGraphicsPixmapItem>
typedef struct{
    int category;//宝石种类
    QGraphicsPixmapItem* picItem;
}Stone;//
namespace Ui {
class CGameDlg;
}

class CGameDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CGameDlg(QWidget *parent = nullptr,int dimension=8,int numOfStone=4);
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

    /*——————————判断相邻，消子————————————*/
    //由stone1和stone2储存交换信息
    QVector<Stone> swapStones;
protected:
    void mousePressEvent(QMouseEvent* event) override;

private:
    Ui::CGameDlg *ui;
};

#endif // CGAMEDLG_H

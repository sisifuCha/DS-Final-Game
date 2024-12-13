#include "gamelogic.h"
#include <QRandomGenerator>

GameLogic::GameLogic(int dimension,int numOfStone){
    this->dimension=dimension;
    this->numOfStone=numOfStone;

    coutSec=0;
    timer=new QTimer(nullptr);
}

QVector<QVector<int>> GameLogic::Inimatrix(){
    QVector<QVector<int>> result(dimension,QVector<int>(dimension,0));
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            result[i][j]=QRandomGenerator::global()->bounded(numOfStone);
            //生成从0（包含)到numOfStone（包含）的随机数
        }
        //qDebug()<<Qt::endl;
    }
    return result;
}

/***
 * 要不干脆直接在cgamedlg里面写交换逻辑吧，这样比较顺一点，这个地方就不再更新了
***/

#include "gamelogic.h"
#include <QRandomGenerator>

GameLogic::GameLogic(int dimension,int numOfStone) {
    this->dimension=dimension;
    this->numOfStone=numOfStone;
}

QVector<QVector<int>> GameLogic::Inimatrix(){
    QVector<QVector<int>> result(dimension,QVector<int>(dimension,0));
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            result[i][j]=QRandomGenerator::global()->bounded(numOfStone);
            //qDebug()<<"位置("<<i<<","<<j<<")"<<result[i][j];
        }
        //qDebug()<<Qt::endl;
    }
    return result;
}

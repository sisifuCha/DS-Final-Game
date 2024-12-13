#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <QVector>
#include <QTimer>

class GameLogic
{
public:
    GameLogic(int dimension,int numOfStone);

    int dimension;
    int numOfStone;

    QVector<QVector<int>> Inimatrix();
private:
    int coutSec;
    QTimer* timer;
    void updateLabel();
};

#endif // GAMELOGIC_H

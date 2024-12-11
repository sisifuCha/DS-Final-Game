#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <QVector>

class GameLogic
{
public:
    GameLogic(int dimension,int numOfStone);

    int dimension;
    int numOfStone;

    QVector<QVector<int>> Inimatrix();
};

#endif // GAMELOGIC_H

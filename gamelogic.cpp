#include "gamelogic.h"
#include <QRandomGenerator>
#include<QGraphicsPixmapItem>

using namespace std;
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

            //——————————————————TODO:保证初始化不能有连子————————————————————
        }
        //qDebug()<<Qt::endl;
    }
    return result;
}
//交换子,交换后消除子
///此方法已经废弃
void GameLogic::Switch(int x, int y, QVector<QVector<Stone> > *matrix, int *ClickedTimes,QGraphicsView* view)
{
    if(x+1<dimension && (*matrix)[x+1][y].isClicked){
        (*matrix)[x][y].isClicked=false;
        (*matrix)[x+1][y].isClicked=false;

        //交换
        Stone stone;
        stone=(*matrix)[x][y];
        (*matrix)[x][y]=(*matrix)[x+1][y];
        (*matrix)[x+1][y]=stone;
        //交换图片位置并更新
        (*matrix)[x][y].picItem->setPos(x*50,y*50);
        (*matrix)[x+1][y].picItem->setPos((x+1)*50,y*50);
        view->scene()->update();

        *ClickedTimes=0;
        //___________TODO 产生一条消子记录______________//
        Destroy(x,y,matrix,view);
        Destroy(x+1,y,matrix,view);//两个颜色可能交换完之后都能消除
        //(*matrix)[x][y].HideBorder(view->scene());
        //(*matrix)[x+1][y].HideBorder(view->scene());
    }
    if(y+1<dimension&&(*matrix)[x][y+1].isClicked){
        Stone stone;
        (*matrix)[x][y].isClicked=false;
        (*matrix)[x][y+1].isClicked=false;
        stone=(*matrix)[x][y];
        (*matrix)[x][y]=(*matrix)[x][y+1];
        (*matrix)[x][y+1]=stone;
        (*matrix)[x][y].picItem->setPos(x*50,y*50);
        (*matrix)[x][y+1].picItem->setPos(x*50,(1+y)*50);
        view->scene()->update();
        *ClickedTimes=0;
        Destroy(x,y,matrix,view);
        //Destroy(x,y+1,matrix,view);
        //(*matrix)[x][y].HideBorder(view->scene());
        //(*matrix)[x][y+1].HideBorder(view->scene());
    }
    if(x-1>=0&&(*matrix)[x-1][y].isClicked){
        (*matrix)[x][y].isClicked=false;
        (*matrix)[x-1][y].isClicked=false;
        Stone stone;
        stone=(*matrix)[x][y];
        (*matrix)[x][y]=(*matrix)[x-1][y];
        (*matrix)[x-1][y]=stone;
        (*matrix)[x][y].picItem->setPos(x*50,y*50);
        (*matrix)[x-1][y].picItem->setPos((x-1)*50,y*50);
        view->scene()->update();
        *ClickedTimes=0;
        Destroy(x,y,matrix,view);
        //Destroy(x-1,y,matrix,view);
        //(*matrix)[x][y].HideBorder(view->scene());
        //(*matrix)[x-1][y].HideBorder(view->scene());
    }
    if(y-1>=0&&(*matrix)[x][y-1].isClicked){
        (*matrix)[x][y].isClicked=false;
        (*matrix)[x][y-1].isClicked=false;
        Stone stone;
        stone=(*matrix)[x][y];
        (*matrix)[x][y]=(*matrix)[x][y-1];
        (*matrix)[x][y-1]=stone;
        (*matrix)[x][y].picItem->setPos(x*50,y*50);
        (*matrix)[x][y-1].picItem->setPos(x*50,(y-1)*50);
        view->scene()->update();
        *ClickedTimes=0;
        Destroy(x,y,matrix,view);
        //Destroy(x,y-1,matrix,view);
        //(*matrix)[x][y].HideBorder(view->scene());
        //(*matrix)[x][y-1].HideBorder(view->scene());
    }
}
//消除子
void GameLogic::Destroy(int x, int y, QVector<QVector<Stone>> *matrix, QGraphicsView *view)
{
    //创建一个存放相同石子的容器
    QVector<Stone*> CollectedStones;
    //将所有联通的相同石子放入容器
    preorderTraversal((*matrix)[x][y].category,x,y,matrix,&CollectedStones);
    //清除容器中的石子
    if(CollectedStones.size()>1)
        for(Stone* stone:CollectedStones){
            qDebug()<<stone->category<<'\n';
            stone->picItem->setPixmap(QPixmap());
            view->scene()->update();
        }
    else if(CollectedStones.size()==1){
        CollectedStones[0]->isEmpty=false;
        CollectedStones[0]->isClicked=false;
    }
}

void GameLogic::preorderTraversal(int category,int x, int y, QVector<QVector<Stone>> *matrix, QVector<Stone*> *CollectedStones)
{
    //qDebug()<<"debug1";
    //(*matrix)[x][y].isEmpty=true;                                           ///这个要放这里吗？
    //(*CollectedStones).append(&(*matrix)[x][y]);        //存放当前要消除的节点

    //__________________递归寻找相邻的节点，要求类型相同_________________//
    QVector<Stone*> temp(20);//临时的数组，用来检查水平或者垂直方向的消除宝石是否到达3个

    //向水平查看是否有连续的种类相同的宝石
    int check_x1=x;
    int check_y1=y;
    //向左查看
    while(check_x1>=0&&check_x1<dimension && (*matrix)[check_x1][y].category==category){
        temp.append(&(*matrix)[check_x1][y]);
        check_x1--;
    }
    //向右查看
    check_x1=x;
    while(check_x1>=0&&check_x1<dimension && (*matrix)[check_x1][y].category==category){
        (*CollectedStones).append(&(*matrix)[check_x1][y]);
        check_x1++;
    }//判断水平方向是否到达三个
    if(temp.size()>=3){
        for(Stone* eachElement:temp){
            (*CollectedStones).append(eachElement);
            eachElement->isEmpty=true;
        }
    }
    temp.clear();


    //向上查看
    while(check_y1>=0&&check_y1<dimension && (*matrix)[x][check_y1].category==category){
        temp.append(&(*matrix)[x][check_y1]);
        check_y1--;
    }
    //向下查看
    check_y1=y;
    while(check_y1>=0&&check_y1<dimension && (*matrix)[x][check_y1].category==category){
        (*CollectedStones).append(&(*matrix)[x][check_y1]);
        check_y1++;
    }//判断垂直方向是否到达三个
    if(temp.size()>=3){
        for(Stone* eachElement:temp){
            (*CollectedStones).append(eachElement);
            eachElement->isEmpty=true;
        }
    }
    temp.clear();

}

//查看是否三连子
bool GameLogic::search(Stone* stoneToSearch, Stone *objcetStone,  QVector<QVector<Stone>>& matrix){
    //站在stoneToSearch的视角上，判断它交换之后  有没有三连子。因为交换涉及另一个石头objcetStone的种类，所以更改stoneToSearch原式位置的category

    QVector<QVector<Stone>> tempCopyMatrix=matrix;
    //int newCategory=objcetStone->category;
    int targetcategory=stoneToSearch->category;///目标种类

    /*首先做种类上的交换,然后从交换后的位置开始检查，每个方向每个宝石的种类是否和目标种类匹配*/

    //交换
    Stone temp;
    temp=tempCopyMatrix[stoneToSearch->xLoc][stoneToSearch->yLoc];
    tempCopyMatrix[stoneToSearch->xLoc][stoneToSearch->yLoc]=tempCopyMatrix[objcetStone->xLoc][objcetStone->yLoc];
    tempCopyMatrix[objcetStone->xLoc][objcetStone->yLoc]=temp;

    int check_x1=objcetStone->xLoc;//交换后位置
    int check_y1=objcetStone->yLoc;
    bool horizenEnough=false;
    bool verticalEnough=false;


    int count=1;
    //向左查看
    while(check_x1>=1&&check_x1<dimension && tempCopyMatrix[check_x1-1][objcetStone->yLoc].category==targetcategory){
        //temp.append(&tempCopyMatrix[check_x1][y]);
        count++;
        check_x1--;
    }
    //向右查看
    check_x1=objcetStone->xLoc;
    while(check_x1>=0&&check_x1<dimension-1 && tempCopyMatrix[check_x1+1][objcetStone->yLoc].category==targetcategory){
        //temp.append(&tempCopyMatrix[check_x1][y]);
        count++;
        check_x1++;
    }//判断水平方向是否到达三个
    if(count>=3){
        horizenEnough=true;
    }
    //temp.clear();
    check_x1=objcetStone->xLoc;
    qDebug()<<"GameLogic::search检查"<<stoneToSearch->category<<"的宝石交换后水平够不够三连子"<<horizenEnough;
    count=1;
    //向上查看
    while(check_y1>=1&&check_y1<dimension && tempCopyMatrix[objcetStone->xLoc][check_y1-1].category==targetcategory){
        //temp.append(&tempCopyMatrix[x][check_y1]);
        count++;
        check_y1--;
    }
    //向下查看
    check_y1=objcetStone->yLoc;
    while(check_y1>=0&&check_y1<dimension-1 && tempCopyMatrix[objcetStone->xLoc][check_y1+1].category==targetcategory){
        //temp.append(&tempCopyMatrix[x][check_y1]);
        count++;
        check_y1++;
    }//判断垂直方向是否到达三个
    if(count>=3){
        verticalEnough=true;
    }
    //temp.clear();
    qDebug()<<"GameLogic::search检查"<<stoneToSearch->category<<"的宝石交换后竖直够不够三连子"<<verticalEnough;
    return horizenEnough||verticalEnough;
}

//交换后消子
void GameLogic::swapStone(QPair<int,int>* leStone,QPair<int,int>*riStone,QVector<QVector<Stone>>* matrix,QGraphicsView* view,QVector<Stone*>* collection1,QVector<Stone*>* collection2){
    if((*matrix)[leStone->first][leStone->second].category!=(*matrix)[riStone->first][riStone->second].category){
    //交换lStone,rStone
    Stone temp;
    temp=(*matrix)[leStone->first][leStone->second];
    (*matrix)[leStone->first][leStone->second]=(*matrix)[riStone->first][riStone->second];
    (*matrix)[riStone->first][riStone->second]=temp;
    //修改这个
    int x1=leStone->first;
    int y1=leStone->second;
    int x2=riStone->first;
    int y2=riStone->second;
    (*matrix)[x2][y2].xLoc = (*matrix)[x1][y1].xLoc;
    (*matrix)[x2][y2].yLoc = (*matrix)[x1][y1].yLoc;
    (*matrix)[x1][y1].xLoc = temp.xLoc;
    (*matrix)[x1][y1].yLoc = temp.yLoc;
    //QGraphicsPixmapItem* tempItem = (*matrix)[x1][y1].picItem;
    //(*matrix)[x1][y1].picItem = (*matrix)[x2][y2].picItem;
    //(*matrix)[x2][y2].picItem = tempItem;

    (*matrix)[leStone->first][leStone->second].picItem->setPos(leStone->first*50,leStone->second*50);
    (*matrix)[riStone->first][riStone->second].picItem->setPos(riStone->first*50,riStone->second*50);;

    view->scene()->update();
    qDebug()<<"GameLogic::swapStone:交换";
    //————————————————————消子————————————————————
    /*分别检查交换后的两个位置，判断上下左右相邻的元素是否有同色*/

    collectSame(&((*matrix)[leStone->first][leStone->second]),collection1,matrix);
    collectSame(&((*matrix)[riStone->first][riStone->second]),collection2,matrix);
    qDebug()<<"GameLogic::swapStone collectSame之后：collection1"<<collection1->size();
    qDebug()<<"GameLogic::swapStone collectSame之后：collection2"<<collection2->size();
}
}

//
void  GameLogic::collectSame(Stone* currentStone,QVector<Stone*>* collection,QVector<QVector<Stone>>* matrix){
    int xcount=1;
    int ycount=1;
    int targetCategory=currentStone->category;
    qDebug()<<"待删除的宝石种类是"<<targetCategory;
    int x=currentStone->xLoc;
    int y=currentStone->yLoc;
    qDebug()<<"被选中的宝石坐标是"<<x<<y;

    collection->push_back(&(*matrix)[x][y]);

    while(x>=1&&x<dimension&&(*matrix)[x-1][y].category==targetCategory){
        qDebug()<<"向左搜索";
        collection->push_back(&(*matrix)[x-1][y]);
        qDebug()<<x-1<<" "<<y<<"被添加到待删集合里";
        x--;
        xcount++;
    }
    x=currentStone->xLoc;
    while(x>=0&&x<dimension-1&&(*matrix)[x+1][y].category==targetCategory){
        qDebug()<<"向右搜索";
        collection->push_back(&(*matrix)[x+1][y]);
        qDebug()<<x+1<<" "<<y<<"被添加到待删集合里";
        x++;
        xcount++;
    }

    x=currentStone->xLoc;

    if(!(xcount>=3)){
        qDebug()<<"横向不足三个";
        collection->clear();
        collection->push_back(&(*matrix)[x][y]);
    }
    while(y>=1&&y<dimension&&(*matrix)[x][y-1].category==targetCategory){
        qDebug()<<"向上搜索";
        collection->push_back(&(*matrix)[x][y-1]);
        qDebug()<<x<<" "<<y-1<<"被添加到待删集合里";
        y--;
        ycount++;
    }

    y=currentStone->yLoc;
    while(y>=0&&y<dimension-1&&(*matrix)[x][y+1].category==targetCategory){
        qDebug()<<"向下搜索";
        collection->push_back(&(*matrix)[x][y+1]);
        qDebug()<<x<<" "<<y+1<<"被添加到待删集合里";
        y++;
        ycount++;
    }
    if(ycount<3&&y!=1){
        qDebug()<<"纵向不足三个";
        for(int i=1;i<ycount;i++){
            collection->pop_back();
        }
    }
    if(xcount>=3||ycount>=3) {
        qDebug()<<"添加完毕，待删除元素如下";
        for(int i=0;i<collection->size();i++){
            qDebug()<<(*collection)[i]->xLoc<<(*collection)[i]->yLoc;
        }
    }
    else {
        collection->clear();
        qDebug()<<"无可删除元素";
    }
}

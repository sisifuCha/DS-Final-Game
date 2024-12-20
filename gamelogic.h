#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <QVector>
#include <QTimer>
#include<QGraphicsView>
#include<QRectF>
#include<QGraphicsRectItem>
struct Stone {
    int category; // 宝石种类
    QGraphicsPixmapItem* picItem;
    //QGraphicsRectItem* borderItem; // 边框项
    bool isClicked;
    bool isEmpty;

    int xLoc;
    int yLoc;//x,y都是索引。这个参数使得可以根据stone查询自己在矩阵的位置
    /*
    void ShowBorder(QGraphicsScene* scene) {
        // 假设picItem的位置和大小已经设置，并且它已经被添加到scene中
        QRectF picRect = picItem->boundingRect();

        // 创建一个与picItem相同位置和大小的矩形项作为边框
        borderItem = new QGraphicsRectItem(picRect, nullptr);
        QPen pen(Qt::red, 2); // 设置边框的宽度和颜色
        borderItem->setPen(pen);
        borderItem->setBrush(Qt::NoBrush); // 不填充内部
        borderItem->setPos(picItem->pos());
        // 将边框项添加到场景中
        if (scene) {
            scene->addItem(borderItem);
        }
        qDebug()<<"showborder";
        qDebug()<<borderItem->pos();
    }*/

    /*
    void HideBorder(QGraphicsScene* scene) {
        // 从场景中移除边框项
        if (borderItem && scene) {
            scene->removeItem(borderItem);
            // 可选：删除borderItem以释放内存（如果它不是由智能指针管理的）
            // delete borderItem;
            // 注意：如果在这里删除了borderItem，那么需要在结构体中添加一个标志来防止重复删除
            // 或者确保HideBorder不会被多次调用对于同一个borderItem。
            // 在这个例子中，我们假设borderItem的生命周期由外部管理（例如，由拥有Stone结构体的对象管理）。
        }
        // 如果决定在HideBorder中删除borderItem，那么需要将borderItem设置为nullptr
        // 以防止悬挂指针。但是，在这个例子中，我们不做这个假设。
    }*/
}typedef Stone;
// 注意：在实际使用中，您可能需要处理Stone结构体的内存管理，
// 特别是当您动态分配Stone实例时。此外，当不再需要边框时，
// 您应该确保删除borderItem以避免内存泄漏


class GameLogic
{
public:
    GameLogic(int dimension,int numOfStone);

    int dimension;
    int numOfStone;

    QVector<QVector<int>> Inimatrix();
    //交换子,abandon
    void Switch(int x,int y,QVector<QVector<Stone>>* matrix,int* ClickedTimes,QGraphicsView* view);
    //消除子
    void Destroy(int x,int y,QVector<QVector<Stone>>* matrix,QGraphicsView* view);

    //查看子是否三连子
    bool search(Stone*,Stone* ,QVector<QVector<Stone>>&matrix);
    //交换子
    void swapStone(QPair<int,int>*,QPair<int,int>*,QVector<QVector<Stone>>* matix,QGraphicsView* view,QVector<Stone*>,QVector<Stone*>);
private:
    int coutSec;//计时器
    QTimer* timer;
    void updateLabel();
    void preorderTraversal(int category,int x, int y, QVector<QVector<Stone> > *matrix,QVector<Stone*>* CollectedStones);
    void collectSame(Stone*,QVector<Stone*>* collection,QVector<QVector<Stone>>* matrix);//消子，上下左右遍历，收集相同元素的子再容器里
};

#endif // GAMELOGIC_H

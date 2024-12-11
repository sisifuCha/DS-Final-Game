#include "cgamedlg.h"
#include "ui_cgamedlg.h"
#include <QMouseEvent>


CGameDlg::CGameDlg(QWidget *parent,int dimension,int numOfStone)
    : QDialog(parent)
    , ui(new Ui::CGameDlg)
{
    ui->setupUi(this);

    this->dimension=dimension;
    this->numOfStone=numOfStone;
    //qDebug()<<"GameWidget:dimension"<<dimension<<"numOfStone"<<numOfStone;
    QGraphicsScene* graphicsScene=new QGraphicsScene(this);
    ui->graphicsView->setScene(graphicsScene);

    /*初始化自定义的宝石图片数组，这里先用本地的代替*/
    stonePic.resize(6);
    stonePic[0]=":/pics/resource/1.png";
    stonePic[1]=":/pics/resource/2.png";
    stonePic[2]=":/pics/resource/3.png";
    stonePic[3]=":/pics/resource/4.png";
    stonePic[4]=":/pics/resource/5.png";
    stonePic[5]=":/pics/resource/6.png";

    //qDebug()<<"GameWidget:测试点2";
    gLogic=new GameLogic(dimension,numOfStone);
    /*初始化矩阵 每次生成随机数，设置Qlabel位置和icon*/
    QVector<QVector<int>> temp(dimension, QVector<int>(dimension, 0));
    temp=gLogic->Inimatrix();//暂时保存一个int类型的二维数组
    matrix.resize(dimension);
    //qDebug()<<"GameWidget:测试点3";
    /*for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            qDebug()<<temp[i][j];
        }
    }*/
    /*****************在matrix里面添加元素***************/
    /*****************在matrix里面添加元素***************/
    for(int i=0;i<dimension;i++){
        matrix[i].resize(dimension);
        //qDebug()<<"GameWidget:测试点4";
        qDebug()<<"matrix[i]大小"<<matrix[i].size();
        for(int j=0;j<dimension;j++){
            //qDebug()<<"GameWidget:测试点5";
            matrix[i][j].category=temp[i][j];
            matrix[i][j].isClicked=false;
            matrix[i][j].isEmpty=false;
            //qDebug()<<"GameWidget:测试点6";
            QPixmap pmap;

            //加载路径检查
            if (!pmap.load(stonePic[matrix[i][j].category])) {
                qDebug() << "Failed to load image:" << stonePic[matrix[i][j].category];
            }
            //qDebug()<<"GameWidget:测试点7";
            matrix[i][j].picItem = new QGraphicsPixmapItem();
            matrix[i][j].picItem->setPixmap(pmap.scaled(50,50));
            matrix[i][j].picItem->setPos(i*50,j*50);
            graphicsScene->addItem(matrix[i][j].picItem);
            //qDebug()<<"位置("<<i<<","<<j<<")"<<matrix[i][j].category;
        }
        //qDebug()<<"GameWidget:测试点8";
        //qDebug()<<Qt::endl;
    }
    /*——————————消子和交换初始化——————————*/
    swapStones.resize(2);
    swapStones[0].category=0;swapStones[0].picItem=nullptr;//存放鼠标左键点击的引用
    swapStones[1].category=0;swapStones[1].picItem=nullptr;
    //点击槽事件
    //connect(ui->graphicsView, &CGameDlg::mousePressEvent, this, &CGameDlg::onGraphicsViewClicked);
}

CGameDlg::~CGameDlg()
{
    delete ui;
}
void CGameDlg::mousePressEvent(QMouseEvent* event) {
    QPointF scenePos = ui->graphicsView->mapToScene(event->pos());
    scenePos.setX(scenePos.x()-30);//此处修改得到相对graphicsView的坐标，虽然我不知道为什么上一行出了问题
    scenePos.setY(scenePos.y()-80);//但修改以后矩阵索引打印出来是对的
    qDebug() << "Mouse clicked at scene position:" << scenePos;

    //判断鼠标单击是否在scene里面
    if(!ui->graphicsView->scene()->sceneRect().contains(scenePos)){
        qDebug() << "Clicked outside the scene.————ERR From CGameDlg::onGraphicsViewClicked";
        return;
    }
    //计算矩阵的行列索引
    int x = static_cast<int>(scenePos.x()) / 50;
    int y = static_cast<int>(scenePos.y()) / 50;

    // 确保点击的位置在矩阵范围内,被点击的mitrix[x][y]的isChosen为true，已经为true再点击一次isChosen为false;
    if (x >= 0 && x < dimension && y >= 0 && y < dimension) {
        if(event->button() == Qt::LeftButton){
            swapStones[0]=matrix[x][y];
            qDebug() << "CGameDlg::onGraphicsViewClicked : 鼠标左键点击了" << x << y;
            //看这个坐标的stone是否非空（即是否被削掉了）
            if(matrix[x][y].isEmpty) return;
            //如果非空，判断它是否被点击过，然后视情况更改isClicked属性
            if(matrix[x][y].isClicked==true){
                matrix[x][y].isClicked=false;
                //被选中个数减1
                ClickedTimes--;
            }
            else
            {
                //如果没被选过，则看场上被选中的是否小于2
                if(ClickedTimes<2){
                matrix[x][y].isClicked=true;
                //被选中个数数加1
                ClickedTimes++;
                }
                else return;
            }
            //接着判断其周围有无被点击的stone，有则与其交换图片,然后给场景贴新的图（不能用刷新!!!!!!!!!）
            isClickedAround(x,y);

        }else if(event->button() == Qt::RightButton){
            swapStones[1]=matrix[x][y];
            qDebug() << "CGameDlg::onGraphicsViewClicked : 鼠标右键点击了" << x << y;
        }
    }
}

void CGameDlg::isClickedAround(int x, int y)
{
    if(x+1<dimension&&matrix[x+1][y].isClicked){
        matrix[x][y].isClicked=false;
        matrix[x+1][y].isClicked=false;
        Stone stone;
        stone=matrix[x][y];
        matrix[x][y]=matrix[x+1][y];
        matrix[x+1][y]=stone;
        matrix[x][y].picItem->setPos(x*50,y*50);
        matrix[x+1][y].picItem->setPos((x+1)*50,y*50);
        putStone(x,y);
        putStone(x+1,y);
        ClickedTimes=0;
    }
    if(y+1<dimension&&matrix[x][y+1].isClicked){
        Stone stone;
        matrix[x][y].isClicked=false;
        matrix[x][y+1].isClicked=false;
        stone=matrix[x][y];
        matrix[x][y]=matrix[x][y+1];
        matrix[x][y+1]=stone;
        matrix[x][y].picItem->setPos(x*50,y*50);
        matrix[x][y+1].picItem->setPos(x*50,(1+y)*50);
        putStone(x,y);
        putStone(x,y+1);
        ClickedTimes=0;
    }
    if(x-1>=0&&matrix[x-1][y].isClicked){
        matrix[x][y].isClicked=false;
        matrix[x-1][y].isClicked=false;
        Stone stone;
        stone=matrix[x][y];
        matrix[x][y]=matrix[x-1][y];
        matrix[x-1][y]=stone;
        matrix[x][y].picItem->setPos(x*50,y*50);
        matrix[x-1][y].picItem->setPos((x-1)*50,y*50);
        putStone(x-1,y);
        putStone(x,y);
        ClickedTimes=0;
    }
    if(y-1>=0&&matrix[x][y-1].isClicked){
        matrix[x][y].isClicked=false;
        matrix[x][y-1].isClicked=false;
        Stone stone;
        stone=matrix[x][y];
        matrix[x][y]=matrix[x][y-1];
        matrix[x][y-1]=stone;
        matrix[x][y].picItem->setPos(x*50,y*50);
        matrix[x][y-1].picItem->setPos(x*50,(y-1)*50);
        putStone(x,y-1);
        putStone(x,y);
        ClickedTimes=0;
    }
}
void CGameDlg::putStone(int x, int y)
{
    ui->graphicsView->scene()->addItem(matrix[x][y].picItem);
    ui->graphicsView->scene()->update();
}

void CGameDlg::on_SwapButton_clicked()//交换按钮
{

}


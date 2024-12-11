#include "gameDlg.h"
#include "ui_gameDlg.h"
#include <QVector>
#include <qpixmap.h>

GameDlg::GameDlg(QWidget *parent,int dimension,int numOfStone)
    : QWidget(parent)
    , ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    this->dimension=dimension;
    this->numOfStone=numOfStone;
    //qDebug()<<"GameWidget:dimension"<<dimension<<"numOfStone"<<numOfStone;
    QGraphicsScene* graphicsScene=new QGraphicsScene(this);
    ui->graphicsView->setScene(graphicsScene);

    /*初始化自定义的宝石图片数组，这里先用本地的代替*/
    stonePic.resize(6);
    stonePic[0]=":/resource/1.png";
    stonePic[1]=":/resource/2.png";
    stonePic[2]=":/resource/3.png";
    stonePic[3]=":/resource/4.png";
    stonePic[4]=":/resource/5.png";
    stonePic[5]=":/resource/6.png";

    //qDebug()<<"GameWidget:测试点2";
    gLogic=new GameLogic(dimension,numOfStone);
    /*初始化矩阵 每次生成随机数，设置Qlabel位置和icon*/
    QVector<QVector<int>> temp(dimension, QVector<int>(dimension, 0));
    temp=gLogic->Inimatrix();//暂时保存一个int类型的二维数组
    matrix.resize(dimension);
    //qDebug()<<"GameWidget:测试点3";
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            qDebug()<<temp[i][j];
        }
    }

    for(int i=0;i<dimension;i++){
        matrix[i].resize(dimension);
        //qDebug()<<"GameWidget:测试点4";
        qDebug()<<"matrix[i]大小"<<matrix[i].size();
        for(int j=0;j<dimension;j++){
            //qDebug()<<"GameWidget:测试点5";
            matrix[i][j].category=temp[i][j];
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
            qDebug()<<"位置("<<i<<","<<j<<")"<<matrix[i][j].category;
        }
        //qDebug()<<"GameWidget:测试点8";
        qDebug()<<Qt::endl;
    }
}

GameDlg::~GameDlg()
{
    delete ui;
}

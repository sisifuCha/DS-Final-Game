#include "cgamedlg.h"
#include "ui_cgamedlg.h"
#include <QMouseEvent>


CGameDlg::CGameDlg(QWidget *parent,int dimension,int numOfStone,int gemType,int backChoice)
    : QDialog(parent)
    , ui(new Ui::CGameDlg)
{
    ui->setupUi(this);

    this->dimension=dimension;
    this->numOfStone=numOfStone;
    this->gemType=gemType;
    this->backChoice=backChoice;
    //qDebug()<<"GameWidget:dimension"<<dimension<<"numOfStone"<<numOfStone;
    QGraphicsScene* graphicsScene=new QGraphicsScene(this);
    ui->graphicsView->setScene(graphicsScene);
    ui->graphicsView->setStyleSheet("background: transparent");
    ui->graphicsView->setFrameStyle(QFrame::NoFrame);
    graphicsScene->setBackgroundBrush(Qt::transparent);
    lclicktime=0;
    rclicktime=0;


    //计时器
    timer=new QTimer(this);
    secCount=0;
    connect(timer, &QTimer::timeout, this, &CGameDlg::updateLabel);
    timeLimit=10;
    timer->start(1000);

    /*初始化自定义的宝石图片数组*/
    iniPicRescource();
    QPalette palette;
    backGround.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    palette.setBrush(QPalette::Window, backGround);
    setPalette(palette);

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
    QPixmap pmap;
    for(int i=0;i<dimension;i++){
        matrix[i].resize(dimension);
        for(int j=0;j<dimension;j++){
            matrix[i][j].category=temp[i][j];
            matrix[i][j].isClicked=false;
            matrix[i][j].isEmpty=false;
            matrix[i][j].xLoc=i;
            matrix[i][j].yLoc=j;


            //加载路径检查
            if (!pmap.load(stonePic[matrix[i][j].category])) {
                qDebug() << "CgameDlg.cpp:Failed to load image:" << stonePic[matrix[i][j].category];
            }
            matrix[i][j].picItem = new QGraphicsPixmapItem();
            matrix[i][j].picItem->setPixmap(pmap.scaled(50,50));
            matrix[i][j].picItem->setPos(i*50,j*50);
            graphicsScene->addItem(matrix[i][j].picItem);
        }
        //qDebug()<<"GameWidget:测试点8";
        //qDebug()<<Qt::endl;
    }


    /*——————————消子和交换初始化——————————*/
    leftChooseStone=new Stone(matrix[0][0]);
    rightChooseStone=new Stone(matrix[0][0]);


    /*——————————显示的两个borderItem初始化——————————————*/
    QRectF picRect = matrix[0][0].picItem->boundingRect();
    lborderItem = new QGraphicsRectItem(picRect, nullptr);
    rborderItem = new QGraphicsRectItem(picRect, nullptr);

    QPen pen(Qt::red, 2); // 置边框的宽度和颜色
    lborderItem->setPen(pen);
    lborderItem->setBrush(Qt::NoBrush); //不填充内部
    lborderItem->setPos(matrix[0][0].picItem->pos());
    rborderItem->setPen(pen);
    rborderItem->setBrush(Qt::NoBrush); //不填充内部
    rborderItem->setPos(matrix[0][0].picItem->pos());
    graphicsScene->addItem(lborderItem);
    graphicsScene->addItem(rborderItem);

    //点击槽事件
    //connect(ui->graphicsView, &CGameDlg::mousePressEvent, this, &CGameDlg::onGraphicsViewClicked);
}

CGameDlg::~CGameDlg()
{
    delete ui;
}

//初始化宝石图片素材
void CGameDlg::iniPicRescource(){
    stonePic.resize(6);
    if(gemType==0){
        stonePic[0]=":/pics/resource/gem1.png";
        stonePic[1]=":/pics/resource/gem2.png";
        stonePic[2]=":/pics/resource/gem3.png";
        stonePic[3]=":/pics/resource/gem4.png";
        stonePic[4]=":/pics/resource/gem5.png";
        stonePic[5]=":/pics/resource/gem6.png";
    }else if(gemType==1){
        stonePic[0]=":/pics/resource/gemBlue.png";
        stonePic[1]=":/pics/resource/gemGreen.png";
        stonePic[2]=":/pics/resource/gemOrange.png";
        stonePic[3]=":/pics/resource/gemPurple.png";
        stonePic[4]=":/pics/resource/gemRed.png";
        stonePic[5]=":/pics/resource/gemWhite.png";
    }else if(gemType==2){
        stonePic[0]=":/pics/resource/mine1.png";
        stonePic[1]=":/pics/resource/mine2.png";
        stonePic[2]=":/pics/resource/mine3.png";
        stonePic[3]=":/pics/resource/mine4.png";
        stonePic[4]=":/pics/resource/mine5.png";
        stonePic[5]=":/pics/resource/mine6.png";
    }

    if(backChoice==0){
        backGround.load(":/pics/resource/back1.png");
    }else if(backChoice==1){
        backGround.load(":/pics/resource/back2.png");
    }else if(backChoice==2){
        backGround.load(":/pics/resource/back3.png");
    }else if(backChoice==3){
        backGround.load(":/pics/resource/back4.png");
    }else if(backChoice==4){
        backGround.load(":/pics/resource/back5.png");
    }else if(backChoice==5){
        backGround.load(":/pics/resource/back6.png");
    }else if(backChoice==6){
        backGround.load(":/pics/resource/back7.png");
    }else{
        backGround.load(":/pics/resource/back8.png");
    }
}

//点击图标选中宝石
void CGameDlg::mousePressEvent(QMouseEvent* event) {
    QRect viewGeometry = ui->graphicsView->geometry();
    QPointF scenePos = ui->graphicsView->mapToScene(event->pos());
    scenePos.setX(scenePos.x()-viewGeometry.left());//此处修改得到相对graphicsView的坐标
    scenePos.setY(scenePos.y()-viewGeometry.top());


    //判断鼠标单击是否在scene里面
    if(!ui->graphicsView->scene()->sceneRect().contains(scenePos)){
        qDebug() << "鼠标没有点击任何坐标.————ERR From CGameDlg::onGraphicsViewClicked";
        return;
    }
    //计算矩阵的行列索引
    int x = static_cast<int>(scenePos.x()) / 50;
    int y = static_cast<int>(scenePos.y()) / 50;

    //确保点击的位置在矩阵范围内,被点击的matrix[x][y]的isChosen为true，已经为true再点击一次isChosen为false;
    if (x >= 0 && x < dimension && y >= 0 && y < dimension) {
        if(event->button() == Qt::LeftButton){

            qDebug() << "CGameDlg::mousePressEvent : 鼠标左键点击了" << x << y;
            //看这个坐标的stone是否非空（即是否被削掉了）
            //if(matrix[x][y].isEmpty) return;
            (*leftChooseStone)=matrix[x][y];
            leftChoosePair.first=x;
            leftChoosePair.second=y;

            lborderItem->setVisible(true);
            lborderItem->setPos(x*50,y*50);
            qDebug()<<"leftChoosePair"<<(leftChoosePair).first<<leftChoosePair.second;
            /*
            if(lclicktime%2==0){
                //左击选中
                lclicktime++;
                //显示“选中”效果
                /*if (lborderItem) {
                    ui->graphicsView->scene()->removeItem(lborderItem);
                    delete lborderItem;
                }
                lborderItem =ui->graphicsView->scene()->addRect(picRect,QPen(Qt::red, 2));
                lborderItem->setPen(QPen(Qt::red, 2));

                lborderItem->setVisible(true);
                lborderItem->setPos(x*50,y*50);
                //lborderItem->setVisible(true);
                //ui->graphicsView->scene()->addItem(lborderItem);
                leftChooseStone->isClicked=true;
                //ui->graphicsView->scene()->update();

            }//用来双击消除框
            else{
                //左击取消
                lclicktime--;
                lborderItem->setVisible(false);
                //ui->graphicsView->scene()->removeItem(lborderItem);
                //(*leftChooseStone).isClicked=false;

                //清除临时空间
                leftChooseStone->isClicked=false;

            }*/
            //如果非空，判断它是否被点击过，然后视情况更改isClicked属性
            /*
            if(matrix[x][y].isClicked==true){
                matrix[x][y].isClicked=false;
                matrix[x][y].HideBorder(ui->graphicsView->scene());
                //被选中个数减1
                ClickedTimes--;
            }
            else{
                //如果没被选过，则看场上被选中的是否小于2
                if(ClickedTimes<2){
                    matrix[x][y].isClicked=true;
                    matrix[x][y].ShowBorder(ui->graphicsView->scene());
                    ClickedTimes++;
                    //被选中个数数加1
                }
                else return;
            }
            //接着判断其周围有无被点击的stone，有则与其交换图片,然后给场景贴新的图（不能用刷新!!!!!!!!!）
            //isClickedAround(x,y);
            //999this->gLogic->Switch(x,y,&matrix,&ClickedTimes,ui->graphicsView);
            */
        }else if(event->button() == Qt::RightButton){
            (*rightChooseStone)=matrix[x][y];
            qDebug() << "CGameDlg::onGraphicsViewClicked : 鼠标右键点击了" << x << y;
            //if(matrix[x][y].isEmpty) return;
            //(*rightChooseStone)=matrix[x][y];
            rightChoosePair.first=x;
            rightChoosePair.second=y;

            rborderItem->setVisible(true);
            rborderItem->setPos(x*50,y*50);
            qDebug()<<"rightChooseStone"<<rightChoosePair.first<<rightChoosePair.second;
            /*
            if(rclicktime%2==0){
                //qDebug()<<"上面";
                rclicktime++;

                rightChooseStone->isClicked=true;

            }else{
                //qDebug()<<"下面";
                rclicktime--;
                rborderItem->setVisible(false);
                rightChooseStone->isClicked=false;
            }*/

             /*
             if((*rightChooseStone).isClicked==false){
                 (*rightChooseStone).isClicked=true;
                 //显示“选中”效果
                 QRectF picRect = matrix[x][y].picItem->boundingRect();
                 rborderItem=new QGraphicsRectItem(picRect, nullptr);
             }//用来双击消除框
             else{
                 (*rightChooseStone).isClicked=false;
                 if(ui->graphicsView->scene() && lborderItem)
                     ui->graphicsView->scene()->removeItem(lborderItem);
                 rightChooseStone->category=0;rightChooseStone->picItem=nullptr;
             }*/
        }
    }
}



//计时器方法
void CGameDlg::updateLabel(){
    //判断是否暂停 isPaused
    if(secCount<timeLimit){
        secCount++;
        ui->timesLabel->setText(QString("剩余时间: %1 秒").arg(timeLimit-secCount));
    }else{
        timer->disconnect();
        //展示失败信息
    }
}

void CGameDlg::on_SwapButton_clicked()
{
    //交换子
    //获取当前“选中”子的状态
    qDebug()<<"按下swap";
    /*
    if(!leftChoosePair||!rightChooseStone){
        //两个字有一个没选中，点击按钮清空所有选中状态
        qDebug()<<"没选中子！！！！！！！！！！！！！！！";
        leftChooseStone->isClicked=false;
        rightChooseStone->isClicked=false;
        lborderItem->setVisible(false);
        rborderItem->setVisible(false);
        rclicktime=0;
        lclicktime=0;
        qDebug()<<"CGameDlg::on_SwapButton_clicked:两个子都被清空了";
        return;
    }else{*/
        //_______1判断两个是否相邻
        bool isAdjacent=false;
        bool hasThreeCombo=false;
        int xL=leftChoosePair.first;
        int yL=leftChoosePair.second;
        int xR=rightChoosePair.first;
        int yR=rightChoosePair.second;
        if((xL==xR&&qAbs(yL-yR)==1)||(yL==yR&&qAbs(xL-xR)==1)){
            isAdjacent=true;}
            //_______2判断两个交换之后能否连成三个消除
        if(gLogic->search(leftChooseStone,rightChooseStone,matrix)||
            gLogic->search(rightChooseStone,leftChooseStone,matrix)){
            hasThreeCombo=true;
        }
        qDebug()<<"CGameDlg::on_SwapButton_clicked邻接判断"<<isAdjacent;
        qDebug()<<"CGameDlg::on_SwapButton_clicked三联判断"<<hasThreeCombo;

        if(isAdjacent && hasThreeCombo){
            //交换
            gLogic->swapStone(&leftChoosePair,&rightChoosePair,&matrix,ui->graphicsView,collection1,collection2);
            ui->graphicsView->scene()->update();
            QPair<int,int> tempP;
            tempP=leftChoosePair;
            leftChoosePair=rightChoosePair;
            rightChoosePair=tempP;
            //重置选中信息
            Stone temp;
            temp=(*leftChooseStone);
            (*leftChooseStone)=(*rightChooseStone);
            (*rightChooseStone)=temp;

            lborderItem->setVisible(false);
            rborderItem->setVisible(false);
            rclicktime=0;
            lclicktime=0;
            qDebug()<<"CGameDlg::on_SwapButton_clicked 交换成功";
            return;
        }else{
            //重置选中信息
            leftChooseStone->isClicked=false;
            rightChooseStone->isClicked=false;
            (*leftChooseStone)=matrix[0][0];
            (*rightChooseStone)=matrix[0][0];
            lborderItem->setVisible(false);
            rborderItem->setVisible(false);
            rclicktime=0;
            lclicktime=0;
            qDebug()<<"CGameDlg::on_SwapButton_clicked 交换失败";
            return;
        }
    //}
}


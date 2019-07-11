#include "snakewidget.h"
#define ROW 13
#define COL 16
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 0

snakeWidget::snakeWidget(QWidget *parent) : QWidget(parent)
{
    //菜单栏
    QMenuBar *mBar =new QMenuBar(this);

    //添加菜单
    QMenu *pFile =mBar->addMenu("难度");

    //添加菜单项，添加动作
    QAction *pnewc = pFile->addAction("初级");

    connect(pnewc,&QAction::triggered,
            [=]()
            {
                  speed=400;
            }
            );

    QAction *pnewz = pFile->addAction("中级");

    connect(pnewz,&QAction::triggered,
            [=]()
            {
                  speed=300;
            }
            );

    QAction *pnewg = pFile->addAction("高级");

    connect(pnewg,&QAction::triggered,
            [=]()
            {
                  speed=200;
            }
            );

    QAction *pnewh = pFile->addAction("骨灰级");

    connect(pnewh,&QAction::triggered,
            [=]()
            {
                  speed=100;
            }
            );
    speed=400;
    this->setAutoFillBackground(true);
    this->resize(1000,605);
    this->setWindowIcon(QIcon("img/WindowPicture.jpg"));//图标
    this->setWindowTitle("贪吃蛇");//标题（可能有乱码）

    snake[0][0]=qrand()%COL;
    snake[0][1]=qrand()%ROW;
    direction=qrand()%4;
    timer=new QTimer;

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/GameBack.jpg").scaled(this->size())));//背景(前面为图片路径，后面是缩放)
    this->setPalette(palette);

    //得分
    ft.setPointSize(20);
    score.setParent(this);
    score.setFont(ft);
    score.setGeometry(750,40,80,40);
    score.setText("得分  ");


    //按钮
    downbtn=new QPushButton(this);
    downbtn->setIcon(QIcon("img/down.png"));
    downbtn->setGeometry(820,240,80,40);
    leftbtn=new QPushButton(this);
    leftbtn->setIcon(QIcon("img/left.png"));
    leftbtn->setGeometry(740,180,80,40);
    rightbtn=new QPushButton(this);
    rightbtn->setIcon(QIcon("img/right.png"));
    rightbtn->setGeometry(900,180,80,40);
    upbtn=new QPushButton(this);
    upbtn->setIcon(QIcon("img/up.png"));
    upbtn->setGeometry(820,120,80,40);
    startbtn=new QPushButton("开始",this);
    startbtn->setGeometry(770,320,180,50);
    returnbtn=new QPushButton("返回",this);
    returnbtn->setGeometry(770,400,180,50);

    connect(leftbtn,SIGNAL(clicked(bool)),this,SLOT(leftbtn_click()));
    connect(rightbtn,SIGNAL(clicked(bool)),this,SLOT(rightbtn_click()));
    connect(upbtn,SIGNAL(clicked(bool)),this,SLOT(upbtn_click()));
    connect(downbtn,SIGNAL(clicked(bool)),this,SLOT(downbtn_click()));
    connect(startbtn,SIGNAL(clicked(bool)),this,SLOT(startbtn_click()));
    connect(returnbtn,SIGNAL(clicked(bool)),this,SLOT(returnbtn_click()));
    connect(timer,SIGNAL(timeout()),this,SLOT(timeoutslot()));

    //食物
    foodx=qrand()%COL;
    foody=qrand()%ROW;
    foodcount=0;

    ft.setPointSize(20);
    QString b;
    b=QString::number(foodcount);
    score1.setParent(this);
    score1.setFont(ft);
    score1.setGeometry(850,40,100,40);
    score1.setText(b);
}

void snakeWidget::paintEvent(QPaintEvent *)
{
    int i,j;
    QPainter painter(this);
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            painter.drawRect(QRect(j*45,i*45+20,45,45));
        }
    }
    //食物

    painter.drawImage(QRectF(foodx*45,foody*45+20,45,45),QImage("img/Apple.png"));
    //蛇头

    switch (direction) {
    case UP:
        painter.drawImage(QRectF(snake[0][0]*45,snake[0][1]*45+20,45,45),QImage("img/touup"));
        break;
    case DOWN:
        painter.drawImage(QRectF(snake[0][0]*45,snake[0][1]*45+20,45,45),QImage("img/toudown"));
        break;
    case LEFT:
        painter.drawImage(QRectF(snake[0][0]*45,snake[0][1]*45+20,45,45),QImage("img/touleft"));
        break;
    case RIGHT:
        painter.drawImage(QRectF(snake[0][0]*45,snake[0][1]*45+20,45,45),QImage("img/touright"));
    default:
        break;
    }
    //蛇身
    for(i=1;i<=foodcount;i++)
    {
        painter.drawImage(QRectF(snake[i][0]*45,snake[i][1]*45+20,45,45),QImage("img/shen"));
    }
}
void snakeWidget::timeoutslot()
{
    int i=0;
    //是否吃到食物
    if(snake[0][0]==foodx&&snake[0][1]==foody)
    {
        //更新食物做表
        foodx=qrand()%COL;
        foody=qrand()%ROW;

        foodcount++;

        ft.setPointSize(20);
        QString b;
        b=QString::number(foodcount);
        score1.setFont(ft);
        score1.setParent(this);
        score1.setGeometry(850,40,100,40);
        score1.setText(b);
    }

    memcpy(snake1,snake,sizeof(snake));
    //改变蛇身坐标
    for(i=foodcount;i>0;i--)
    {
        snake[i][0]=snake[i-1][0];
        snake[i][1]=snake[i-1][1];
    }
    switch (direction) {
    case UP:
        snake[0][1]--;
        break;
    case DOWN:
        snake[0][1]++;
        break;
    case LEFT:
        snake[0][0]--;
        break;
    case RIGHT:
        snake[0][0]++;
    default:
        break;
    }
    if(snake[0][0]<0||snake[0][0]>=COL||snake[0][1]<0||snake[0][1]>=ROW)
    {
        memcpy(snake,snake1,sizeof(snake));
        QString b;
        b=QString::number(foodcount);
        if(QMessageBox::Yes==QMessageBox::question(this,"提示","GAME OVER! SCORE: "+b,QMessageBox::Yes))
        {
            this->close();
            delete this;
            timer->stop();
            return;
        }
    }
    if(foodcount>=3)
    {
        for(i=3;i<=foodcount;i++)
        if(snake[0][0]==snake[i][0]&&snake[0][1]==snake[i][1])
        {
            QString b;
            b=QString::number(foodcount);
            if(QMessageBox::Yes==QMessageBox::question(this,"提示","GAME OVER! SCORE: "+b,QMessageBox::Yes))
            {
                this->close();
                delete this;
                timer->stop();
                return;
            }
        }
    }
    this->update();
}

void snakeWidget::upbtn_click()
{
    direction=UP;
}
void snakeWidget::leftbtn_click()
{
    direction=LEFT;
}
void snakeWidget::rightbtn_click()
{
    direction=RIGHT;
}
void snakeWidget::downbtn_click()
{
    direction=DOWN;
}
void snakeWidget::startbtn_click()
{
    timer->start(speed);
}
void snakeWidget::returnbtn_click()
{
    delete this;
}


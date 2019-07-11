#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    this->resize(1000,605);
    this->setWindowIcon(QIcon("img/WindowPicture.jpg"));//图标
    this->setWindowTitle("贪吃蛇");//标题（可能有乱码）

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap("img/Back.jpg").scaled(this->size())));//背景(前面为图片路径，后面是缩放)
    this->setPalette(palette);

    startbtn=new QPushButton(this);
    startbtn->setIcon(QIcon("img/Start.png"));
    startbtn->setIconSize(QSize(100,100));//大小
    startbtn->setGeometry(QRect(600,400,100,100));//位置及大小
    startbtn->setFlat(true);//去掉边框

    exitbtn=new QPushButton(this);
    exitbtn->setIcon(QIcon("img/Exit.png"));
    exitbtn->setIconSize(QSize(100,100));
    exitbtn->setGeometry(QRect(750,400,100,100));
    exitbtn->setFlat(true);

    startbtn->connect(startbtn,SIGNAL(clicked(bool)),this,SLOT(startbtn_click()));
    this->connect(exitbtn,SIGNAL(clicked(bool)),this,SLOT(exitbtn_click()));
}

Widget::~Widget()
{
    delete startbtn;
    delete exitbtn;
    delete ui;
}

void Widget::startbtn_click()
{
    snake=new snakeWidget(this);
    snake->show();
}
void Widget::exitbtn_click()
{
    if(QMessageBox::Yes==QMessageBox::question(this,"提示","你是否要退出？",QMessageBox::Yes|QMessageBox::No)){
        delete this;
        exit(0);
    }

}

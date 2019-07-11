#ifndef SNAKEWIDGET_H
#define SNAKEWIDGET_H

#include <QWidget>
#include <QIcon>//标签
#include <QPalette>//
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>//询问框
#include <QPainter>
#include <QTimer>
#include <QMenuBar>
#include <QMenu>
#include <QLabel>
#include <QTextEdit>
#include <QString>
#include <QFont>
class snakeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit snakeWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
public slots:
    void leftbtn_click();
    void rightbtn_click();
    void upbtn_click();
    void downbtn_click();
    void startbtn_click();
    void returnbtn_click();
    void timeoutslot();
private:
    QFont ft;
    QLabel score;
    QLabel score1;
    QPushButton *leftbtn;
    QPushButton *rightbtn;
    QPushButton *upbtn;
    QPushButton *downbtn;
    QPushButton *startbtn;
    QPushButton *returnbtn;
    QTextEdit *bro;

    int direction;
    QTimer *timer;
    int snake[100][2];//蛇的坐标
    int snake1[100][2];
    int foodx,foody;//食物
    int foodcount;
    int speed;
signals:

public slots:
};

#endif // SNAKEWIDGET_H

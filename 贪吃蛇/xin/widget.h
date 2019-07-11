#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QIcon>//标签
#include <QPalette>//
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>//询问框
#include <snakewidget.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPushButton * startbtn;
    QPushButton * exitbtn;
    snakeWidget * snake;
public slots:
    void startbtn_click();
    void exitbtn_click();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

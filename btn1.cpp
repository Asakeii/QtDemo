#include "btn1.h"
#include <QPushButton>
#include <QLabel>
#include <QPropertyAnimation>
#include <QDebug>

btn1::btn1(QString resPath, QString btnTitle, int x, int y, int size)
{
    this->resPath = resPath;
    this->btnTitle = btnTitle;
    this->xl = x;
    this->yl = y;
    this->fontSize = size;


    QPixmap pix;

    pix.load(this->resPath);
    //设置图片固定大小
    this->setFixedSize(pix.width(), pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px}");//边框0px
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width()*0.7, pix.height()*0.5));

    //按钮文本信息
    btnLabel = new QLabel(this);
    btnLabel->setGeometry(0, 0, this->width(), this->height());
    btnLabel->setText(this->btnTitle);
    btnLabel->setAlignment(Qt::AlignCenter | Qt::AlignVCenter); // 设置居中 水平+垂直居中
    btnLabel->setAttribute(Qt::WA_TransparentForMouseEvents); // 设置鼠标穿透

    // 设置文本风格

    QFont titleFont;
    titleFont.setFamily("黑体");
    titleFont.setPointSize(this->fontSize);
    btnLabel->setFont(titleFont);
    btnLabel->setStyleSheet("QLabel { color: white; }");

    this->move(this->xl, this->yl);

}

void btn1::zoom1()
{
    //创建动态对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画时间间隔
    animation->setDuration(80);

    //起始位置
    animation->setStartValue(QRect(this->xl, this->yl, this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->xl, this->yl+10, this->width(), this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutSine);
    //执行动画
    animation->start();
}
void btn1::zoom2()
{
    //创建动态对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画时间间隔
    animation->setDuration(100);

    //起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->xl, this->yl, this->width(), this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutSine);
    //执行动画
    animation->start();
}


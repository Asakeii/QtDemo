#ifndef BTN1_H
#define BTN1_H

#include <QPushButton>
#include <QString>
#include <QLabel>


class btn1 : public QPushButton
{
    Q_OBJECT
public:
    // btn1构造函数
    btn1(QString resPath, QString btnTitle,  int x, int y, int size);


    // 弹跳特效
    void zoom1();   //按下
    void zoom2();   //回弹

private:
    QString resPath;  // 按钮图片路径
    QString btnTitle;    // 按钮名称信息
    QLabel *btnLabel;    // 按钮名称
    int xl; // 按钮x
    int yl; // 按钮y
    int fontSize;   // 字号




signals:

};

#endif // BTN1_H

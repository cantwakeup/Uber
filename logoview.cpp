#include "logoview.h"
#include "ui_logoview.h"
//----------------------------本代码仅用于显示logo界面，与主程序无关
LOGOview::LOGOview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LOGOview)
{
    ui->setupUi(this);
    setWindowFlags(Qt::SplashScreen | Qt::FramelessWindowHint);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &LOGOview::close);
}

LOGOview::~LOGOview() {
    delete ui;
}

void LOGOview::showLogo(int duration) {
    timer->start(duration);
    show();
}

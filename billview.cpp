#include "billview.h"
#include "ui_billview.h"
//------------------重要功能，打车后支付界面
BillView::BillView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BillView)
{
    ui->setupUi(this);
    connect(ui->btn_pay, &QPushButton::clicked, this, &BillView::on_payButton_clicked);
}

BillView::~BillView() {
    delete ui;
}

void BillView::setFare(double fare) {
    ui->lb_fare->setText("您此次行程费用为 " + QString::number(fare, 'f', 2) + " 元");
}

void BillView::setTimeElapsed(int timeElapsed) {
    ui->lb_time->setText("您此次行程所花时间 " + QString::number(timeElapsed) + " 秒");
}

void BillView::on_payButton_clicked() {
    emit pay();
}

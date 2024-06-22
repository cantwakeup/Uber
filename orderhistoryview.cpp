#include "orderhistoryview.h"
#include "ui_orderhistoryview.h"
#include <QDebug>

OrderHistoryView::OrderHistoryView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderHistoryView)
{
    ui->setupUi(this);
}

OrderHistoryView::~OrderHistoryView() {
    delete ui;
}

void OrderHistoryView::addOrder(const QString &order) {
    ui->orderListWidget->addItem(order);
    //qDebug() << "Order_added " << order;
}

void OrderHistoryView::clearOrders() {
    ui->orderListWidget->clear();
    //qDebug() << "clear";
}

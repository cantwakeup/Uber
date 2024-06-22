#include "orderhistorycontroller.h"
#include <QDebug>

OrderHistoryController::OrderHistoryController(QObject *parent, OrderModel *model) : QObject(parent) {
    orderHistoryView = new OrderHistoryView();
    orderModel = model; // 使用传递进来的 OrderModel 实例

    //qDebug() << "OrderHistoryControllerinitialized. OrderModel address:" << orderModel;
}

void OrderHistoryController::showOrderHistory() {
    orderHistoryView->clearOrders(); // 每次显示历史订单界面时，刷新订单列表
    QStringList orders = orderModel->getOrderHistory();
    for (const QString &order : orders) {
        orderHistoryView->addOrder(order);
    }
    orderHistoryView->show();

    //qDebug() << "historydisplay: " << orders;
}

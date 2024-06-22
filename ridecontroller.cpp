#include "ridecontroller.h"
#include "billcontroller.h"
#include <QDebug>

RideController::RideController(QObject *parent, OrderModel *model) : QObject(parent), distance(3.0), timeElapsed(0) {
    rideView = new RideView();
    orderModel = model; // 使用传递进来的 OrderModel 实例
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &RideController::updateDistance);
    connect(rideView, &RideView::arrived, this, &RideController::handleArrived);

    timer->start(5000); // 每5秒更新一次距离

    //qDebug() << "rideControllerinitialized,address:" << orderModel;
}

void RideController::showRideView(double pricePerKm, const QString &vehicleType, const QString &destination) {
    this->pricePerKm = pricePerKm;
    this->vehicleType = vehicleType;
    this->destination = destination;
    rideView->setSelectedVehicle(vehicleType); //设置界面所显示车型
    rideView->show();
}

void RideController::updateDistance() {
    if (distance > 0) {
        distance -= 0.1; // 每5秒减少0.1km
        timeElapsed += 5; // 每次更新同时记录下耗费的时间，亦即5秒
        rideView->updateDistance(distance);
    }
}

void RideController::handleArrived() {
    timer->stop();

    double fare = (3.0 - distance) * pricePerKm;
    QString order = QString("出行费用: %1, 所花时间: %2 秒, 乘坐车型: %3, 目的地：%4").arg(fare).arg(timeElapsed).arg(vehicleType).arg(destination);
    orderModel->addOrder(order); // 添加订单到订单模型并保存到文件

    //qDebug() << "orderadded: " << order;
    //qDebug() << "history: " << orderModel->getOrderHistory();

    BillController *billController = new BillController(nullptr, fare, timeElapsed);
    billController->showBillView();

    rideView->close();
}


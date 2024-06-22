#include "maincontroller.h"
#include "logincontroller.h"
#include <QDebug>

MainController::MainController(QObject *parent, OrderModel *model) : QObject(parent) {
    mainView = new mainview();
    orderModel = model; // 使用传递进来的 OrderModel 实例
    rideController = new RideController(nullptr, orderModel); // 传递 OrderModel
    orderHistoryController = new OrderHistoryController(nullptr, orderModel); // 传递 OrderModel

    connect(mainView, &mainview::rideRequest, this, &MainController::handleRideRequest);
    connect(mainView, &mainview::showOrderHistory, this, &MainController::showOrderHistory);
    connect(mainView, &mainview::queryOrdersByTime, this, &MainController::queryOrdersByTime);
    //connect(mainView, &mainview::backToLogin, this, &MainController::handleBackToLogin);

    //qDebug() << "mainControllerinitialized. address:" << orderModel;
}

void MainController::showMainView() {
    mainView->show();
}

void MainController::handleRideRequest(double pricePerKm, const QString &vehicleType, const QString &destination) {
    //qDebug() << "handleRideRequestcalled.";
    rideController->showRideView(pricePerKm, vehicleType, destination);
    mainView->close();
}

void MainController::showOrderHistory() {
    //qDebug() << "showOrderHistorycalled.";
    orderHistoryController->showOrderHistory();
}

void MainController::handleBackToLogin() {
    loginController->showLoginView();
}

void MainController::queryOrdersByTime() {
    QStringList orders = orderModel->queryOrdersByTime(10, 50);
    mainView->displayQueriedOrders(orders);
}

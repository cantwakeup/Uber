#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include "mainview.h"
#include "ridecontroller.h"
#include "orderhistorycontroller.h"
#include "ordermodel.h"
#include "logincontroller.h"

// 使用前向声明避免循环依赖
class LoginController;

class MainController : public QObject {
    Q_OBJECT

public:
    explicit MainController(QObject *parent = nullptr, OrderModel *orderModel = nullptr);
    void showMainView();
public slots://controller处理信号的声明
    void handleRideRequest(double pricePerKm, const QString &vehicleType, const QString &destination);
    void showOrderHistory();
    void handleBackToLogin();

    void queryOrdersByTime();

private:
    mainview *mainView;
    OrderHistoryController *orderHistoryController;
    RideController *rideController;
    OrderModel *orderModel;
    LoginController *loginController;
};

#endif // MAINCONTROLLER_H

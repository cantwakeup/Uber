#ifndef RIDECONTROLLER_H
#define RIDECONTROLLER_H

#include <QObject>
#include <QTimer>
#include "rideview.h"
#include "ordermodel.h"

class RideController : public QObject {
    Q_OBJECT

public:
    explicit RideController(QObject *parent = nullptr, OrderModel *model = nullptr);
    void showRideView(double pricePerKm, const QString &vehicleType, const QString &destination);

private slots:
    void updateDistance();
    void handleArrived();


private:
    RideView *rideView;
    OrderModel *orderModel;
    QTimer *timer;

    //订单信息
    double distance;
    int timeElapsed;
    double pricePerKm;
    QString vehicleType;
    QString destination;
};

#endif // RIDECONTROLLER_H

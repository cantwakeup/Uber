#ifndef ORDERHISTORYCONTROLLER_H
#define ORDERHISTORYCONTROLLER_H

#include <QObject>
#include "orderhistoryview.h"
#include "ordermodel.h"

class OrderHistoryController : public QObject {
    Q_OBJECT

public:
    explicit OrderHistoryController(QObject *parent = nullptr, OrderModel *model = nullptr);
    void showOrderHistory();

private:
    OrderHistoryView *orderHistoryView;
    OrderModel *orderModel;
};

#endif // ORDERHISTORYCONTROLLER_H

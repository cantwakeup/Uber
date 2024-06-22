#ifndef ORDERMODEL_H
#define ORDERMODEL_H

#include <QString>
#include <QStringList>

class OrderModel {
public:
    OrderModel();
    void addOrder(const QString &order);
    QStringList getOrderHistory() const;
    QStringList queryOrdersByTime(int minTime, int maxTime) const;

private:
    void loadOrders(); // 从文件加载订单
    void saveOrder(const QString &order); // 保存订单到文件

};

#endif // ORDERMODEL_H

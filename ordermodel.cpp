#include "ordermodel.h"
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>

OrderModel::OrderModel() {
    loadOrders();
}

void OrderModel::addOrder(const QString &order) {
    saveOrder(order);
}

QStringList OrderModel::getOrderHistory() const {
    QStringList orders;
    QFile file(QCoreApplication::applicationDirPath() + "/orders.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            orders.append(line);
        }
        file.close();
    }
    return orders;
}
//文件读存逻辑
void OrderModel::loadOrders() {
    //这里具有可扩展性，可以从其他数据库读取以往的历史数据
}

void OrderModel::saveOrder(const QString &order) {
    QFile file(QCoreApplication::applicationDirPath() + "/orders.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << order << "\n";
        file.close();
    }
}

QStringList OrderModel::queryOrdersByTime(int minTime, int maxTime) const {
    QStringList orders = getOrderHistory();
    QStringList result;
    for (const QString &order : orders) {
        QRegExp regex("所花时间: (\\d+) 秒");
        if (regex.indexIn(order) != -1) {
            int time = regex.cap(1).toInt();
            if (time >= minTime && time <= maxTime) {
                result.append(order);
            }
        }
    }
    return result;
}

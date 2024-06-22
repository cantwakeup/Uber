#ifndef ORDERHISTORYVIEW_H
#define ORDERHISTORYVIEW_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class OrderHistoryView;
}

class OrderHistoryView : public QWidget
{
    Q_OBJECT

public:
    explicit OrderHistoryView(QWidget *parent = 0);
    ~OrderHistoryView();
    void addOrder(const QString &order);
    void clearOrders();

private:
    Ui::OrderHistoryView *ui;
};

#endif // ORDERHISTORYVIEW_H

#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QRadioButton>

namespace Ui {
class mainview;
}

class mainview : public QWidget {
    Q_OBJECT

public:
    explicit mainview(QWidget *parent = nullptr);
    ~mainview();

signals:
    void rideRequest(double pricePerKm, const QString &vehicleType, const QString &destination);//在处理ride信号时传递信息
    void showOrderHistory();//查询历史请求
    //void backToLogin(); //退出登录
    void queryOrdersByTime();
public:
    void on_button1_clicked();
        void on_nextPageButton_clicked(); //切换新闻页面的槽函数
    void on_button2_clicked();
        void on_rideButton_clicked();
        void on_vehicleTypeChanged(); //处理车型选择的槽函数
    void on_button3_clicked(); //屏幕底端导航的三个按钮
        void Entered();
        void on_btn_orderHistory_clicked();
        void on_btn_back_clicked();
         void on_queryButton_clicked(); // 查询按钮槽函数
         void displayQueriedOrders(const QStringList &orders); // 显示查询结果
private:
    Ui::mainview *ui;
    double pricePerKm; // 每公里价格
    QString vehicleType; // 车型名称
    QWidget *previousView; // 保存上一个窗口的指针用于返回

    void updateSelectedVehicleLabel();
};

#endif // MAINVIEW_H

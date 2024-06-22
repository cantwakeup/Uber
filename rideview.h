#ifndef RIDEVIEW_H
#define RIDEVIEW_H

#include <QWidget>

namespace Ui {
class RideView;
}

class RideView : public QWidget {
    Q_OBJECT

public:
    explicit RideView(QWidget *parent = nullptr);
    ~RideView();

    void setSelectedVehicle(const QString &vehicleType);
signals:
    void arrived();
    void vehicleTypeChanged(double pricePerKm);

public slots:
    void updateDistance(double distance);

private slots:
    void on_arrivedButton_clicked(); //“我已到达目的地”的按钮被按下
    void on_report_clicked();

private:
    Ui::RideView *ui;
};

#endif // RIDEVIEW_H

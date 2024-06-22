#include "rideview.h"
#include "ui_rideview.h"
#include <QMessageBox>
#include <Qdebug>
//-------------------------这里是核心功能，打车界面，ui设计还需完善
RideView::RideView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RideView)
{
    ui->setupUi(this);
    connect(ui->btn_arrived, &QPushButton::clicked, this, &RideView::on_arrivedButton_clicked);


}

RideView::~RideView() {
    delete ui;
}

void RideView::updateDistance(double distance) {
    ui->lb_distance->setText(QString::number(distance, 'f', 1) + " km");
}//实时反馈当前距离目的地距离

void RideView::setSelectedVehicle(const QString &vehicleType) {
    ui->selectedVehicleLabel->setText(vehicleType); // 设置车型信息到标签
}

void RideView::on_arrivedButton_clicked() {
    emit arrived();
}//到达！

//void RideView::updateSelectedVehicleLabel() {
    //ui->selectedVehicleLabel->setText(vehicleType + " - " + QString::number(pricePerKm) + "元/km");
//}

void RideView::on_report_clicked()
{
    QMessageBox warningBox;
    warningBox.setIcon(QMessageBox::Warning);
    warningBox.setText("我们已收到举报，将密切监控当前司机！");
    warningBox.setWindowTitle("举报成功！");
    warningBox.setStandardButtons(QMessageBox::Ok);
    warningBox.exec();
}

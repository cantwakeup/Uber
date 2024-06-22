#include "mainview.h"
#include "ui_mainview.h"
#include "QMessageBox"
#include "QDebug"
//---------------------------------这里是主导航界面，最重要的也是最核心的中转站
//----------------------------主要引导用户到程序的各个功能中去
//----------------------------所有异常操作都应该返回到这里来
mainview::mainview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainview),
  pricePerKm(2.0), // 初始值为实惠快车
      vehicleType("实惠快车")
{
    ui->setupUi(this);

//主界面的三个导航按钮以及对应的槽与函数
    connect(ui->button1, &QPushButton::clicked, this, &mainview::on_button1_clicked);
        connect(ui->nextPageButton, &QPushButton::clicked, this, &mainview::on_nextPageButton_clicked);

    connect(ui->button2, &QPushButton::clicked, this, &mainview::on_button2_clicked);
        connect(ui->bt_ride, &QPushButton::clicked, this, &mainview::on_rideButton_clicked);
        //四种车型所对应选择按钮的信号到槽函数
            connect(ui->economyRadioButton, &QRadioButton::toggled, this, &mainview::on_vehicleTypeChanged);
            connect(ui->expressRadioButton, &QRadioButton::toggled, this, &mainview::on_vehicleTypeChanged);
            connect(ui->executiveRadioButton, &QRadioButton::toggled, this, &mainview::on_vehicleTypeChanged);
            connect(ui->businessRadioButton, &QRadioButton::toggled, this, &mainview::on_vehicleTypeChanged);

            updateSelectedVehicleLabel(); // 更新初始选择的车型标签

    connect(ui->button3, &QPushButton::clicked, this, &mainview::on_button3_clicked);
         connect(ui->vip_bt, &QPushButton::clicked, this, &mainview::Entered);
         connect(ui->btn_orderHistory, &QPushButton::clicked, this, &mainview::on_btn_orderHistory_clicked);
         //connect(ui->btn_back, &QPushButton::clicked, this, &mainview::on_btn_back_clicked);

          connect(ui->queryButton, &QPushButton::clicked, this, &mainview::on_queryButton_clicked);
}

mainview::~mainview() {
    delete ui;
}
//1111111111111111111111111111111
void mainview::on_button1_clicked() {
    ui->navigate->setCurrentIndex(0);
}

    void mainview::on_nextPageButton_clicked() {
        int currentIndex = ui->news_CSU->currentIndex();
        int pageCount = ui->news_CSU->count();
        int nextIndex = (currentIndex + 1) % pageCount;
        ui->news_CSU->setCurrentIndex(nextIndex);
        }
//2222222222222222222222222222222
void mainview::on_button2_clicked() {
    ui->navigate->setCurrentIndex(1);
}
    void mainview::on_rideButton_clicked() {
        QString destination = ui->destinationLineEdit->text();
        emit rideRequest(pricePerKm, vehicleType, destination);    //核心功能：打车
    }

    void mainview::on_vehicleTypeChanged() {
        if (ui->economyRadioButton->isChecked()) {
            pricePerKm = 2.0;
            vehicleType = "实惠快车";
        } else if (ui->expressRadioButton->isChecked()) {
            pricePerKm = 5.0;
            vehicleType = "滴行特快";
        } else if (ui->executiveRadioButton->isChecked()) {
            pricePerKm = 15.0;
            vehicleType = "行政级专车";
        } else if (ui->businessRadioButton->isChecked()) {
            pricePerKm = 30.0;
            vehicleType = "商务六座";
        }

        updateSelectedVehicleLabel();//实时反馈用户所选车型
    }

    void mainview::updateSelectedVehicleLabel() {
        ui->selectedVehicleLabel->setText(vehicleType + " - " + QString::number(pricePerKm) + "元/km");
    }

//3333333333333333333333333333333
void mainview::on_button3_clicked() {
    ui->navigate->setCurrentIndex(2);
}

    void mainview::on_queryButton_clicked() {
    emit queryOrdersByTime();
    }
    void mainview::displayQueriedOrders(const QStringList &orders) {
        ui->orderListWidget1->clear();
        for (const QString &order : orders) {
            ui->orderListWidget1->addItem(order);
        }
    }
    void mainview::Entered() {
    QString key = ui->le_id->text();
    if (key == "1234") {
        ui->label_status->setText("尊贵的 滴行会员");
        ui->label_status->setStyleSheet("color: orange;");

        QMessageBox infoBox;
        infoBox.setIcon(QMessageBox::Information);
        infoBox.setText("欢迎您！滴行会员用户！");
        infoBox.setWindowTitle("来自服务器");
        infoBox.setStandardButtons(QMessageBox::Ok);
        infoBox.exec();
       // qDebug() << "Admin mode";
    } else {
        ui->label_status->setText("中南滴行 普通用户");
        ui->label_status->setStyleSheet("color: black;");
       // qDebug() << "User mode";
    }
}
    //vip检入功能


    void mainview::on_btn_orderHistory_clicked() {
        emit showOrderHistory();
    }
    //显示历史订单功能

    void mainview::on_btn_back_clicked() {
        this->close();
            if (previousView) {
                previousView->show(); // 显示上一个窗口
            }
    }

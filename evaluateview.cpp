#include "evaluateview.h"
#include "ui_evaluateview.h"
#include <QMessageBox>
#include "QDebug"
//--------------------------这里是评价界面

evaluateview::evaluateview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::evaluateview)
{
    ui->setupUi(this);
    connect(ui->ratingSlider, &QSlider::valueChanged, this, &evaluateview::updateRatingLabel);
    connect(ui->submitButton, &QPushButton::clicked, this, &evaluateview::onSubmitButtonClicked);
    updateRatingLabel(ui->ratingSlider->value());
}

evaluateview::~evaluateview()
{
    delete ui;
}

void evaluateview::updateRatingLabel(int value)
{
    QString stars;
    for (int i = 0; i < value; ++i) {
        stars += "★";
    }
    for (int i = value; i < 5; ++i) {
        stars += "☆";
    }//利用字符串实现星星拖动评分
    ui->ratingLabel->setText(stars);
}

void evaluateview::onSubmitButtonClicked()
{
    QMessageBox infoBox;
    infoBox.setIcon(QMessageBox::Information);
    infoBox.setText("我们已收到您的评价！");
    infoBox.setWindowTitle("来自服务器");
    infoBox.setStandardButtons(QMessageBox::Ok);
    infoBox.exec();

    int rating = ui->ratingSlider->value();
    //这里具有可扩展性，可将评分保存到数据库或发送到服务器
    //qDebug() << "提交的评分:" << rating;
    emit evaluationCompleted();  // 发送评价完成信号
    this->close();
}

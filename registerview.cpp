#include "registerview.h"
#include "ui_registerview.h"

RegisterView::RegisterView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterView)
{
    ui->setupUi(this);
    connect(ui->btn_submit, &QPushButton::clicked, this, &RegisterView::on_btn_submit_clicked);
}//把registerview中的按钮与register函数链接

RegisterView::~RegisterView()
{
    delete ui;
}

void RegisterView::on_btn_submit_clicked() {
    QString email = ui->le_username->text();
    QString password = ui->le_password->text();
    emit registerUser(email, password);
    this->close();
}//在注册view中，按下注册按钮后的逻辑

#include "loginview.h"
#include "ui_loginview.h"
#include <QMessageBox>

LoginView::LoginView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);
    connect(ui->btn_login, &QPushButton::clicked, this, &LoginView::on_loginButton_clicked);
    connect(ui->btn_register, &QPushButton::clicked, this, &LoginView::on_btn_register_clicked);
    //登录and注册按钮
}

LoginView::~LoginView() {
    delete ui;
}

void LoginView::on_loginButton_clicked() {
    QString email = ui->le_username->text();
    QString password = ui->le_password->text();
    emit login(email, password);
}//输入账号密码


void LoginView::showError(const QString &message) {
    QMessageBox::critical(this, "Error", message);  // 使用 QMessageBox 弹出错误提示框
}

void LoginView::on_btn_register_clicked()
{
    emit registerUser();//发出注册信号
}

QString LoginView::getLoginEmail() const {
    return ui->le_username->text();
}

QString LoginView::getLoginPassword() const {
    return ui->le_password->text();
}

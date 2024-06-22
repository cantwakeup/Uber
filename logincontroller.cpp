#include "logincontroller.h"
#include "maincontroller.h"
#include "QMessageBox"
//-------------------------这里是login的controller，用于处理登录注册逻辑所需要的函数调用
LoginController::LoginController(QObject *parent) : QObject(parent) {
    loginView = new LoginView();
    userModel = new UserModel();
    registerView = new RegisterView(); // 创建一个对应类的实例
    orderModel = new OrderModel(); // 创建 OrderModel 实例


    connect(loginView, &LoginView::login, this, &LoginController::handleLogin); // 登录信号链接登录槽函数
    connect(loginView, &LoginView::registerUser, this, &LoginController::showRegisterView); // 注册信号链接显示注册界面的槽函数
    connect(registerView, &RegisterView::registerUser, this, &LoginController::handleRegister); // 注册界面信号链接注册槽函数

    mainController = new MainController(nullptr, orderModel); // 在这里创建 MainController 实例，并传递 OrderModel 实例
}

void LoginController::showLoginView() {
    loginView->show();
}

void LoginController::showRegisterView() {
    registerView->show();
}

void LoginController::handleLogin(const QString &email, const QString &password) {
    if (userModel->authenticate(email, password)) {
        mainController->showMainView();
        loginView->close();
    } else {
        loginView->showError("账号或密码错误！！请重试！！");
    }
}

void LoginController::handleRegister(const QString &email, const QString &password) {
    // 调用 UserModel 的 registerUser 方法进行注册
    if (userModel->registerUser(email, password)) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("注册成功！");
        msgBox.setWindowTitle("来自服务器");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
    else {
        //loginView->showError("注册失败！请重试！");
    }
}

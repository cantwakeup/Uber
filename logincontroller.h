#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <QObject>
#include "loginview.h"
#include "usermodel.h"
#include "registerview.h"
#include "ordermodel.h"
#include "maincontroller.h"

// 使用前向声明
class MainController;

class LoginController : public QObject {
    Q_OBJECT

public:
    explicit LoginController(QObject *parent = nullptr);
    void showLoginView();

private slots:
    void handleLogin(const QString &email, const QString &password);
    void showRegisterView();
    void handleRegister(const QString &email, const QString &password);

private:
    LoginView *loginView;
    UserModel *userModel;
    RegisterView *registerView;
    OrderModel *orderModel;
    MainController *mainController;
};

#endif // LOGINCONTROLLER_H

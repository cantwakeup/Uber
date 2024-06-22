#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>

namespace Ui {
class LoginView;
}

class LoginView : public QWidget {
    Q_OBJECT

public:
    explicit LoginView(QWidget *parent = nullptr);
    ~LoginView();

signals:
    void login(const QString &email, const QString &password);//登录信号
    void registerUser();//注册信号

private slots:
    void on_loginButton_clicked();
    void on_btn_register_clicked();//登录and注册的槽函数

public slots:
    void showError(const QString &message);//返回错误信息

public:
    QString getLoginEmail() const;
    QString getLoginPassword() const;//从输入框中获取输入的账号密码

private:
    Ui::LoginView *ui;
};

#endif // LOGINVIEW_H

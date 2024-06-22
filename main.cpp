#include <QApplication>
#include "logoview.h"
#include "logincontroller.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    LOGOview LOGO;
    LOGO.showLogo(500); // 先显示logo

    LoginController login;

    QTimer::singleShot(500, [&login]() {
        login.showLoginView(); // lambda表达式调用Logincontroller中的函数
    }); // 实现logo展示后再进入登录界面

    return a.exec();
}

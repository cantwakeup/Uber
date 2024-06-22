#ifndef USERMODEL_H
#define USERMODEL_H

#include <QString>
#include <QMap>

class UserModel {
public:
    UserModel();
    bool authenticate(const QString &email, const QString &password);
    bool registerUser(const QString &email, const QString &password);

private:
    QMap<QString, QString> users;  // 用于存储用户数据
    bool isVIP = 0;
};

#endif // USERMODEL_H

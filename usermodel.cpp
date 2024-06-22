#include "usermodel.h"

UserModel::UserModel() {
   //这里具有可扩展性，例如从某个数据库中载入信息
}

bool UserModel::authenticate(const QString &email, const QString &password) {
    return users.contains(email) && users[email] == password;    // 基本用户认证逻辑
}

bool UserModel::registerUser(const QString &email, const QString &password) {
    if (users.contains(email))
    {
        return false;  //用户已存在
    }
    users[email] = password;  //用户不存在的话，就直接注册新用户
    return true;
}

#ifndef TEMPLATE_H
#define TEMPLATE_H
//----------------------这里是部分需要用到的功能实现的模板，放在这便于使用，项目完成后将删除


// 弹出一个消息框，询问用户是否确认某个操作，确定执行xx，否定则执行xx，当然还有取消执行xx
/*#include <QMessageBox>

QMessageBox questionBox;
questionBox.setIcon(QMessageBox::Question);
questionBox.setText("您确定要执行此操作吗？");
questionBox.setWindowTitle("确认操作");
questionBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
int ret = questionBox.exec();

switch (ret) {
    case QMessageBox::Yes:
        // 用户点击了“是”按钮
        // 执行相关操作
        break;
    case QMessageBox::No:
        // 用户点击了“否”按钮
        // 执行相关操作
        break;
    case QMessageBox::Cancel:
        // 用户点击了“取消”按钮
        // 执行相关操作
        break;
    default:
        // 应该不会到这里
        break;
}
*/

//弹出一个（无操作仅提示）的消息框，包括提示、警告、报错
/*#include <QMessageBox>
 *

// 创建一个信息消息框
QMessageBox infoBox;
infoBox.setIcon(QMessageBox::Information);
infoBox.setText("这是一个信息消息框。");
infoBox.setWindowTitle("信息");
infoBox.setStandardButtons(QMessageBox::Ok);
infoBox.exec();

// 创建一个警告消息框
QMessageBox warningBox;
warningBox.setIcon(QMessageBox::Warning);
warningBox.setText("这是一个警告消息框。");
warningBox.setWindowTitle("警告");
warningBox.setStandardButtons(QMessageBox::Ok);
warningBox.exec();

// 创建一个错误消息框
QMessageBox criticalBox;
criticalBox.setIcon(QMessageBox::Critical);
criticalBox.setText("这是一个错误消息框。");
criticalBox.setWindowTitle("错误");
criticalBox.setStandardButtons(QMessageBox::Ok);
criticalBox.exec();
*/
//订单信息追加保存到一个文本文件中,关键词：追加、文本
/*void OrderModel::saveOrder(const QString &order) {
    QFile file(QCoreApplication::applicationDirPath() + "/orders.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << order << "\n";
        file.close();
    }
}
*/
//从文件中读取订单历史记录的函数，关键词：只读、文本
/*QStringList OrderModel::getOrderHistory() const {
    QStringList orders;
    QFile file(QCoreApplication::applicationDirPath() + "/orders.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            orders.append(line);
        }
        file.close();
    }
    return orders;
}
*/
#endif // TEMPLATE_H

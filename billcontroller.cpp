#include "billcontroller.h"
#include "maincontroller.h"
//--------------处理支付相关功能的信号与槽函数都将在这里链接
BillController::BillController(QObject *parent, double fare, int timeElapsed) : QObject(parent), fare(fare), timeElapsed(timeElapsed) {
    billView = new BillView();
    evaluateView = new evaluateview();

    connect(billView, &BillView::pay, this, &BillController::handlePayment);
    connect(evaluateView, &evaluateview::evaluationCompleted, this, &BillController::handleEvaluationCompleted);

    billView->setFare(fare);
    billView->setTimeElapsed(timeElapsed);
}

void BillController::showBillView() {
    billView->show();
}

void BillController::handlePayment() {
    evaluateView->show();  // 支付后显示评价界面
    billView->close();
}

void BillController::handleEvaluationCompleted() {
    MainController *mainController = new MainController();
    mainController->showMainView();
    evaluateView->close();
}//评价完成后退出，返回主页面

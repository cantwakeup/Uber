#ifndef BILLCONTROLLER_H
#define BILLCONTROLLER_H

#include <QObject>
#include "billview.h"
#include "evaluateview.h"

class BillController : public QObject {
    Q_OBJECT

public:
    explicit BillController(QObject *parent = nullptr, double fare = 0.0, int timeElapsed = 0);
    void showBillView();

private slots:
    void handlePayment();
    void handleEvaluationCompleted();

private:
    BillView *billView;
    evaluateview *evaluateView;
    double fare;
    int timeElapsed;
};

#endif // BILLCONTROLLER_H

#ifndef BILLVIEW_H
#define BILLVIEW_H

#include <QWidget>

namespace Ui {
class BillView;
}

class BillView : public QWidget {
    Q_OBJECT

public:
    explicit BillView(QWidget *parent = nullptr);
    ~BillView();

signals:
    void pay();

public slots:
    void setFare(double fare);
    void setTimeElapsed(int timeElapsed);

private slots:
    void on_payButton_clicked();

private:
    Ui::BillView *ui;
};

#endif // BILLVIEW_H

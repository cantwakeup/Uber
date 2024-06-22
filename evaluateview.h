#ifndef EVALUATEVIEW_H
#define EVALUATEVIEW_H

#include <QWidget>

namespace Ui {
class evaluateview;
}

class evaluateview : public QWidget
{
    Q_OBJECT

public:
    explicit evaluateview(QWidget *parent = nullptr);
    ~evaluateview();

signals:
    void evaluationCompleted();  // 评价完成信号

private slots:
    void updateRatingLabel(int value);
    void onSubmitButtonClicked();

private:
    Ui::evaluateview *ui;
};

#endif // EVALUATEVIEW_H

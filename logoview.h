#ifndef LOGOVIEW_H
#define LOGOVIEW_H

#include <QWidget>
#include <QTimer>

namespace Ui {
    class LOGOview;
}

class LOGOview : public QWidget {
    Q_OBJECT

public:
    explicit LOGOview(QWidget *parent = nullptr);
    ~LOGOview();
    void showLogo(int duration);

signals:
    void finished();  // 添加一个信号

private:
    Ui::LOGOview *ui;
    QTimer *timer;
};

#endif // LOGOVIEW_H

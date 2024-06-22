#ifndef REGISTERVIEW_H
#define REGISTERVIEW_H

#include <QDialog>

namespace Ui {
class RegisterView;
}

class RegisterView : public QDialog {
    Q_OBJECT

public:
    explicit RegisterView(QWidget *parent = nullptr);
    ~RegisterView();

signals:
    void registerUser(const QString &email, const QString &password);

private slots:
    void on_btn_submit_clicked();

private:
    Ui::RegisterView *ui;
};

#endif // REGISTERVIEW_H

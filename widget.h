#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#define Coffee 100
#define Tea 150
#define Milk 200

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money {0};
    void changeMoney(int diff){
        money += diff;
    }
    void on_pbCoffee();

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbMilk_clicked();

    void on_pbReset_clicked();

    int CheckMoney();

private:
    Ui::Widget *ui;
    QTimer* timer;
};
#endif // WIDGET_H

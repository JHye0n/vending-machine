#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(CheckMoney()));
    timer->start(100);

}

Widget::~Widget()
{
    delete ui;
}

int Widget::CheckMoney()
{
    //coffee money check
    if(money >= Coffee){
        ui->pbCoffee->setEnabled(true);
    }else{
        ui->pbCoffee->setEnabled(false);
    }

    //tea money check
    if(money >= Tea){
        ui->pbTea->setEnabled(true);
    }else{
        ui->pbTea->setEnabled(false);
    }

    //milk money check
    if(money >= Milk){
        ui->pbMilk->setEnabled(true);
    }else{
        ui->pbMilk->setEnabled(false);
    }

}

void Widget::on_pb10_clicked()
{
    //ChangeMoney(10);
    money += 10;
    ui->lcdNumber->display(money);
}

void Widget::on_pb50_clicked()
{
    //ChangeMoney(50);
    money += 50;
    ui->lcdNumber->display(money);
}

void Widget::on_pb100_clicked()
{
    //ChangeMoney(100);
    money += 100;
    ui->lcdNumber->display(money);
}

void Widget::on_pb500_clicked()
{
    //ChangeMoney(500);
    money += 500;
    ui->lcdNumber->display(money);
}

void Widget::on_pbCoffee_clicked()
{
    if(money < Coffee){
        QMessageBox m;
        m.warning(nullptr,"warning!!!","you have no money");
    }else{
        money -= Coffee;
        ui->lcdNumber->display(money);
    }
}

void Widget::on_pbTea_clicked()
{
    if(money < Tea){
        QMessageBox m;
        m.warning(nullptr,"warning!!!","you have no money");
    }else{
        money -= Tea;
        ui->lcdNumber->display(money);
    }
}

void Widget::on_pbMilk_clicked()
{
    if(money < Milk){
        QMessageBox m;
        m.warning(nullptr,"warning!!!","you have no money");
    }else{
        money -= Milk;
        ui->lcdNumber->display(money);
    }
}

void Widget::on_pbReset_clicked()
{
    QMessageBox m;
    if(money == 0){
        m.warning(nullptr, "no~~~","no money!!!");
    }else{
        m.information(nullptr,"good bye", QString("%1").arg(money)); // result money
        money = {0};
        ui->lcdNumber->display(money);
    }
}

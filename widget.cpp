#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    SetMoney();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::addMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
    SetMoney();
}

void Widget::invMoney(int diff)
{
    money -= diff;
    ui->lcdNumber->display(money);
    SetMoney();
}

void Widget::ResetMoney(){
    money = {0};
    ui->lcdNumber->display(money);
    SetMoney();
}

void Widget::SetMoney()
{
    ui->pbCoffee->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=150);
    ui->pbMilk->setEnabled(money>=200);
}

void Widget::on_pb10_clicked()
{
    addMoney(10);
}

void Widget::on_pb50_clicked()
{
    addMoney(50);
}

void Widget::on_pb100_clicked()
{
    addMoney(100);
}

void Widget::on_pb500_clicked()
{
    addMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    if(money < Coffee){
        QMessageBox m;
        m.warning(nullptr,"warning!!!","you have no money");
    }else{
        invMoney(100);
    }
}

void Widget::on_pbTea_clicked()
{
    if(money < Tea){
        QMessageBox m;
        m.warning(nullptr,"warning!!!","you have no money");
    }else{
         invMoney(150);
    }
}

void Widget::on_pbMilk_clicked()
{
    if(money < Milk){
        QMessageBox m;
        m.warning(nullptr,"warning!!!","you have no money");
    }else{
        invMoney(200);
    }
}

void Widget::on_pbReset_clicked()
{
    // 10won, 100won, 500won
    // for ~~
    QMessageBox m;
    if(money == 0){
        m.warning(nullptr, "no~~~","no money!!!");
    }else{
        m.information(nullptr,"good bye", QString("%1").arg(money)); // result money
        ResetMoney();
    }
}

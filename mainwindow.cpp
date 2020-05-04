#include <QLabel>

#include "mainwindow.h"
#include "ui_mainwindow.h"

static int counter = 0;
QVector<QLabel *> labels;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QLabel *lbl = new QLabel;
    lbl->setText(QString("foo_%1").arg(++counter));

    labels.push_back(lbl);

    ui->scrollLayout->addWidget(lbl);
}

void MainWindow::on_pushButton_2_clicked()
{
    for (QLabel * lbl: labels) {
        ui->scrollLayout->addWidget(lbl);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QLayoutItem *wItem;
    while ((wItem = ui->scrollLayout->layout()->takeAt(0)) != nullptr)
    delete  wItem;
    labels.clear();
}

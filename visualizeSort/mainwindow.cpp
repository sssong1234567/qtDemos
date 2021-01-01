#include <iostream>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sortbubble.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _bars.reset(new QCPBars(ui->GP_Main->xAxis, ui->GP_Main->yAxis));
    _bars->setName("Sort Bars");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PB_Play_toggled(bool checked)
{
    std::cout << __func__ << " " << __LINE__ << " checked=" << checked << std::endl;

    if (!_sort) {
        QMessageBox qmsgbox;
        qmsgbox.setText("Create first!");
        qmsgbox.exec();

        return;
    }

    // draw
    _sort->sort();
    _sort->toString();
    updateGraph(_sort->data());
}

void MainWindow::on_PB_New_clicked()
{
    _sort.reset(new SortBubble);
    _sort->init(10);
    updateGraph(_sort->data());
}

void MainWindow::updateGraph(std::vector<int> data)
{
    QVector<double> keyData;
    QVector<double> valData(data.begin(), data.end());

    for (uint32_t i = 0; i < data.size(); i++) {
        keyData << i+1;
    }

    _bars->setData(keyData, valData);
    ui->GP_Main->rescaleAxes();
    ui->GP_Main->replot();
}

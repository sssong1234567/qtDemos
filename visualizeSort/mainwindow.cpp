#include <iostream>
#include <string>
#include <sstream>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "bubblesort.h"
#include "quicksort.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _bars.reset(new QCPBars(ui->GP_Main->xAxis, ui->GP_Main->yAxis));
    _bars->setName("Sort Bars");

    _timer.reset(new QTimer(this));
    connect(_timer.get(), &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PB_Play_toggled(bool checked)
{
    if (checked && !_sort) {
        QMessageBox qmsgbox;
        qmsgbox.setText("Make a new list first!");
        qmsgbox.exec();

        return;
    }

    if (checked && !_timer->isActive()) {
        _timer->start(ui->SB_Interval->value());
    }
    if (!checked && _timer->isActive()) {
        _timer->stop();
    }
}

void MainWindow::on_PB_New_clicked()
{
    stop();

    if (_sort.get() != nullptr)
        disconnect(_sort.get());

    if (ui->CB_Sort->currentText() == "Bubble")
        _sort.reset(new BubbleSort);
    else if (ui->CB_Sort->currentText() == "Quick")
        _sort.reset(new QuickSort);

    connect(_sort.get(), SIGNAL(swapped()), this, SLOT(updateGraph()));

    _sort->init(ui->SB_Size->value());
    updateGraph();
    updateCount();
}

void MainWindow::update()
{
    // draw
    if (!_sort->sort()) {
        stop();
    }
    //_sort->toString();
    updateGraph();
}

void MainWindow::updateGraph()
{
    std::vector<int>& data = _sort->data();
    QVector<double> keyData;
    QVector<double> valData(data.begin(), data.end());

    for (uint32_t i = 0; i < data.size(); i++) {
        keyData << i+1;
    }

    _bars->setData(keyData, valData);
    ui->GP_Main->rescaleAxes();
    ui->GP_Main->replot();

    updateCount();
}

void MainWindow::updateCount()
{
    ui->LB_Count->setText(QString::fromStdString(std::to_string(_sort->count())));
}

void MainWindow::stop()
{
    _timer->stop();
    ui->PB_Play->setChecked(false);
}

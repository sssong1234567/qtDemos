#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include <QTimer>

#include "qcustomplot.h"
#include "sort.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PB_Play_toggled(bool checked);
    void on_PB_New_clicked();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<Sort> _sort;
    std::unique_ptr<QCPBars> _bars;
    std::unique_ptr<QTimer> _timer;

    void update();
    void updateGraph(std::vector<int> data);
    void updateCount();
    void stop();
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QString ping_IP = "14.215.177.38";
    QProcess ping(this);
    ping.start("ping " + ping_IP);

    //waitForFinished 等待程序执行完成
    while (ping.waitForFinished(5) == false)
    {

    //进程交互，读取ping控制台的输出
    QByteArray out = ping.readAllStandardOutput();
    if (!out.isEmpty())
        {

        //把内容显示在textBrowser 通过fromLocal8Bit编码输出
        ui->text_ping_network->append(QString::fromLocal8Bit(out));

        //重绘
        repaint();

        }
    }

    //进程交互，读取ping控制台的输出
    QByteArray out = ping.readAllStandardOutput();

    //把内容显示在textBrowser 通过fromLocal8Bit编码输出
    ui->text_ping_network->append(QString::fromLocal8Bit(out));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_network_quit_clicked()
{
    //结束程序 退出窗口
    QApplication* app;
    app->quit();
}

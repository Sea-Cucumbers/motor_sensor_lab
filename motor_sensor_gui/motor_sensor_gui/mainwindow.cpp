#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    qDebug() << "Connecting,..";

    socket->connectToHost("10.0.0.153", 65432);
}

void MainWindow::connected()
{
    qDebug() << "Connected!";
}

void MainWindow::disconnected()
{
    qDebug() << "Disconnected!";
}

void MainWindow::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes;
}

void MainWindow::readyRead()
{
    qDebug() << "Reading...";
    QString received(socket->readAll());
    if (received.indexOf("us") >= 0) {
        ui->ultrasonicTextEdit->setPlainText(received);
     }
}

MainWindow::~MainWindow()
{
    if(!socket->waitForDisconnected(1000))
    {
        qDebug() << "Error: " << socket->errorString();
    }
    delete ui;
}


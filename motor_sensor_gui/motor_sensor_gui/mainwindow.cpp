#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serialBuf = "";

    serial.setPortName("ttyACM0");
    if(!serial.setBaudRate(QSerialPort::Baud9600))
        qDebug() << serial.errorString();
    if(!serial.setDataBits(QSerialPort::Data7))
        qDebug() << serial.errorString();
    if(!serial.setParity(QSerialPort::EvenParity))
        qDebug() << serial.errorString();
    if(!serial.setFlowControl(QSerialPort::HardwareControl))
        qDebug() << serial.errorString();
    if(!serial.setStopBits(QSerialPort::OneStop))
        qDebug() << serial.errorString();
    if(!serial.open(QIODevice::ReadOnly))
        qDebug() << serial.errorString();

    QObject::connect(&serial, &QSerialPort::readyRead, this, &MainWindow::readyRead);
    QObject::connect(&serial,
                     static_cast<void(QSerialPort::*)(QSerialPort::SerialPortError)>
                     (&QSerialPort::error),
                     [&](QSerialPort::SerialPortError error)
    {
        //this is called when a serial communication error occurs
        qDebug() << "An error occured: " << error;
    });

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timerDown);
    timer->start(100);
}

void MainWindow::readyRead()
{
    serialBuf.append(serial.readAll());
}

void MainWindow::timerDown()
{
    int newlineIdx = serialBuf.indexOf('\n');
    if (newlineIdx < 0) {
        return;
    }

    QByteArray show = serialBuf.left(newlineIdx);
    if (show.indexOf("us") >= 0) {
        ui->ultrasonicTextEdit->setPlainText(show);
    }

    // TODO: add conditionals for other GUI components

    serialBuf = serialBuf.remove(0, newlineIdx + 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up serial
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
    if(!serial.open(QIODevice::ReadWrite))
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

    // Read Arduino serial messages every 100 ms
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
    while (newlineIdx >= 0) {
        QByteArray show = serialBuf.left(newlineIdx);
        if (show.indexOf("us") >= 0) {
            ui->ultrasonicTextEdit->setPlainText(show);
        } else if (show.indexOf("ir") >= 0) {
            ui->infraredTextEdit->setPlainText(show);
            qDebug() << show << endl;
        } else if (show.indexOf("pot") >= 0) {
            ui->potentiometerTextEdit->setPlainText(show);
        } else {
            qDebug() << "Unknown message type received from MCU\n";
            qDebug() << show << endl;
        }

        serialBuf = serialBuf.remove(0, newlineIdx + 1);
        newlineIdx = serialBuf.indexOf('\n');
    }
}

MainWindow::~MainWindow()
{
    serial.close();
    delete ui;
}

void MainWindow::serialWrite(QString &str) {
    QByteArray writeData = str.toLatin1();
    qint64 bytesWritten = serial.write(writeData);
    if (bytesWritten == -1) {
        qDebug() << "Failed to write serial data" << endl;
        QCoreApplication::exit(1);
    } else if (bytesWritten != writeData.size()) {
        qDebug() << "Failed to write all the data" << endl;
        QCoreApplication::exit(1);
    }
}

void MainWindow::on_servoPushButton_clicked()
{
    qDebug() << "Wrote servo position" << endl;
    QString str = "sv " + ui->servoAngleLineEdit->text() + "\n";
    serialWrite(str);
}

void MainWindow::on_dcAnglePushButton_clicked()
{
    qDebug() << "Wrote DC motor position" << endl;
    QString str = "da " + ui->dcAngleLineEdit->text();
    serialWrite(str);
}

void MainWindow::on_dcVelocityPushButton_clicked()
{
    qDebug() << "Wrote DC motor velocity" << endl;
    QString str = "dv " + ui->dcVelocityLineEdit->text();
    serialWrite(str);
}

void MainWindow::on_stepperPushButton_clicked()
{
    qDebug() << "Wrote stepper displacement" << endl;
    QString str = "st " + ui->stepperDisplacementLineEdit->text();
    serialWrite(str);
}

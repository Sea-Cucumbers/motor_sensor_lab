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

    // All motors start in GUI mode
    servoControlMethod = 0;
    dcControlMethod = 0;
    stepperControlMethod = 0;
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
    } else if (show.indexOf("ir") >= 0) {
        ui->infraredTextEdit->setPlainText(show);
    } else if (show.indexOf("pot") >= 0) {
        ui->potentiometerTextEdit->setPlainText(show);
    } else {
        qDebug() << "Unknown message type received from MCU\n";
    }

    serialBuf = serialBuf.remove(0, newlineIdx + 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_servoComboBox_currentIndexChanged(int index)
{
    servoControlMethod = index;
    QString str = "svm " + QString::number(index);
    serialWrite(str);
}

void MainWindow::serialWrite(QString &str) {
    QByteArray writeData = str.toUtf8();
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
    if (servoControlMethod == 0) {
        QString str = "svc " + ui->servoAngleLineEdit->text() + " " + ui->servoSpeedLineEdit->text();
        serialWrite(str);
    }
}

void MainWindow::on_dcComboBox_currentIndexChanged(int index)
{
    dcControlMethod = index;
    QString str = "dcm " + QString::number(index);
    serialWrite(str);
}

void MainWindow::on_dcPushButton_clicked()
{
    if (dcControlMethod == 0) {
        QString str = "dcc " + ui->dcAngleLineEdit->text();
        serialWrite(str);
    } else if (dcControlMethod == 1) {
        QString str = "dcc " + ui->dcVelocityLineEdit->text();
        serialWrite(str);
    }
}

void MainWindow::on_stepperComboBox_currentIndexChanged(int index)
{
    stepperControlMethod = index;
    QString str = "stm " + QString::number(index);
    serialWrite(str);
}

void MainWindow::on_stepperPushButton_clicked()
{
    if (stepperControlMethod == 0) {
        QString str = "stc " + ui->stepperDisplacementLineEdit->text();
        serialWrite(str);
    }
}

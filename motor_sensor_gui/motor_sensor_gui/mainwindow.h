#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void readyRead();
    void timerDown();

private slots:
    void on_servoComboBox_currentIndexChanged(int index);

    void on_servoPushButton_clicked();

    void on_dcComboBox_currentIndexChanged(int index);

    void on_dcPushButton_clicked();

    void on_stepperComboBox_currentIndexChanged(int index);

    void on_stepperPushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    QByteArray serialBuf;
    QTimer *timer;

    int servoControlMethod;
    int dcControlMethod;
    int stepperControlMethod;

    void serialWrite(QString &str);
};
#endif // MAINWINDOW_H

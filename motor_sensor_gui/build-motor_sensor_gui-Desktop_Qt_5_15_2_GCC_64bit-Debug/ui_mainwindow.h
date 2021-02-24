/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *infraredLabel;
    QTextEdit *infraredTextEdit;
    QLabel *potentiometerLabel;
    QTextEdit *potentiometerTextEdit;
    QLabel *servoAngleLabel;
    QLineEdit *dcVelocityLineEdit;
    QLabel *dcAngleLabel;
    QLabel *dcVelocityLabel;
    QLineEdit *dcAngleLineEdit;
    QLineEdit *servoAngleLineEdit;
    QPushButton *servoPushButton;
    QPushButton *dcVelocityPushButton;
    QLineEdit *stepperDisplacementLineEdit;
    QLabel *stepperDisplacementLabel;
    QPushButton *stepperPushButton;
    QLabel *ultrasonicLabel;
    QTextEdit *ultrasonicTextEdit;
    QPushButton *dcAnglePushButton;
    QTextEdit *controlModeTextEdit;
    QLabel *controlModeLabel;
    QMenuBar *menubar;
    QMenu *menuMotor_Sensor_GUI;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 624);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        infraredLabel = new QLabel(centralwidget);
        infraredLabel->setObjectName(QString::fromUtf8("infraredLabel"));
        infraredLabel->setGeometry(QRect(140, 60, 216, 17));
        infraredTextEdit = new QTextEdit(centralwidget);
        infraredTextEdit->setObjectName(QString::fromUtf8("infraredTextEdit"));
        infraredTextEdit->setGeometry(QRect(380, 50, 251, 31));
        potentiometerLabel = new QLabel(centralwidget);
        potentiometerLabel->setObjectName(QString::fromUtf8("potentiometerLabel"));
        potentiometerLabel->setGeometry(QRect(140, 100, 144, 17));
        potentiometerTextEdit = new QTextEdit(centralwidget);
        potentiometerTextEdit->setObjectName(QString::fromUtf8("potentiometerTextEdit"));
        potentiometerTextEdit->setGeometry(QRect(380, 90, 251, 31));
        servoAngleLabel = new QLabel(centralwidget);
        servoAngleLabel->setObjectName(QString::fromUtf8("servoAngleLabel"));
        servoAngleLabel->setGeometry(QRect(140, 160, 211, 17));
        dcVelocityLineEdit = new QLineEdit(centralwidget);
        dcVelocityLineEdit->setObjectName(QString::fromUtf8("dcVelocityLineEdit"));
        dcVelocityLineEdit->setGeometry(QRect(440, 320, 113, 25));
        dcAngleLabel = new QLabel(centralwidget);
        dcAngleLabel->setObjectName(QString::fromUtf8("dcAngleLabel"));
        dcAngleLabel->setGeometry(QRect(140, 250, 221, 17));
        dcVelocityLabel = new QLabel(centralwidget);
        dcVelocityLabel->setObjectName(QString::fromUtf8("dcVelocityLabel"));
        dcVelocityLabel->setGeometry(QRect(140, 330, 241, 17));
        dcAngleLineEdit = new QLineEdit(centralwidget);
        dcAngleLineEdit->setObjectName(QString::fromUtf8("dcAngleLineEdit"));
        dcAngleLineEdit->setGeometry(QRect(440, 240, 113, 25));
        servoAngleLineEdit = new QLineEdit(centralwidget);
        servoAngleLineEdit->setObjectName(QString::fromUtf8("servoAngleLineEdit"));
        servoAngleLineEdit->setGeometry(QRect(440, 150, 113, 25));
        servoPushButton = new QPushButton(centralwidget);
        servoPushButton->setObjectName(QString::fromUtf8("servoPushButton"));
        servoPushButton->setGeometry(QRect(440, 190, 121, 25));
        dcVelocityPushButton = new QPushButton(centralwidget);
        dcVelocityPushButton->setObjectName(QString::fromUtf8("dcVelocityPushButton"));
        dcVelocityPushButton->setGeometry(QRect(440, 360, 201, 25));
        stepperDisplacementLineEdit = new QLineEdit(centralwidget);
        stepperDisplacementLineEdit->setObjectName(QString::fromUtf8("stepperDisplacementLineEdit"));
        stepperDisplacementLineEdit->setGeometry(QRect(440, 410, 113, 25));
        stepperDisplacementLabel = new QLabel(centralwidget);
        stepperDisplacementLabel->setObjectName(QString::fromUtf8("stepperDisplacementLabel"));
        stepperDisplacementLabel->setGeometry(QRect(140, 420, 261, 17));
        stepperPushButton = new QPushButton(centralwidget);
        stepperPushButton->setObjectName(QString::fromUtf8("stepperPushButton"));
        stepperPushButton->setGeometry(QRect(440, 450, 151, 25));
        ultrasonicLabel = new QLabel(centralwidget);
        ultrasonicLabel->setObjectName(QString::fromUtf8("ultrasonicLabel"));
        ultrasonicLabel->setGeometry(QRect(140, 20, 230, 17));
        ultrasonicTextEdit = new QTextEdit(centralwidget);
        ultrasonicTextEdit->setObjectName(QString::fromUtf8("ultrasonicTextEdit"));
        ultrasonicTextEdit->setGeometry(QRect(377, 9, 256, 31));
        dcAnglePushButton = new QPushButton(centralwidget);
        dcAnglePushButton->setObjectName(QString::fromUtf8("dcAnglePushButton"));
        dcAnglePushButton->setGeometry(QRect(440, 280, 201, 25));
        controlModeTextEdit = new QTextEdit(centralwidget);
        controlModeTextEdit->setObjectName(QString::fromUtf8("controlModeTextEdit"));
        controlModeTextEdit->setGeometry(QRect(380, 500, 251, 31));
        controlModeLabel = new QLabel(centralwidget);
        controlModeLabel->setObjectName(QString::fromUtf8("controlModeLabel"));
        controlModeLabel->setGeometry(QRect(140, 510, 144, 17));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMotor_Sensor_GUI = new QMenu(menubar);
        menuMotor_Sensor_GUI->setObjectName(QString::fromUtf8("menuMotor_Sensor_GUI"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMotor_Sensor_GUI->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        infraredLabel->setText(QCoreApplication::translate("MainWindow", "Infrared Distance Measurement", nullptr));
        potentiometerLabel->setText(QCoreApplication::translate("MainWindow", "Potentiometer Angle", nullptr));
        servoAngleLabel->setText(QCoreApplication::translate("MainWindow", "Desired Servo Angle (deg)", nullptr));
        dcAngleLabel->setText(QCoreApplication::translate("MainWindow", "Desired DC Motor Angle (deg)", nullptr));
        dcVelocityLabel->setText(QCoreApplication::translate("MainWindow", "Desired DC Motor Velocity (deg/s)", nullptr));
        servoPushButton->setText(QCoreApplication::translate("MainWindow", "Command Servo", nullptr));
        dcVelocityPushButton->setText(QCoreApplication::translate("MainWindow", "Command DC Motor Velocity", nullptr));
        stepperDisplacementLabel->setText(QCoreApplication::translate("MainWindow", "Desired Stepper Displacement (deg)", nullptr));
        stepperPushButton->setText(QCoreApplication::translate("MainWindow", "Command Stepper", nullptr));
        ultrasonicLabel->setText(QCoreApplication::translate("MainWindow", "Ultrasonic Distance Measurement", nullptr));
        dcAnglePushButton->setText(QCoreApplication::translate("MainWindow", "Command DC Motor Angle", nullptr));
        controlModeLabel->setText(QCoreApplication::translate("MainWindow", "Control Mode", nullptr));
        menuMotor_Sensor_GUI->setTitle(QCoreApplication::translate("MainWindow", "Motor Sensor GUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

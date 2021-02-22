/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
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
    QLabel *servoSpeedLabel;
    QLineEdit *servoSpeedLineEdit;
    QLineEdit *dcVelocityLineEdit;
    QLabel *dcAngleLabel;
    QLabel *dcVelocityLabel;
    QLineEdit *dcAngleLineEdit;
    QLineEdit *servoAngleLineEdit;
    QComboBox *dcComboBox;
    QPushButton *servoPushButton;
    QComboBox *servoComboBox;
    QPushButton *dcPushButton;
    QLabel *servoMethodLabel;
    QLabel *dcMethodLabel;
    QComboBox *stepperComboBox;
    QLabel *stepperMethodLabel;
    QLineEdit *stepperDisplacementLineEdit;
    QLabel *stepperDisplacementLabel;
    QPushButton *stepperPushButton;
    QLabel *ultrasonicLabel;
    QTextEdit *ultrasonicTextEdit;
    QMenuBar *menubar;
    QMenu *menuMotor_Sensor_GUI;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 624);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        infraredLabel = new QLabel(centralwidget);
        infraredLabel->setObjectName(QStringLiteral("infraredLabel"));
        infraredLabel->setGeometry(QRect(140, 60, 216, 17));
        infraredTextEdit = new QTextEdit(centralwidget);
        infraredTextEdit->setObjectName(QStringLiteral("infraredTextEdit"));
        infraredTextEdit->setGeometry(QRect(380, 50, 251, 31));
        potentiometerLabel = new QLabel(centralwidget);
        potentiometerLabel->setObjectName(QStringLiteral("potentiometerLabel"));
        potentiometerLabel->setGeometry(QRect(140, 100, 144, 17));
        potentiometerTextEdit = new QTextEdit(centralwidget);
        potentiometerTextEdit->setObjectName(QStringLiteral("potentiometerTextEdit"));
        potentiometerTextEdit->setGeometry(QRect(380, 90, 251, 31));
        servoAngleLabel = new QLabel(centralwidget);
        servoAngleLabel->setObjectName(QStringLiteral("servoAngleLabel"));
        servoAngleLabel->setGeometry(QRect(140, 190, 211, 17));
        servoSpeedLabel = new QLabel(centralwidget);
        servoSpeedLabel->setObjectName(QStringLiteral("servoSpeedLabel"));
        servoSpeedLabel->setGeometry(QRect(140, 230, 201, 17));
        servoSpeedLineEdit = new QLineEdit(centralwidget);
        servoSpeedLineEdit->setObjectName(QStringLiteral("servoSpeedLineEdit"));
        servoSpeedLineEdit->setGeometry(QRect(440, 220, 113, 25));
        dcVelocityLineEdit = new QLineEdit(centralwidget);
        dcVelocityLineEdit->setObjectName(QStringLiteral("dcVelocityLineEdit"));
        dcVelocityLineEdit->setGeometry(QRect(440, 380, 113, 25));
        dcAngleLabel = new QLabel(centralwidget);
        dcAngleLabel->setObjectName(QStringLiteral("dcAngleLabel"));
        dcAngleLabel->setGeometry(QRect(140, 350, 221, 17));
        dcVelocityLabel = new QLabel(centralwidget);
        dcVelocityLabel->setObjectName(QStringLiteral("dcVelocityLabel"));
        dcVelocityLabel->setGeometry(QRect(140, 390, 241, 17));
        dcAngleLineEdit = new QLineEdit(centralwidget);
        dcAngleLineEdit->setObjectName(QStringLiteral("dcAngleLineEdit"));
        dcAngleLineEdit->setGeometry(QRect(440, 340, 113, 25));
        servoAngleLineEdit = new QLineEdit(centralwidget);
        servoAngleLineEdit->setObjectName(QStringLiteral("servoAngleLineEdit"));
        servoAngleLineEdit->setGeometry(QRect(440, 180, 113, 25));
        dcComboBox = new QComboBox(centralwidget);
        dcComboBox->setObjectName(QStringLiteral("dcComboBox"));
        dcComboBox->setGeometry(QRect(440, 300, 151, 25));
        servoPushButton = new QPushButton(centralwidget);
        servoPushButton->setObjectName(QStringLiteral("servoPushButton"));
        servoPushButton->setGeometry(QRect(440, 260, 121, 25));
        servoComboBox = new QComboBox(centralwidget);
        servoComboBox->setObjectName(QStringLiteral("servoComboBox"));
        servoComboBox->setGeometry(QRect(440, 140, 121, 25));
        dcPushButton = new QPushButton(centralwidget);
        dcPushButton->setObjectName(QStringLiteral("dcPushButton"));
        dcPushButton->setGeometry(QRect(440, 420, 151, 25));
        servoMethodLabel = new QLabel(centralwidget);
        servoMethodLabel->setObjectName(QStringLiteral("servoMethodLabel"));
        servoMethodLabel->setGeometry(QRect(140, 150, 181, 17));
        dcMethodLabel = new QLabel(centralwidget);
        dcMethodLabel->setObjectName(QStringLiteral("dcMethodLabel"));
        dcMethodLabel->setGeometry(QRect(140, 300, 181, 17));
        stepperComboBox = new QComboBox(centralwidget);
        stepperComboBox->setObjectName(QStringLiteral("stepperComboBox"));
        stepperComboBox->setGeometry(QRect(440, 460, 151, 25));
        stepperMethodLabel = new QLabel(centralwidget);
        stepperMethodLabel->setObjectName(QStringLiteral("stepperMethodLabel"));
        stepperMethodLabel->setGeometry(QRect(140, 460, 181, 17));
        stepperDisplacementLineEdit = new QLineEdit(centralwidget);
        stepperDisplacementLineEdit->setObjectName(QStringLiteral("stepperDisplacementLineEdit"));
        stepperDisplacementLineEdit->setGeometry(QRect(440, 500, 113, 25));
        stepperDisplacementLabel = new QLabel(centralwidget);
        stepperDisplacementLabel->setObjectName(QStringLiteral("stepperDisplacementLabel"));
        stepperDisplacementLabel->setGeometry(QRect(140, 510, 261, 17));
        stepperPushButton = new QPushButton(centralwidget);
        stepperPushButton->setObjectName(QStringLiteral("stepperPushButton"));
        stepperPushButton->setGeometry(QRect(440, 540, 151, 25));
        ultrasonicLabel = new QLabel(centralwidget);
        ultrasonicLabel->setObjectName(QStringLiteral("ultrasonicLabel"));
        ultrasonicLabel->setGeometry(QRect(140, 20, 230, 17));
        ultrasonicTextEdit = new QTextEdit(centralwidget);
        ultrasonicTextEdit->setObjectName(QStringLiteral("ultrasonicTextEdit"));
        ultrasonicTextEdit->setGeometry(QRect(377, 9, 256, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuMotor_Sensor_GUI = new QMenu(menubar);
        menuMotor_Sensor_GUI->setObjectName(QStringLiteral("menuMotor_Sensor_GUI"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMotor_Sensor_GUI->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        infraredLabel->setText(QApplication::translate("MainWindow", "Infrared Distance Measurement", Q_NULLPTR));
        potentiometerLabel->setText(QApplication::translate("MainWindow", "Potentiometer Angle", Q_NULLPTR));
        servoAngleLabel->setText(QApplication::translate("MainWindow", "Desired Servo Angle (deg)", Q_NULLPTR));
        servoSpeedLabel->setText(QApplication::translate("MainWindow", "Desired Servo Speed (deg/s)", Q_NULLPTR));
        dcAngleLabel->setText(QApplication::translate("MainWindow", "Desired DC Motor Angle (deg)", Q_NULLPTR));
        dcVelocityLabel->setText(QApplication::translate("MainWindow", "Desired DC Motor Velocity (deg/s)", Q_NULLPTR));
        dcComboBox->clear();
        dcComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "GUI Angle Control", Q_NULLPTR)
         << QApplication::translate("MainWindow", "GUI Velocity Control", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Sensor Control", Q_NULLPTR)
        );
        servoPushButton->setText(QApplication::translate("MainWindow", "Command Servo", Q_NULLPTR));
        servoComboBox->clear();
        servoComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "GUI Control", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Sensor Control", Q_NULLPTR)
        );
        dcPushButton->setText(QApplication::translate("MainWindow", "Command DC Motor", Q_NULLPTR));
        servoMethodLabel->setText(QApplication::translate("MainWindow", "Servo Control Method", Q_NULLPTR));
        dcMethodLabel->setText(QApplication::translate("MainWindow", "DC Motor Control Method", Q_NULLPTR));
        stepperComboBox->clear();
        stepperComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "GUI Control", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Sensor Control", Q_NULLPTR)
        );
        stepperMethodLabel->setText(QApplication::translate("MainWindow", "Stepper Control Method", Q_NULLPTR));
        stepperDisplacementLabel->setText(QApplication::translate("MainWindow", "Desired Stepper Displacement (deg)", Q_NULLPTR));
        stepperPushButton->setText(QApplication::translate("MainWindow", "Command Stepper", Q_NULLPTR));
        ultrasonicLabel->setText(QApplication::translate("MainWindow", "Ultrasonic Distance Measurement", Q_NULLPTR));
        menuMotor_Sensor_GUI->setTitle(QApplication::translate("MainWindow", "Motor Sensor GUI", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'simulacion.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULACION_H
#define UI_SIMULACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simulacion
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *simulacion)
    {
        if (simulacion->objectName().isEmpty())
            simulacion->setObjectName(QString::fromUtf8("simulacion"));
        simulacion->resize(1350, 700);
        simulacion->setMinimumSize(QSize(1350, 700));
        simulacion->setMaximumSize(QSize(1350, 700));
        centralwidget = new QWidget(simulacion);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1350, 700));
        graphicsView->setMinimumSize(QSize(1350, 700));
        graphicsView->setMaximumSize(QSize(1350, 700));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1210, 30, 111, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Rockwell"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1210, 90, 111, 41));
        pushButton_2->setFont(font);
        simulacion->setCentralWidget(centralwidget);
        menubar = new QMenuBar(simulacion);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1350, 20));
        simulacion->setMenuBar(menubar);
        statusbar = new QStatusBar(simulacion);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        simulacion->setStatusBar(statusbar);

        retranslateUi(simulacion);

        QMetaObject::connectSlotsByName(simulacion);
    } // setupUi

    void retranslateUi(QMainWindow *simulacion)
    {
        simulacion->setWindowTitle(QApplication::translate("simulacion", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("simulacion", "volver", nullptr));
        pushButton_2->setText(QApplication::translate("simulacion", "iniciar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simulacion: public Ui_simulacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULACION_H

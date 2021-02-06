/********************************************************************************
** Form generated from reading UI file 'principal.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPAL_H
#define UI_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Principal
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QSpinBox *yo1;
    QSpinBox *yd1;
    QSpinBox *dist1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Principal)
    {
        if (Principal->objectName().isEmpty())
            Principal->setObjectName(QString::fromUtf8("Principal"));
        Principal->resize(400, 300);
        Principal->setMinimumSize(QSize(400, 300));
        Principal->setMaximumSize(QSize(400, 300));
        centralwidget = new QWidget(Principal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 400, 300));
        graphicsView->setMinimumSize(QSize(400, 300));
        graphicsView->setMaximumSize(QSize(400, 300));
        QFont font;
        font.setFamily(QString::fromUtf8("Rockwell"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        graphicsView->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 30, 111, 41));
        pushButton->setFont(font);
        yo1 = new QSpinBox(centralwidget);
        yo1->setObjectName(QString::fromUtf8("yo1"));
        yo1->setGeometry(QRect(70, 60, 91, 22));
        yo1->setMaximum(500);
        yd1 = new QSpinBox(centralwidget);
        yd1->setObjectName(QString::fromUtf8("yd1"));
        yd1->setGeometry(QRect(70, 140, 91, 22));
        yd1->setMaximum(500);
        dist1 = new QSpinBox(centralwidget);
        dist1->setObjectName(QString::fromUtf8("dist1"));
        dist1->setGeometry(QRect(70, 230, 91, 22));
        dist1->setMaximum(1150);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 171, 21));
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 110, 181, 21));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 190, 191, 16));
        label_3->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 80, 111, 41));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(260, 130, 111, 41));
        pushButton_3->setFont(font);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(260, 180, 111, 41));
        pushButton_4->setFont(font);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(260, 230, 111, 41));
        pushButton_5->setFont(font);
        Principal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Principal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 20));
        Principal->setMenuBar(menubar);
        statusbar = new QStatusBar(Principal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Principal->setStatusBar(statusbar);

        retranslateUi(Principal);

        QMetaObject::connectSlotsByName(Principal);
    } // setupUi

    void retranslateUi(QMainWindow *Principal)
    {
        Principal->setWindowTitle(QApplication::translate("Principal", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("Principal", "op1", nullptr));
        label->setText(QApplication::translate("Principal", "Altura ca\303\261on ofensivo ", nullptr));
        label_2->setText(QApplication::translate("Principal", "Altura ca\303\261on defensivo ", nullptr));
        label_3->setText(QApplication::translate("Principal", "Distancia que los separa", nullptr));
        pushButton_2->setText(QApplication::translate("Principal", "op2", nullptr));
        pushButton_3->setText(QApplication::translate("Principal", "op3", nullptr));
        pushButton_4->setText(QApplication::translate("Principal", "op4", nullptr));
        pushButton_5->setText(QApplication::translate("Principal", "op5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Principal: public Ui_Principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H

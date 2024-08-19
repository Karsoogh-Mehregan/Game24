/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *calc;
    QAction *lev1;
    QAction *lev2;
    QAction *reload;
    QAction *lev3;
    QAction *lev4;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QLineEdit *ip;
    QPushButton *set_ip;
    QMenuBar *menubar;
    QMenu *menutools;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        calc = new QAction(MainWindow);
        calc->setObjectName(QString::fromUtf8("calc"));
        lev1 = new QAction(MainWindow);
        lev1->setObjectName(QString::fromUtf8("lev1"));
        lev2 = new QAction(MainWindow);
        lev2->setObjectName(QString::fromUtf8("lev2"));
        reload = new QAction(MainWindow);
        reload->setObjectName(QString::fromUtf8("reload"));
        lev3 = new QAction(MainWindow);
        lev3->setObjectName(QString::fromUtf8("lev3"));
        lev4 = new QAction(MainWindow);
        lev4->setObjectName(QString::fromUtf8("lev4"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);

        ip = new QLineEdit(centralwidget);
        ip->setObjectName(QString::fromUtf8("ip"));

        verticalLayout_2->addWidget(ip);

        set_ip = new QPushButton(centralwidget);
        set_ip->setObjectName(QString::fromUtf8("set_ip"));

        verticalLayout_2->addWidget(set_ip);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menutools = new QMenu(menubar);
        menutools->setObjectName(QString::fromUtf8("menutools"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menutools->menuAction());
        menutools->addAction(calc);
        menutools->addAction(lev1);
        menutools->addAction(lev2);
        menutools->addAction(lev3);
        menutools->addAction(lev4);
        menutools->addAction(reload);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        calc->setText(QApplication::translate("MainWindow", "calculate", nullptr));
        lev1->setText(QApplication::translate("MainWindow", "deactivate leverage 1", nullptr));
        lev2->setText(QApplication::translate("MainWindow", "activate leverage 2", nullptr));
        reload->setText(QApplication::translate("MainWindow", "reload", nullptr));
#ifndef QT_NO_SHORTCUT
        reload->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        lev3->setText(QApplication::translate("MainWindow", "activate lev3", nullptr));
        lev4->setText(QApplication::translate("MainWindow", "lev4", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "A", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "score", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "status", nullptr));
        ip->setText(QApplication::translate("MainWindow", "http://127.0.0.1:3000/", nullptr));
        set_ip->setText(QApplication::translate("MainWindow", "set ip", nullptr));
        menutools->setTitle(QApplication::translate("MainWindow", "tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

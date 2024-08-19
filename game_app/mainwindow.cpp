#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <qjsonarray.h>
#include <QLineEdit>
#include <QPushButton>
#include "team.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    

   

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &MainWindow::onCellClicked);
    connect(this, SIGNAL(get_ip()), this, SLOT(get_ip_slot()));
    connect(ui->calc, &QAction::triggered, []() {QJsonDocument response = Request::post(path + "calculate", {}); });
    connect(ui->reload, &QAction::triggered, [this]() {load(); });
    connect(ui->lev1, &QAction::triggered, [this]() {QJsonDocument response = Request::post(path + "toggle-lev-1", {}); load(); });
    connect(ui->lev2, &QAction::triggered, [this]() {QJsonDocument response = Request::post(path + "toggle-lev-2", {}); load(); });
    connect(ui->lev3, &QAction::triggered, [this]() {QJsonDocument response = Request::post(path + "toggle-lev-3", {}); load(); });
    connect(ui->lev4, &QAction::triggered, [this]() {QJsonDocument response = Request::post(path + "toggle-lev-4", {}); load(); });
    connect(ui->set_ip, &QPushButton::clicked, [this]() {path = ui->ip->text(); });
    emit get_ip();





}
void MainWindow::onCellClicked(int row, int column) {
    Team* team_window = new Team(ui->tableWidget->item(row,0)->text().toInt());
    connect(team_window, &QWidget::destroyed, this, &MainWindow::reload);
    team_window->show();
}
void MainWindow::load() {
    {
        ui->ip->setText(path);
        QJsonDocument response = Request::get(path + "teams", {});
        QJsonArray jsonArray = response.array();
        ui->tableWidget->setRowCount(jsonArray.size());
        for (int i = 0; i < jsonArray.size(); i++) {
            auto object = jsonArray[i].toObject();
            QTableWidgetItem* item0 = new QTableWidgetItem(QString::number(object.value("id").toInt()));
            QTableWidgetItem* item1 = new QTableWidgetItem(object.value("name").toString());
            QTableWidgetItem* item2 = new QTableWidgetItem(QString::number(object.value("A").toDouble()));
            QTableWidgetItem* item3 = new QTableWidgetItem(QString::number(object.value("B").toDouble()));
            QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(object.value("score").toDouble()));
            QTableWidgetItem* item5 = new QTableWidgetItem(object.value("status").toString());


            ui->tableWidget->setItem(i, 0, item0);
            ui->tableWidget->setItem(i, 1, item1);
            ui->tableWidget->setItem(i, 2, item2);
            ui->tableWidget->setItem(i, 3, item3);
            ui->tableWidget->setItem(i, 4, item4);
            ui->tableWidget->setItem(i, 5, item5);

        }
        
        ui->tableWidget->show();
    }
    {
        QJsonDocument response = Request::get(path + "get-leverages", {});
        QJsonObject obj = response.object();
        if (obj["lev1"].toBool()) {
            ui->lev1->setText("deactivate increase game score");

        }
        else {
            ui->lev1->setText("activate increase game score");


        }
        if (obj["lev2"].toBool()) {
            ui->lev2->setText("deactivate B currency for questions");

        }
        else {
            ui->lev2->setText("activate B uorrency for questions");


        }
        if (obj["lev3"].toBool()) {
            ui->lev3->setText("deactivate increase duel prize");

        }
        else {
            ui->lev3->setText("activateB increase duel prize");


        }
        if (obj["lev4"].toBool()) {
            ui->lev4->setText("deactivate A currency for playground");

        }
        else {
            ui->lev4->setText("activate A currency for playground");


        }

    }

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::get_ip_slot() {
    bool flag = false;
    while (1) {
        IpInputDialog ipDialog(this);
        if (ipDialog.exec() == QDialog::Accepted) {
            path = ipDialog.getIpAddress();
            QJsonDocument response = Request::get(path, {});
            QJsonObject obj = response.object();
            ipDialog.close();
            if (obj.find("error") == obj.end()) {
                break;
            }

        }
        else {
            flag = true;
            ipDialog.close();

            break;


        }
    }
    if (flag) {
        this->close();
        return;

    }
    load();
}



void MainWindow::reload() {
    load();
}









IpInputDialog::IpInputDialog(QWidget* parent) :
    QDialog(parent),
    lineEdit(new QLineEdit(this)),
    okButton(new QPushButton("OK", this)),
    cancelButton(new QPushButton("Cancel", this))
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* buttonLayout = new QHBoxLayout;

    mainLayout->addWidget(lineEdit);
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    mainLayout->addLayout(buttonLayout);

    connect(okButton, &QPushButton::clicked, this, &IpInputDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &IpInputDialog::reject);

    setLayout(mainLayout);
    setWindowTitle("Enter IP Address");
}

IpInputDialog::~IpInputDialog()
{
    // No need to delete ui elements manually; Qt takes care of it.
}

QString IpInputDialog::getIpAddress() const
{
    return lineEdit->text();
}

void IpInputDialog::accept()
{
    // Add validation if necessary
    QDialog::accept();
}



#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qmainwindow.h>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkRequest>
#include <QUrl>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "request.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class IpInputDialog;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void load();
    ~MainWindow();
signals:
    void get_ip();
public slots:
    void reload();
    void onCellClicked(int row, int column);
    void get_ip_slot();



private:
    Ui::MainWindow *ui;
};











class IpInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IpInputDialog(QWidget* parent = nullptr);
    ~IpInputDialog();

    QString getIpAddress() const;

private slots:
    void accept() override;

private:
    QLineEdit* lineEdit;
    QPushButton* okButton;
    QPushButton* cancelButton;
};
#endif // MAINWINDOW_H

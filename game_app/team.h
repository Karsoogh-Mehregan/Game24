#ifndef TEAM_H
#define TEAM_H

#include <QWidget>
#include <QObject>
#include <qlineedit.h>
#include <qlabel.h>
#include <QVariant>
#include <QDialog>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include  <QMainWindow>

namespace Ui {
class Team;
}

class Team : public QWidget
{
    Q_OBJECT

public:
    explicit Team(int id,QMainWindow *parent = nullptr);
    ~Team();
    void load();
    void showMess(QJsonDocument _resp);
signals:
    void reload_parent();
private slots:
    void exchangeA();
    void exchangeB();
    void buy();
    void solve();
    void duel();
    void accept();
    void reject();
    void win();
    void loose();
    void loose_game();
    void win_game();
    void play();
    void set_b();
    void set_a();
    void buy_random();

private:
    Ui::Team *ui;
    int id;
};










class IntegerInputDialog : public QDialog {
    Q_OBJECT

public:
    IntegerInputDialog(QWidget* parent = nullptr);
    int getInteger() const;

private slots:
    void onConfirmButtonClicked();

private:
    QLineEdit* lineEdit;
    QPushButton* confirmButton;
    QLabel* label;
    int inputValue;
};
#endif // TEAM_H

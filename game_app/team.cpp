#include "team.h"
#include "ui_team.h"
#include <qjsonarray.h>
#include "request.h"
#include <QMessageBox>

Team::Team(int id,QMainWindow *parent) :
    QWidget(parent),
    ui(new Ui::Team)
{
    ui->setupUi(this);
    connect(this, SIGNAL(finished()), parent, SLOT(reload()));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->duel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->games->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->duel->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->games->setEditTriggers(QAbstractItemView::NoEditTriggers);

    

    this->id = id;
    load();
    connect(ui->buy, SIGNAL(clicked()), this, SLOT(buy()));
    connect(ui->random, SIGNAL(clicked()), this, SLOT(buy_random()));
    connect(ui->solve, SIGNAL(clicked()), this, SLOT(solve()));
    connect(ui->A_exchange_btn, SIGNAL(clicked()), this, SLOT(exchangeA()));
    connect(ui->B_exchange_btn, SIGNAL(clicked()), this, SLOT(exchangeB()));
    connect(ui->duel_btn, SIGNAL(clicked()), this, SLOT(duel()));
    connect(ui->accpet, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->reject, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->loose, SIGNAL(clicked()), this, SLOT(loose()));
    connect(ui->win, SIGNAL(clicked()), this, SLOT(win()));
    connect(ui->win_game, SIGNAL(clicked()), this, SLOT(win_game()));
    connect(ui->loose_game, SIGNAL(clicked()), this, SLOT(loose_game()));
    connect(ui->play, SIGNAL(clicked()), this, SLOT(play()));
    connect(ui->change_a, &QPushButton::clicked, this, &Team::set_a);
    connect(ui->change_b, &QPushButton::clicked, this, &Team::set_b);
    

}
void Team::load() {
    {
        QJsonDocument response = Request::get(path + "team/" + QString::number(id), {});
        QJsonObject jsonObject = response.object();
        ui->A_amount->setText(QString::number(jsonObject["A"].toDouble()));
        ui->B_amount->setText(QString::number(jsonObject["B"].toDouble()));
        ui->score->setText(QString::number(jsonObject["score"].toDouble()));
        ui->name->setText(jsonObject["name"].toString());
        ui->status->setText(jsonObject["status"].toString());

    }

    {
        QJsonDocument response = Request::get(path + "questions/" + QString::number(id), {});
        QJsonArray jsonArray = response.array();
        ui->tableWidget->setRowCount(jsonArray.size());
        for (int i = 0; i < jsonArray.size(); i++) {
            auto object = jsonArray[i].toObject();
            QTableWidgetItem* item0 = new QTableWidgetItem(QString::number(object.value("number").toInt()));
            QTableWidgetItem* item1;
            QTableWidgetItem* item2;
            QTableWidgetItem* item3;
            QTableWidgetItem* item4;
            
            item1 = new QTableWidgetItem(QString::number(object.value("price").toDouble()));
            item2 = new QTableWidgetItem(QString::number(object.value("max-score").toDouble()));
            item3 = new QTableWidgetItem(QString::number(object.value("score").toDouble()));
            
            if (object.value("bought").toBool()) {

                item4 = new QTableWidgetItem("+");
                item4->setBackgroundColor(Qt::green);
            }
            else {
                item4 = new QTableWidgetItem("-");
                item4->setBackgroundColor(Qt::red);

            }

            ui->tableWidget->setItem(i, 0, item0);
            ui->tableWidget->setItem(i, 1, item1);
            ui->tableWidget->setItem(i, 2, item2);
            ui->tableWidget->setItem(i, 3, item3);
            ui->tableWidget->setItem(i, 4, item4);


        }

        ui->tableWidget->show();
    }
    {
        QJsonDocument response = Request::get(path + "teams", {});
        QJsonArray jsonArray = response.array();
        ui->duel->setRowCount(jsonArray.size()-1);
        bool reached = false;
        for (int i = 0; i < jsonArray.size(); i++) {

            auto object = jsonArray[i].toObject();
            if (id == object.value("id").toInt()) {
                reached = true;
                continue;
            }
            QTableWidgetItem* item0 = new QTableWidgetItem(QString::number(object.value("id").toInt()));
            QTableWidgetItem* item1 = new QTableWidgetItem(object.value("name").toString());
            QTableWidgetItem* item2 = new QTableWidgetItem(object.value("status").toString());


            ui->duel->setItem(i-reached, 0, item0);
            ui->duel->setItem(i-reached, 1, item1);
            ui->duel->setItem(i-reached, 2, item2);
            
        }

        ui->duel->show();
    }
    {
        QJsonDocument response = Request::get(path + "duel/"+QString::number(id), {});
        QJsonObject jsonObject = response.object();
        if (jsonObject["active"].toBool()) {
            ui->attacker->setText(jsonObject["attacker"].toString());
            ui->defender->setText(jsonObject["defender"].toString());
            ui->duel_frame->show();
            ui->invitation_frame->hide();

        }
        else if (jsonObject["invitation"].toBool()) {
            ui->invitation_frame->show();
            ui->duel_frame->hide();
            ui->attacker_invitation->setText(jsonObject["attacker"].toString());


        }else{
            ui->duel_frame->hide();
            ui->invitation_frame->hide();
        }



    }

    {
        QJsonDocument response = Request::get(path + "game/"+QString::number(id), {});
        QJsonObject jsonObject = response.object();
        if (jsonObject["active"].toBool()) {
            ui->game_frame->show();
            ui->game_name->setText(jsonObject["name"].toString());
        }
        else {
            ui->game_frame->hide();
        }

    }

    {
        QJsonDocument response = Request::get(path + "games", {});
        QJsonArray jsonArray = response.array();
        ui->games->setRowCount(jsonArray.size() );
        for (int i = 0; i < jsonArray.size(); i++) {

            auto object = jsonArray[i].toObject();
           
            
            QTableWidgetItem* item0 = new QTableWidgetItem(object.value("name").toString());
            QTableWidgetItem* item1 = new QTableWidgetItem(QString::number(object.value("value").toDouble()));
            QTableWidgetItem* item2 = new QTableWidgetItem(QString::number(object.value("score").toDouble()));


            ui->games->setItem(i, 0, item0);
            ui->games->setItem(i, 1, item1);
            ui->games->setItem(i, 2, item2);

        }

        ui->games->show();
    }



}
void Team::exchangeA() {
    QJsonObject obj;
    obj["amount"] = ui->A_exchange->text().toFloat();
    obj["team_id"] = id;
    QJsonDocument response = Request::post(path + "exchange/A", QJsonDocument(obj));
    load();
    
    showMess(response);

}
void Team::exchangeB() {
    QJsonObject obj;
    obj["amount"] = ui->b_exchange->text().toFloat();
    obj["team_id"] = id;
    QJsonDocument response = Request::post(path + "exchange/B", QJsonDocument(obj));
    load();
    
    showMess(response);

}


void Team::showMess(QJsonDocument _resp) {
    QJsonObject resp = _resp.object();
    if (resp.find("error") != resp.end()) {
        QMessageBox::warning(this, "ERROR", resp["error"].toString());


    }else if (resp.find("message") != resp.end()) {
        QMessageBox::information(this, "message", resp["message"].toString());


    }
    else {
        QMessageBox::warning(this, "ERROR", "UNKNOWN ERROR");


    }

}

void Team::play() {
    if (ui->games->selectedItems().isEmpty()) {
        QMessageBox::warning(this, "ERROR", "no question is selected");
        return;
    }
    QString game_name= ui->games->item(ui->games->selectedItems().first()->row(), 0)->text();
    QJsonObject obj;
    obj["game_name"] = game_name;
    obj["team_id"] = id;
    QJsonDocument response = Request::post(path + "start-game", QJsonDocument(obj));
    load();

    showMess(response);

}
void Team::set_a() {
    QJsonObject obj;
    obj["amount"] = ui->A_amount->text().toFloat();
    obj["team_id"] = id;
    QJsonDocument response = Request::post(path + "set-a", QJsonDocument(obj));
    load();

    showMess(response);

}
void Team::set_b() {
    QJsonObject obj;
    obj["amount"] = ui->B_amount->text().toFloat();
    obj["team_id"] = id;
    QJsonDocument response = Request::post(path + "set-b", QJsonDocument(obj));
    load();

    showMess(response);

}
void Team::buy_random() {
    QJsonObject obj;

    obj["team_id"] = id;
    QJsonDocument response = Request::post(path + "buy-random", QJsonDocument(obj));
    load();

    showMess(response);


}
void Team::buy() {
    if (ui->tableWidget->selectedItems().isEmpty()) {
        QMessageBox::warning(this, "ERROR", "no question is selected");
        return;
    }
    int q_id = ui->tableWidget->item(ui->tableWidget->selectedItems().first()->row(),0)->text().toInt();
    QJsonObject obj;
    obj["team_id"] = id;
    obj["question_id"] = q_id;
    QJsonDocument response = Request::post(path + "buy", QJsonDocument(obj));
    load();

    showMess(response);
    
}
void Team::solve() {
    if (ui->tableWidget->selectedItems().isEmpty()) {
        QMessageBox::warning(this, "ERROR", "no question is selected");
        return;
    }
    int q_id = ui->tableWidget->item(ui->tableWidget->selectedItems().first()->row(), 0)->text().toInt();
    IntegerInputDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        int score = dialog.getInteger();
        QJsonObject obj;
        obj["team_id"] = id;
        obj["question_id"] = q_id;
        obj["score"] = score;
        QJsonDocument response = Request::post(path + "set-score", QJsonDocument(obj));
        load();
        showMess(response);
        
    }
}
void Team::duel() {
    if (ui->duel->selectedItems().isEmpty()) {
        QMessageBox::warning(this, "ERROR", "no team is selected");
        return;
    }
    
    int defender = ui->duel->item(ui->duel->selectedItems().first()->row(), 0)->text().toInt();
   
    QJsonObject obj;
    obj["attacker_id"] = id;
    obj["defender_id"] = defender;
    QJsonDocument response = Request::post(path + "attack", QJsonDocument(obj));
    load();

    showMess(response);

}
void Team::accept() {

    QJsonObject obj;
    obj["defender_id"] = id;
    QJsonDocument response = Request::post(path + "accept", QJsonDocument(obj));
    load();

    showMess(response);
}
void Team::reject() {
    QJsonObject obj;
    obj["defender_id"] = id;
    QJsonDocument response = Request::post(path + "reject", QJsonDocument(obj));
    load();

    showMess(response);
}
void Team::loose() {
    QJsonDocument get_response = Request::get(path + "duel/" + QString::number(id), {});
    QJsonObject jsonObject = get_response.object();
    QJsonObject obj;
    int winner_id;

    if (jsonObject["defender_id"].toInt() != id) {
        winner_id = jsonObject["defender_id"].toInt();
    }
    else {
        winner_id = jsonObject["attacker_id"].toInt();
    }
    
    obj["defender_id"] = jsonObject["defender_id"].toInt();
    obj["winner_id"] = winner_id;

    QJsonDocument response = Request::post(path + "end-duel", QJsonDocument(obj));
    load();

    showMess(response);

}
void Team::win() {
    QJsonDocument get_response = Request::get(path + "duel/" + QString::number(id), {});
    QJsonObject jsonObject = get_response.object();
    QJsonObject obj;
    obj["defender_id"] = jsonObject["defender_id"].toInt();
    obj["winner_id"] = id;
    QJsonDocument response = Request::post(path + "end-duel", QJsonDocument(obj));
    load();

    showMess(response);

}



void Team::loose_game() {
    QJsonDocument get_response = Request::get(path + "duel/" + QString::number(id), {});
    QJsonObject jsonObject = get_response.object();
    QJsonObject obj;
        

    obj["team_id"] = id;
    obj["won"] = false;

    QJsonDocument response = Request::post(path + "end-game", QJsonDocument(obj));
    load();

    showMess(response);

}
void Team::win_game() {
    QJsonDocument get_response = Request::get(path + "duel/" + QString::number(id), {});
    QJsonObject jsonObject = get_response.object();
    QJsonObject obj;


    obj["team_id"] = id;
    obj["won"] = true;

    QJsonDocument response = Request::post(path + "end-game", QJsonDocument(obj));
    load();

    showMess(response);

}
Team::~Team()
{
    delete ui;
}






IntegerInputDialog::IntegerInputDialog(QWidget* parent) : QDialog(parent), inputValue(0) {
    lineEdit = new QLineEdit(this);
    confirmButton = new QPushButton("Confirm", this);
    label = new QLabel("Enter an integer:", this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(confirmButton);

    lineEdit->setValidator(new QIntValidator(this)); // Only allow integer input

    connect(confirmButton, &QPushButton::clicked, this, &IntegerInputDialog::onConfirmButtonClicked);
}

void IntegerInputDialog::onConfirmButtonClicked() {
    bool ok;
    int value = lineEdit->text().toInt(&ok);

    if (ok) {
        inputValue = value;
        accept();
    }
    else {
        QMessageBox::warning(this, "Invalid input", "Please enter a valid integer.");
    }
}

int IntegerInputDialog::getInteger() const {
    return inputValue;
}
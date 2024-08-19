/********************************************************************************
** Form generated from reading UI file 'team.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAM_H
#define UI_TEAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Team
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_8;
    QLabel *name;
    QLabel *score;
    QHBoxLayout *horizontalLayout_8;
    QLabel *status_2;
    QLabel *status;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *duel;
    QPushButton *duel_btn;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *buy;
    QPushButton *solve;
    QPushButton *random;
    QVBoxLayout *verticalLayout_11;
    QTableWidget *games;
    QPushButton *play;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *A_exchange;
    QPushButton *A_exchange_btn;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *b_exchange;
    QPushButton *B_exchange_btn;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *A_amount;
    QLabel *A_2;
    QPushButton *change_a;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *B_amount;
    QLabel *A_3;
    QPushButton *change_b;
    QFrame *duel_frame;
    QLabel *label_3;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLabel *attacker;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLabel *defender;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_7;
    QPushButton *loose;
    QPushButton *win;
    QFrame *invitation_frame;
    QLabel *label_6;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_9;
    QPushButton *accpet;
    QPushButton *reject;
    QLabel *attacker_invitation;
    QLabel *label_7;
    QFrame *game_frame;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_10;
    QPushButton *loose_game;
    QPushButton *win_game;
    QLabel *label_8;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLabel *game_name;

    void setupUi(QWidget *Team)
    {
        if (Team->objectName().isEmpty())
            Team->setObjectName(QString::fromUtf8("Team"));
        Team->resize(1612, 674);
        layoutWidget = new QWidget(Team);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 0, 151, 106));
        verticalLayout_8 = new QVBoxLayout(layoutWidget);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(layoutWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setStyleSheet(QString::fromUtf8("font-size:30px;\n"
""));

        verticalLayout_8->addWidget(name);

        score = new QLabel(layoutWidget);
        score->setObjectName(QString::fromUtf8("score"));
        score->setStyleSheet(QString::fromUtf8("color:red;font-size:20px;"));

        verticalLayout_8->addWidget(score);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        status_2 = new QLabel(layoutWidget);
        status_2->setObjectName(QString::fromUtf8("status_2"));

        horizontalLayout_8->addWidget(status_2);

        status = new QLabel(layoutWidget);
        status->setObjectName(QString::fromUtf8("status"));

        horizontalLayout_8->addWidget(status);


        verticalLayout_8->addLayout(horizontalLayout_8);

        layoutWidget1 = new QWidget(Team);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 240, 1551, 421));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        duel = new QTableWidget(layoutWidget1);
        if (duel->columnCount() < 3)
            duel->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        duel->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        duel->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        duel->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        duel->setObjectName(QString::fromUtf8("duel"));

        verticalLayout_5->addWidget(duel);

        duel_btn = new QPushButton(layoutWidget1);
        duel_btn->setObjectName(QString::fromUtf8("duel_btn"));

        verticalLayout_5->addWidget(duel_btn);


        horizontalLayout_5->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tableWidget = new QTableWidget(layoutWidget1);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_4->addWidget(tableWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        buy = new QPushButton(layoutWidget1);
        buy->setObjectName(QString::fromUtf8("buy"));

        verticalLayout_3->addWidget(buy);

        solve = new QPushButton(layoutWidget1);
        solve->setObjectName(QString::fromUtf8("solve"));

        verticalLayout_3->addWidget(solve);

        random = new QPushButton(layoutWidget1);
        random->setObjectName(QString::fromUtf8("random"));

        verticalLayout_3->addWidget(random);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        games = new QTableWidget(layoutWidget1);
        if (games->columnCount() < 3)
            games->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        games->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        games->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        games->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        games->setObjectName(QString::fromUtf8("games"));

        verticalLayout_11->addWidget(games);

        play = new QPushButton(layoutWidget1);
        play->setObjectName(QString::fromUtf8("play"));

        verticalLayout_11->addWidget(play);


        horizontalLayout_5->addLayout(verticalLayout_11);

        horizontalLayout_5->setStretch(0, 2);
        horizontalLayout_5->setStretch(1, 1);
        layoutWidget2 = new QWidget(Team);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 100, 209, 139));
        verticalLayout_12 = new QVBoxLayout(layoutWidget2);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        A_exchange = new QLineEdit(layoutWidget2);
        A_exchange->setObjectName(QString::fromUtf8("A_exchange"));

        horizontalLayout_3->addWidget(A_exchange);

        A_exchange_btn = new QPushButton(layoutWidget2);
        A_exchange_btn->setObjectName(QString::fromUtf8("A_exchange_btn"));

        horizontalLayout_3->addWidget(A_exchange_btn);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        b_exchange = new QLineEdit(layoutWidget2);
        b_exchange->setObjectName(QString::fromUtf8("b_exchange"));

        horizontalLayout_4->addWidget(b_exchange);

        B_exchange_btn = new QPushButton(layoutWidget2);
        B_exchange_btn->setObjectName(QString::fromUtf8("B_exchange_btn"));

        horizontalLayout_4->addWidget(B_exchange_btn);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_12->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        A_amount = new QLineEdit(layoutWidget2);
        A_amount->setObjectName(QString::fromUtf8("A_amount"));

        horizontalLayout->addWidget(A_amount);

        A_2 = new QLabel(layoutWidget2);
        A_2->setObjectName(QString::fromUtf8("A_2"));

        horizontalLayout->addWidget(A_2);

        change_a = new QPushButton(layoutWidget2);
        change_a->setObjectName(QString::fromUtf8("change_a"));

        horizontalLayout->addWidget(change_a);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        B_amount = new QLineEdit(layoutWidget2);
        B_amount->setObjectName(QString::fromUtf8("B_amount"));

        horizontalLayout_2->addWidget(B_amount);

        A_3 = new QLabel(layoutWidget2);
        A_3->setObjectName(QString::fromUtf8("A_3"));

        horizontalLayout_2->addWidget(A_3);

        change_b = new QPushButton(layoutWidget2);
        change_b->setObjectName(QString::fromUtf8("change_b"));

        horizontalLayout_2->addWidget(change_b);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_12->addLayout(verticalLayout);

        duel_frame = new QFrame(Team);
        duel_frame->setObjectName(QString::fromUtf8("duel_frame"));
        duel_frame->setGeometry(QRect(280, 100, 321, 131));
        duel_frame->setStyleSheet(QString::fromUtf8("#duel_frame{border: 2px solid black;}"));
        duel_frame->setFrameShape(QFrame::StyledPanel);
        duel_frame->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(duel_frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 151, 20));
        layoutWidget3 = new QWidget(duel_frame);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 40, 141, 81));
        verticalLayout_6 = new QVBoxLayout(layoutWidget3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_7->addWidget(label_4);

        attacker = new QLabel(layoutWidget3);
        attacker->setObjectName(QString::fromUtf8("attacker"));

        horizontalLayout_7->addWidget(attacker);


        verticalLayout_6->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        defender = new QLabel(layoutWidget3);
        defender->setObjectName(QString::fromUtf8("defender"));

        horizontalLayout_6->addWidget(defender);


        verticalLayout_6->addLayout(horizontalLayout_6);

        layoutWidget4 = new QWidget(duel_frame);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(200, 30, 82, 91));
        verticalLayout_7 = new QVBoxLayout(layoutWidget4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        loose = new QPushButton(layoutWidget4);
        loose->setObjectName(QString::fromUtf8("loose"));

        verticalLayout_7->addWidget(loose);

        win = new QPushButton(layoutWidget4);
        win->setObjectName(QString::fromUtf8("win"));

        verticalLayout_7->addWidget(win);

        invitation_frame = new QFrame(Team);
        invitation_frame->setObjectName(QString::fromUtf8("invitation_frame"));
        invitation_frame->setGeometry(QRect(630, 100, 321, 131));
        invitation_frame->setStyleSheet(QString::fromUtf8("#invitation_frame{border: 2px solid black;}"));
        invitation_frame->setFrameShape(QFrame::StyledPanel);
        invitation_frame->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(invitation_frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 10, 181, 20));
        layoutWidget_3 = new QWidget(invitation_frame);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(230, 20, 82, 91));
        verticalLayout_9 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        accpet = new QPushButton(layoutWidget_3);
        accpet->setObjectName(QString::fromUtf8("accpet"));

        verticalLayout_9->addWidget(accpet);

        reject = new QPushButton(layoutWidget_3);
        reject->setObjectName(QString::fromUtf8("reject"));

        verticalLayout_9->addWidget(reject);

        attacker_invitation = new QLabel(invitation_frame);
        attacker_invitation->setObjectName(QString::fromUtf8("attacker_invitation"));
        attacker_invitation->setGeometry(QRect(80, 50, 137, 51));
        label_7 = new QLabel(invitation_frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 50, 65, 51));
        game_frame = new QFrame(Team);
        game_frame->setObjectName(QString::fromUtf8("game_frame"));
        game_frame->setGeometry(QRect(280, 0, 321, 91));
        game_frame->setFrameShape(QFrame::StyledPanel);
        game_frame->setFrameShadow(QFrame::Raised);
        layoutWidget_2 = new QWidget(game_frame);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(230, 0, 82, 91));
        verticalLayout_10 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        loose_game = new QPushButton(layoutWidget_2);
        loose_game->setObjectName(QString::fromUtf8("loose_game"));

        verticalLayout_10->addWidget(loose_game);

        win_game = new QPushButton(layoutWidget_2);
        win_game->setObjectName(QString::fromUtf8("win_game"));

        verticalLayout_10->addWidget(win_game);

        label_8 = new QLabel(game_frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 10, 181, 20));
        layoutWidget5 = new QWidget(game_frame);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(20, 50, 114, 18));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);

        game_name = new QLabel(layoutWidget5);
        game_name->setObjectName(QString::fromUtf8("game_name"));

        horizontalLayout_9->addWidget(game_name);


        retranslateUi(Team);

        QMetaObject::connectSlotsByName(Team);
    } // setupUi

    void retranslateUi(QWidget *Team)
    {
        Team->setWindowTitle(QApplication::translate("Team", "Form", nullptr));
        name->setText(QApplication::translate("Team", "TextLabel", nullptr));
        score->setText(QApplication::translate("Team", "TextLabel", nullptr));
        status_2->setText(QApplication::translate("Team", "status:", nullptr));
        status->setText(QApplication::translate("Team", "stat", nullptr));
        QTableWidgetItem *___qtablewidgetitem = duel->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Team", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = duel->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Team", "name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = duel->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Team", "status", nullptr));
        duel_btn->setText(QApplication::translate("Team", "Duel", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Team", "Question Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Team", "price", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("Team", "max-score", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("Team", "score", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("Team", "bought", nullptr));
        buy->setText(QApplication::translate("Team", "buy", nullptr));
        solve->setText(QApplication::translate("Team", "solve", nullptr));
        random->setText(QApplication::translate("Team", "buy random", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = games->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("Team", "name", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = games->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("Team", "cost", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = games->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("Team", "score", nullptr));
        play->setText(QApplication::translate("Team", "play", nullptr));
        A_exchange_btn->setText(QApplication::translate("Team", "exchange A", nullptr));
        B_exchange_btn->setText(QApplication::translate("Team", "exchange B", nullptr));
        label->setText(QApplication::translate("Team", "A currency", nullptr));
        A_2->setText(QApplication::translate("Team", "$", nullptr));
        change_a->setText(QApplication::translate("Team", "change", nullptr));
        label_2->setText(QApplication::translate("Team", "B currency", nullptr));
        A_3->setText(QApplication::translate("Team", "$", nullptr));
        change_b->setText(QApplication::translate("Team", "change", nullptr));
        label_3->setText(QApplication::translate("Team", "you have an active battle", nullptr));
        label_4->setText(QApplication::translate("Team", "attacker:", nullptr));
        attacker->setText(QString());
        label_5->setText(QApplication::translate("Team", "defender", nullptr));
        defender->setText(QString());
        loose->setText(QApplication::translate("Team", "loose", nullptr));
        win->setText(QApplication::translate("Team", "win", nullptr));
        label_6->setText(QApplication::translate("Team", "you have a duel invitaions", nullptr));
        accpet->setText(QApplication::translate("Team", "accept", nullptr));
        reject->setText(QApplication::translate("Team", "reject", nullptr));
        attacker_invitation->setText(QString());
        label_7->setText(QApplication::translate("Team", "attacker:", nullptr));
        loose_game->setText(QApplication::translate("Team", "loose", nullptr));
        win_game->setText(QApplication::translate("Team", "win", nullptr));
        label_8->setText(QApplication::translate("Team", "you have an active game", nullptr));
        label_9->setText(QApplication::translate("Team", "game:", nullptr));
        game_name->setText(QApplication::translate("Team", "game name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Team: public Ui_Team {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAM_H

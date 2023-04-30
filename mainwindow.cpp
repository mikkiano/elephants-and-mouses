#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recordsdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newGameButton_clicked()
{
    bool accepted;
    QString input = QInputDialog::getText(this, "Новая игра",
                                          "Введите имя игрока:", QLineEdit::Normal,
                                          "Вася", &accepted);
    if (accepted){
        if(records.find(input) != records.end()){
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Новая игра", "Рекорд будет перезаписан",
                                          QMessageBox::Ok|QMessageBox::Cancel);
            if (reply != QMessageBox::Ok){
                return;
            }
        }

        player_name = input;
        game = new Game();
        ui->statusLabel->setText(QString("Игра началась"));
        ui->checkButton->setDisabled(false);
        ui->userInput->setDisabled(false);
        ui->gameTableWidget->setRowCount(0);

    }
}


void MainWindow::on_checkButton_clicked()
{
    QString userInput = ui->userInput->text();
    QRegularExpression  re("^\\d{4}$");

    if (re.match(userInput).hasMatch()){
        auto result =  game->countBullsAndCows(userInput);
        ui->gameTableWidget->insertRow( ui->gameTableWidget->rowCount() );
        ui->gameTableWidget->setItem(ui->gameTableWidget->rowCount() - 1, 0, new QTableWidgetItem(userInput));
        ui->gameTableWidget->setItem(ui->gameTableWidget->rowCount() - 1, 1, new QTableWidgetItem("Быков: " + QString::number(result[0]) + "; Коров: " +  QString::number(result[1])));

        if(result[0] == 4){
            ui->statusLabel->setText(QString("Вы победили!"));

            records[player_name] = ui->gameTableWidget->rowCount();

            ui->checkButton->setDisabled(true);
            ui->userInput->setDisabled(true);

            delete game;
        }
    }
}


void MainWindow::on_recordsButton_clicked()
{
    recordsDialog recordsdialog(this);
    recordsdialog.setRecords(records);
    recordsdialog.exec();
}


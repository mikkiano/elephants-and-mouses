#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"

#include <QMainWindow>
#include <QRegularExpression>
#include <QInputDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**
     * @brief on_newGameButton_clicked обработчик нажатия на кнопку "Новая игра". Запоминает имя игрока и создаёт новый экземпляр игры.
     */
    void on_newGameButton_clicked();

    /**
     * @brief on_checkButton_clicked обработчик нажатия на кнопку "Проверить". Проверяет, что введенная строка - четерехзначное число.
     * Заполняет таблицу с игрой. При отгадывании числа завершает игру.
     */
    void on_checkButton_clicked();

    /**
     * @brief on_recordsButton_clicked обработчик нажатия на кнопку "Рекорды". При нажатии на кнопку открывает диалоговое окно с рекордами.
     */
    void on_recordsButton_clicked();

private:
    Ui::MainWindow *ui;
    /**
     * @brief game экземпляр игры
     */
    Game *game;
    /**
     * @brief player_name имя текущего игрока
     */
    QString player_name;
    /**
     * @brief records таблица рекордов, где ключ - имя игрока, значение - рекорд.
     */
    std::map<QString, int> records;
};
#endif // MAINWINDOW_H

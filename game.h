#ifndef GAME_H
#define GAME_H

#include <QDebug>
#include <QObject>

#include <algorithm>
#include <map>
#include <vector>

class Game
{
public:
    Game();

    /**
     * @brief countBullsAndCows Функция подсчитывает количество быков и коров по введенному числу от пользователя
     *
     * @param user_input введенное число пользователя типа QString
     *
     * @return возвращает вектор, где первое число - количество быков, второе - количество коров
    */
    std::vector<int> countBullsAndCows(QString user_input);
private:
    /**
     * @brief guessed_number map для хранения загаданного числа, где ключ - число, значение - его позиция
     */
    std::map<int,int> guessed_number;
};

#endif // GAME_H

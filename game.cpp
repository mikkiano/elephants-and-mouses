#include "game.h"

Game::Game(){
    std::vector<int> numbers = {1,2,3,4,5,6,7,8,9};
    std::random_shuffle(numbers.begin(), numbers.end());

    QString guessed_number_string;

    for (int i = 0; i < 4; i++){
        int temp = numbers.back();
        guessed_number[temp] = i;
        guessed_number_string.push_back(QString::number(temp));
        numbers.pop_back();
    }

    qDebug() << guessed_number_string;
}

std::vector<int> Game::countBullsAndCows(QString user_input)
{
    int bulls = 0, cows = 0;
    int temp;

    for (int i = 0; i < user_input.length(); i++) {
        temp = user_input[i].digitValue();
        if (guessed_number.count(temp) == 1){
            if (guessed_number[temp] == i){
                bulls++;
            } else {
                cows++;
            }
        }
    }

    return std::vector<int> {bulls, cows};
}

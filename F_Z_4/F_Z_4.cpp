// F_Z_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<Windows.h>
#include <iomanip>//Это инструменты для работы с форматированием вывода
/*Написать функцию, выводящую на экран переданную ей игральную карту.
*/
using namespace std;
/*printCard- карта;cardAdvantage-номер карты, преимущество;suitCard-масть
*/

void printCard(enum suit suitCard, char cardAdvantage)
{
    char hl = (char)196; //horizontal line
    char vl = (char)179; //vertical line
    //стандартный отступ
    int indent = 6;

    cout << (char)218 << hl << hl << hl << hl << hl << hl << hl << (char)191 << endl <<
        vl;
    //если 10, то уменьшаем отступ
    //и печатаем 1, а 0 выводится сам 
    if (cardAdvantage == '0')
    {
        indent = 5;
        cout << '1';
    }

    cout << cardAdvantage << (char)suitCard << "\t" << vl << endl <<
        vl << "\t" << vl << endl <<
        vl << "\t" << vl << endl <<
        vl << "\t" << vl << endl <<
        vl << "\t" << vl << endl <<
        vl << "\t" << vl << endl <<
        vl << "\t" << vl << endl <<
        vl << setw(indent) << (char)suitCard;

    if (cardAdvantage == '0')
    {
        cout << '1';
    }

    cout << cardAdvantage << vl << endl <<
        (char)192 << hl << hl << hl << hl << hl << hl << hl << (char)217 << endl;
}

enum Suit//перечисление
{
    Hearts = 3,
    Diamonds = 4,
    Clubs = 5,
    Spades = 6
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int intUserSuitCard;
    enum suit userSuitCard;
    int userCardAdvantage;
    char advantages[] = { ' ', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' };


    cout << "Enter suit card: " << endl <<
        "Hearts = 3" << endl <<      //черви
        "Diamonds = 4" << endl <<    //буби
        "Clubs = 5" << endl <<       //крести
        "Spades = 6" << endl;        //пики
    cin >> intUserSuitCard;
    userSuitCard = (enum suit)intUserSuitCard;

    if (userSuitCard != Hearts && userSuitCard != Diamonds &&
        userSuitCard != Clubs && userSuitCard != Spades)
    {
        cout << "Incorrect choice" << endl;
        return 1;
    }

    cout << "Enter card advantage: " << endl <<
        "1 - ace \t 2 - two \t 3 - three" << endl <<
        "4 - four \t 5 - five \t 6 - six" << endl <<
        "7 - seven \t 8 - eight \t 9 - nine" << endl <<
        "10 - ten \t 11 - jack \t 12 - queen" << endl <<
        "13 - king" << endl;
    cin >> userCardAdvantage;

    if (userCardAdvantage < 1 || userCardAdvantage > 13)
    {
        cout << "Incorrect choice" << endl;
        return 2;
    }

    printCard(userSuitCard, advantages[userCardAdvantage]);
    return 0;
}

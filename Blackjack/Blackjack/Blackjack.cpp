#include <iostream>
#include <ctime>
#include <iomanip>
#include "Header.h"

int putCard();
bool doCheck(int used_card[53], int card, int quantity);
int countPoints(int point_card, int points);
void defineWinner(int user_points, int dealer_card);

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    srand((unsigned)time(NULL));
    bool condition = true;
    int action_counter = 0;
    while (condition) 
    {
        bool cin_fail1 = false, cin_fail2 = false;
        int action = 0, y = 0, card = 0, quantity = 0, user_points = 0, point_card = 0, dealer_card = 0, dealer = 0, user = 0, dealer_points = 0;
        int used_cards[53]{};
        int user_cards[53]{};
        int dealer_cards[53]{};
        int deck[52][3]
        {
            //2
            {1, 2, 2}, {2, 2, 2}, {3, 2, 2}, {4, 2, 2},
            //3
            {1, 3, 3}, {2, 3, 3}, {3, 3, 3}, {4, 3, 3},
            //4
            {1, 4, 4}, {2, 4, 4}, {3, 4, 4}, {4, 4, 4},
            //5
            {1, 5, 5}, {2, 5, 5}, {3, 5, 5}, {4, 5, 5},
            //6
            {1, 6, 6}, {2, 6, 6}, {3, 6, 6}, {4, 6, 6},
            //7
            {1, 7, 7}, {2, 7, 7}, {3, 7, 7}, {4, 7, 7},
            //8
            {1, 8, 8}, {2, 8, 8}, {3, 8, 8}, {4, 8, 8},
            //9
            {1, 9, 9}, {2, 9, 9}, {3, 9, 9}, {4, 9, 9},
            //10
            {1, 10, 10}, {2, 10, 10}, {3, 10, 10}, {4, 10, 10},
            //валет
            {1, 11, 10}, {2, 11, 10}, {3, 11, 10}, {4, 11, 10},
            //дама
            {1, 12, 10}, {2, 12, 10}, {3, 12, 10}, {4, 12, 10},
            //король
            {1, 13, 10}, {2, 13, 10}, {3, 13, 10}, {4, 13, 10},
            //туз
            {1, 14, 11}, {2, 14, 11}, {3, 14, 11}, {4, 14, 11},
        };
        cout << "\t\t\t\t Рады приветсвовать вас за игровым столом Blackjack! \n";
        cout << setw(119) << setfill('-') << "" << endl;
        if (action_counter == 0)
        {
            cout << "Правила игры:\n";
            cout << " => Цель игры — собрать карты с суммой очков как можно ближе к 21, но не больше.\n";
            cout << " => Туз может быть 1 или 11, картинки (валет, дама, король) — это 10, остальные карты считаются по числу.\n";
            cout << " => Ты играешь только против дилера: если у тебя перебор (свыше 21), ты сразу проигрываешь.\n";
            cout << " => Победа — когда твоя сумма ближе к 21, чем у дилера, и при этом не выше 21.\n";
            cout << setw(119) << setfill('-') << "" << endl;
            cout << "С болеее подробными правилами можете ознакомиться на интернет-ресурсе:\nhttps://www.shambalacasino.ru/blog/pravila-igri-v-blekdjek \n";
            cout << setw(119) << setfill('-') << "" << endl;
            cout << "Нажмите Enter для начала игры";
            cin.get();
            for (int i = 0; i < 10; i++)
                cout << "\033[A\33[2K";
        }
        else
        {
            cout << "Нажмите Enter для начала игры";
            cin.get();
            cout << "\033[A\33[2K";
        }
        for (int i = 0; i < 2; i++)
        {
            do
            {
                dealer_card = putCard();
            } while (doCheck(used_cards, dealer_card, quantity) == false);
            used_cards[quantity] = dealer_card;
            dealer_cards[dealer] = dealer_card;
            quantity++;
            dealer++;
            point_card = deck[dealer_card][2];
            dealer_points = countPoints(point_card, dealer_points);
            do
            {
                card = putCard();
            } while (doCheck(used_cards, card, quantity) == false);
            used_cards[quantity] = card;
            user_cards[user] = card;
            quantity++;
            user++;
            point_card = deck[card][2];
            user_points = countPoints(point_card, user_points);
        }
        cout << "Карты диллера: \n";
        for (int i = 0; i <= dealer - 1; i++)
            if (i == 0) outputCard(deck, dealer_cards[i]);
            else cout << " *";
        cout << endl;
        cout << "Ваши карты: \n";
        for (int i = 0; i <= user - 1; i++)
            outputCard(deck, user_cards[i]);
        cout << endl;
        cout << "Ваши очки: " << user_points << endl;
        cout << setw(119) << setfill('-') << "" << endl;
        puts("Выберите действия:");
        puts("1 - взять карту");
        puts("2 - остановить набор");
        cout << setw(119) << setfill('-') << "" << endl;
        do
        {
            cin >> action;
            if (cin_fail1 == true)
            {
                for (int i = 0; i < 2; i++)
                    cout << "\033[A\33[2K";
            }
            if (cin.fail()) 
            { 
                cout << "\033[A\33[2K";
                cin_fail1 = true;
                cout << "Ошибка ввода! Попробуйте еще раз." << std::endl;
                cin.clear(); 
                cin.ignore(10000, '\n'); 
            }
            else
            {
                cin_fail1 = false;
                cout << "\033[A\33[2K";
            }
            switch (action)
            {
            case 1:
            {
                //набор карты игроком
                do
                {
                    card = putCard();
                } while (doCheck(used_cards, card, quantity) == false);
                used_cards[quantity] = card;
                user_cards[user] = card;
                quantity++;
                user++;
                if (user > 3)
                {
                    for (int i = 0; i < 3; i++)
                        cout << "\033[A\33[2K";
                }
                cout << "Ваши карты: \n";
                for (int i = 0; i <= user - 1; i++)
                    outputCard(deck, user_cards[i]);
                cout << endl;
                point_card = deck[card][2];
                user_points = countPoints(point_card, user_points);
                cout << "Ваши очки: " << user_points << endl;
                if (user_points > 21)
                {
                    y = 1;
                    cout << "Вы проиграли\n";
                }
                break;
            }
            case 2:
            {
                y = 1;
                //донабор карт диллером
                if (dealer_points < 17)
                {
                    do
                    {
                        dealer_card = putCard();
                    } while (doCheck(used_cards, dealer_card, quantity) == false);
                    used_cards[quantity] = dealer_card;
                    dealer_cards[dealer] = dealer_card;
                    quantity++;
                    dealer++;
                    point_card = deck[dealer_card][2];
                    dealer_points = countPoints(point_card, dealer_points);
                }
                if (user >= 3)
                {
                    for (int i = 0; i < 3; i++)
                        cout << "\033[A\33[2K";
                }
                cout << "Ваши карты: \n";
                for (int i = 0; i <= user - 1; i++)
                    outputCard(deck, user_cards[i]);
                cout << endl;
                cout << "Карты диллера: \n";
                for (int i = 0; i <= dealer - 1; i++)
                    outputCard(deck, dealer_cards[i]);
                cout << "\nВаши очки: " << user_points;
                cout << "\nОчки диллера: " << dealer_points << endl;
                defineWinner(user_points, dealer_points);
                break;
            }
            default:
            {
                puts("Выберите действие из списка");
                break;
            }
            }
        } while (y == 0);
        cout << setw(119) << setfill('-') << "" << endl;
        int c = 0;
        bool g = false;
        cout << "Для новой игры нажмите 1, для выхода - 2\n";
        cin >> c;
        if (c != 1 && c != 2)
        {
            while (g == false)
            {
                if (cin_fail2 == true)
                        cout << "\033[A\33[2K";
                if (cin.fail())
                {
                    cout << "\033[A\33[2K";
                    cin_fail2 = true;
                    cout << "Ошибка ввода! Попробуйте еще раз.";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else
                {
                    cin_fail2 = false;
                    cout << "\033[A\33[2K";
                }
                cout << "\nНеверная команда, попробуйте ещё раз: ";
                cin >> c;
                if (c == 1 || c == 2) g = true;
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (c)
        {
        case 1:
        {
            system("cls");
            break;
        }
        case 2:
        {
            condition = false;
            break;
        }
        }
        action_counter++;
    }
}

int putCard()
{
    int card = 0;
    card = rand() % 52;
    return card;
}

bool doCheck(int used_card[53], int card, int quantity)
{
    for (int i = 0; i < quantity; i++) 
        if (used_card[i] == card)
            return false;
    return true;
}

int countPoints(int point_card, int points)
{
    if (point_card == 11)
    {
        if (points + 11 <= 21) points += 11;
        else points += 1;
    }
    else
    {
        points += point_card;
    }
    return points;
}

void defineWinner(int user_points, int dealer_points)
{
    if (user_points == dealer_points) cout << "Ничья\n";
    if (user_points > dealer_points && user_points <= 21)
        cout << "Поздравляем, вы победили!\n";
    if (user_points < dealer_points && dealer_points <= 21)
        cout << "Вы проиграли\n";
    if (user_points <= 21 && dealer_points > 21)
        cout << "Поздравляем, вы победили!\n";
}

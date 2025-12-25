#include <iostream>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

void rules();

int main() {
    setlocale(LC_CTYPE, "Russian");
    const int H = 15;
    const int L = 20;
    int driver;
    int difficulty[H];
    int score;

    srand(time(0));

    while (true) {
        // МЕНЮ
        system("cls");
        cout << "====== ГОНКИ ======" << endl;
        cout << "Выберите пункт меню: " << endl;
        cout << "1. Играть" << endl;
        cout << "2. Правила" << endl;
        cout << "3. Выйти" << endl;
        char menu = _getch();

        if (menu == '1') {
            driver = L / 2;
            score = 0;
            for (int i = 0; i < H; i++) {
                difficulty[i] = -1;
            }

            //ТРАССА
            while (true) {
                system("cls");
                for (int i = 0; i < H; i++) {
                    cout << "|";
                    for (int j = 0; j < L; j++) {
                        if (i == H - 1 && j == driver) {
                            cout << "H";
                        }
                        else if (difficulty[i] != -1 && j >= difficulty[i] && j < difficulty[i] + 3) {
                            cout << "#"; 
                        }
                        else {
                            cout << " ";
                        }
                    }
                    cout << "|" << endl;
                }

                //УПРАВЛЕНИЕ
                if (_kbhit()) {
                    char control = _getch();
                    if ((control == 'a' || control == 'A') && driver > 0) {
                        driver--;
                    }
                    if ((control == 'd' || control == 'D') && driver < L - 1) {
                        driver++;
                    }
                }

                //ЛОГИКА
                for (int j = H - 1; j > 0; j--) {
                    difficulty[j] = difficulty[j - 1]; 
                } 
                if (rand() % 4 == 0) {
                    int pos = rand() % (L - 2); 
                    difficulty[0] = pos;
                }
                else { 
                    difficulty[0] = -1; 
                }

                if (difficulty[H - 1] != -1 && driver >= difficulty[H - 1] && driver < difficulty[H - 1] + 3) {
                    system("cls");
                    cout << "Ты врезался! Игра окончена :(" << endl;
                    cout << "Твой счёт: " << score << endl;
                    cout << "Нажмите любую клавишу, чтобы вернуться в меню..." << endl;
                    _getch();
                    break;
                }

                score++;
                Sleep(30);
            }
        }
        else if (menu == '2') {
            rules();
        }
        else if (menu == '3') {
            return 0;
        }
    }
}

//ПРАВИЛА ИГРЫ
void rules() {
    system("cls");
    cout << "=== ПРАВИЛА ИГРЫ ===" << endl;
    cout << "Вы управляете машиной (символ 'H') на трассе." << endl;
    cout << "На дороге появляются препятствия ('#')." << endl;
    cout << "Ваша цель — избегать столкновений и набирать очки." << endl << endl;

    cout << "=== УПРАВЛЕНИЕ ===" << endl;
    cout << "A или a — движение влево" << endl;
    cout << "D или d — движение вправо" << endl;
    cout << "Любая другая клавиша — игнорируется" << endl << endl;

    cout << "Нажмите любую клавишу, чтобы вернуться в меню..." << endl;
    _getch();
}

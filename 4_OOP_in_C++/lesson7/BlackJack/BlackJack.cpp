#include "Game.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "\t\tПриветствую в игре BlackJack!\n\n";
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "Сколько игроков ? (1 - 7): ";
        cin >> numPlayers;
    }
    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Введите имя" << i+1 << "игрока: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\nХотите сыграть ещё раз ? (Y/N): ";
        cin >> again;
    }
    return 0;
}

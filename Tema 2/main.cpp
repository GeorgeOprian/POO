#include <bits/stdc++.h>
#include "interfata.h"

using namespace std;

int main()
{
    system("CLS");
    Interfata menu;
    bool exit = 0;
    while (true)
    {
        system("CLS");
        menu.afiseaza_optiuni();
        menu.citeste_optiunea();
        system("CLS");
        switch (menu.get_optiune())
        {
            case 1:
                menu.citireRestaurant(cin);
                break;

            case 2:
                menu.afisareRestaurant(cout);
                break;
            
            case 3:
                menu.afisareMeniu();
                break;

            case 4:
                menu.sosescClienti();
                break;
            case 5:
                menu.interactiune();
                break;
            case 6:
                menu.afiseazaNumarClientiRestaurant();
                break;
            default:
                cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
                cout << "& Multumesc ca ai folosit aplicatia mea &\n";
                cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
                cout <<"Press enter to exit...";
                cin.get();
                exit = 1;
                break;
        }
        if (exit)
            break;
        cout << "Press enter to continue...\n";
        cin.get();
    }

    return 0;
}
#include <bits/stdc++.h>
#include "meniu.h"
//#include "meniu.cpp"
//#include "teatru.cpp"
//#include "actor.cpp"
using namespace std;

int main()
{
  system("CLS");
  Meniu menu;
  bool exit = 0;
  while (true)
  {
    menu.afiseaza_optiuni();
    menu.citeste_optiunea();
    system("CLS");
    switch (menu.get_optiune())
    {
    case 1:
      menu.afisare_teatre();
      break;

    case 2:
      menu.append_vector_teatre();
      system("CLS");
      menu.afisare_teatre();
      break;

    case 3:
      menu.modificare_info_teatru();
      break;
    case 4:
      menu.sorteaza_teatre();
      menu.afisare_teatre();
      break;
    default:
      system("CLS");
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
    system("CLS");
  }

  return 0;
}

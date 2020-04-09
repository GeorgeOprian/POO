#include <bits/stdc++.h>
// #include "produs.cpp"
// #include "mancare.cpp"
// #include "bauturi.cpp"
// #include "desert.cpp"
//  #include "meniu.cpp"
#include "interfata.h"

#include "meniu.h"
#include "client.h"
#include "comanda.h"
#include "masa.h"
#include "restaurant.h"
//#include "comanda.h"
#include "desert.h"
// #include "bauturi.h"
// #include "mancare.h"
// #include "produs.h"
using namespace std;

///const in cc pt vectori

//fa verificare cu this!=&x in supreaincarcarea pe=

//nu uita sa modici citirile 

int main()
{
    system("clear");
    Interfata menu;
    bool exit = 0;
    while (true)
    {
        system("clear");
        menu.afiseaza_optiuni();
        menu.citeste_optiunea();
        system("clear");
        switch (menu.get_optiune())
        {
            case 1:
                system("clear");
                menu.citireRestaurant(cin);
                break;

            case 2:
                system("clear");
                menu.afisareRestaurant(cout);
                break;
            
            case 3:
                system("clear");
                menu.afisareMeniu();
                //cin.get();
                break;

            case 4:
                menu.interactiune();
                break;
            case 5:
                menu.sosescClienti();
                break;
            case 6:
                menu.afiseazaNumarClientiRestaurant();
                break;
            default:
                system("clear");
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


    
//     ifstream f("input.in");
//     Meniu meniu;
//     f>>meniu;
//     cout << meniu;
//     Restaurant r;
//     cin >>r;
//     cout <<r;
    
//     Client c1;
//     Client c2;
//     Client c3;
    


    // vector<Client> clienti;

    // Client c;
    // Client c1;
    // c.setMeniu(meniu);
    // cin >> c;
    // cout << c;
    // c1.setMeniu(meniu);
    // cin >> c1;
    // cout << c1;

    // clienti.push_back(c);
    // clienti.push_back(c1);
    // cout << "pune in vector\n";
    // cout << clienti.size();
    // Masa m(meniu, clienti); 
    // cout << m;
    // cout <<meniu;

    // c.cheamaChelnerul(cin, cout);
    // c.cheamaChelnerul(cin, cout);

    // c.afiseazaComanda(cout);

    //cout << c;
    // ifstream f("input.in");
    // Meniu meniu;
    // f>>meniu;
    // Comanda c(meniu);
    // cin >> c;
    // cout << c;

    // Comanda c;
    // cin>>c;
    // cout <<c;
    // Meniu c1 = c;   
    // cout <<c1;
    // Meniu c2;
    // c2 = c1;
    // cout <<c2;

    // Meniu s1 = s;   
    // cout <<s1;
    // Meniu s2;
    // s2 = s1;
    // cout <<s2;

    //clasa comanda mosteste meniu
    //citire diferita (aici intervine dialogul cu chelnerul)

    // Meniu s;
    // cin>>s;
    // cout <<s;
    // Meniu s1 = s;   
    // cout <<s1;
    // Meniu s2;
    // s2 = s1;
    // cout <<s2;

    

    // persoana *p = new angajat;//upcast
    // p.getnume_angajat();//down cast


    // Meniu s;
    // cin>>s;
    // cout <<s;
    // Meniu s1 = s;   
    // cout <<s1;
    // Meniu s2;
    // s2 = s1;
    // cout <<s2;
    
    // Bauturi s;
    // cin>>s;
    // cout <<s;
    // Bauturi s1 = s;   
    // cout <<s1;
    // Bauturi s2;
    // s2 = s1;
    // cout <<s2;
    
    // Apa s;
    // cin>>s;
    // cout <<s;
    // Apa s1 = s;   
    // cout <<s1;
    // Apa s2;
    // s2 = s1;
    // cout <<s2;
    
    // Bere s;
    // cin>>s;
    // cout <<s;
    // Bere s1 = s;   
    // cout <<s1;
    // Bere s2;
    // s2 = s1;
    // cout <<s2;

    // VinSticla s;
    // cin>>s;
    // cout <<s;
    // VinSticla s1 = s;   
    // cout <<s1;
    // VinSticla s2;
    // s2 = s1;
    // cout <<s2;


    // Vin s;
    // cin>>s;
    // cout <<s;
    // Vin s1 = s;   
    // cout <<s1;
    // Vin s2;
    // s2 = s1;
    // cout <<s2;

    // Deserturi s;
    // cin>>s;
    // cout <<s;
    // Deserturi s1 = s;   
    // cout <<s1;
    // Deserturi s2;
    // s2 = s1;
    // cout <<s2;

    // Desert s;
    // cin>>s;
    // cout <<s;
    // Desert s1 = s;
    // cout <<s1;
    // Desert s2;
    // s2 = s1;
    // cout <<s2;
    // cout <<s2;

    // FeluriPrincipale s;
    // cin>>s;
    // cout <<s;
    // FeluriPrincipale s1 = s;
    // cout <<s1;
    // FeluriPrincipale s2;
    // s2 = s1;
    // cout <<s2;


    // Vita s;
    // cin>>s;
    // cout <<s;
    // Vita s1 = s;
    // cout <<s1;
    // Vita s2;
    // s2 = s1;
    // cout <<s2.getGradPregatire();

    // Pui s;
    // cin>>s;
    // cout <<s;
    // Pui s1 = s;
    // cout <<s1;
    // Pui s2;
    // s2 = s1;
    // cout <<s2;

    

    // int n =2;
    // vector<Supa*> s;
    // for (int i = 0; i<n; i++){
    //     Supa *s1;
    //     s1 = new Supa;
    //     cin >> *s1;
    //     cin.get();
    //     s.push_back(s1);
    // }
    // for (int i = 0; i<n; i++){
    //     cout <<*s[i];
    // }
    // vector<Supa*> s1;
    // s1 = s;
    // s.clear();
    // for (int i = 0; i<n; i++){
    //     cout <<*s1[i];
    // }
    // s1.clear();
    // cout <<s1.size();

    // Ciorba s;
    // cin>>s;
    // cout <<s;
    // Ciorba s1 = s;
    // cout <<s1;
    // Ciorba s2;
    // s2 = s1;
    // cout <<s2;

    // Supa s;
    // cin>>s;
    // cout <<s;
    // Supa s1 = s;
    // cout <<s1;
    // Supa s2;
    // s2 = s1;
    // cout <<s2;

    // Produs p("Paine", 12, 300, "g");
    // Produs p1 = p;
    // cout <<p<<p1;
    // Produs p2;
    // p1.setPret(22);
    // p2 = p1;
    // cout <<p2.getNumeProdus()<<" "<<p2.getPret()<<endl;

    return 0;
}
#include <bits/stdc++.h>
// #include "produs.cpp"
// #include "mancare.cpp"
// #include "bauturi.cpp"
// #include "desert.cpp"
//  #include "meniu.cpp"

#include "meniu.h"
#include "client.h"
#include "comanda.h"
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

    // Desert d;
    // cin >> d;
    // cout <<d;

    // Ciorba c1;
    // cin >> c1;
    // Ciorba c2;
    // cin >> c2;
    // vector<Produs*> produse;
    
    ifstream f("input.in");
    Meniu m;
    f>>m;
    cout << m;

    Client c(m);
    cin >> c;
    cout << c;
    //cout <<m;

    //c.cheamaChelnerul(cin, cout);
    //c.cheamaChelnerul(cin, cout);
    //c.afiseazaComanda(cout);

    //cout << c;

    // Comanda c(m);
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
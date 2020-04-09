#ifndef CLIENT_H
#define CLIENT_H
#include <bits/stdc++.h>

#include "meniu.h"
#include "comanda.h"

using namespace std;

class Client
{
    protected:

        Meniu meniu;
        Comanda comanda;
        int nrProduse;
        int totalConsumat;
        bool comandaPreluata;
        static int nrClientiRestaurant;

    public:
        Client();
        Client(const Meniu&);
        Client(const Meniu&, int, int);
        Client (const Client&);
        ~Client() = default;

        Client& operator=(const Client&);
        void preiaComanda(istream&);
        int cheamaChelnerul(istream&, ostream&);
        friend istream& operator>>(istream&, Client&);
        void afiseazaComanda(ostream&);
        friend ostream& operator<<(ostream&, Client&);

        void setMeniu(Meniu);
        int getTotalConsumat();
        void afisaremeniucomanda(){cout << comanda.meniu;};

        static void numarClienitIntratiInRestaurant(){
            cout << "Numarul de clienti care au intrat in restaurant este: " << nrClientiRestaurant << endl;
        }

        
};

#endif
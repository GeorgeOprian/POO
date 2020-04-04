#ifndef CLIENT_H
#define CLIENT_H
#include <bits/stdc++.h>

#include "meniu.h"

using namespace std;

class Client
{
    protected:

        vector<Produs*> comanda;
        int nrProduse;
        Meniu meniu;
        int totalCosumat;
        bool comandaPreluata;

    public:
        Client();
        // Client(Meniu, int, int);
        Client(Meniu);
        Client(Meniu, int, int);
        Client (const Client&);
        ~Client() = default;

        Client& operator=(const Client&);
        friend istream& operator>>(istream&, Client&);
        friend ostream& operator<<(ostream&, Client&);

        void cheamaChelnerul(istream&);
        void preiaComanda(istream&);
        void afiseazaComanda(ostream&);

        void calculeazaNota();

        int getTotalConsumat();
};

#endif
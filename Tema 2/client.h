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
        int totalCosumat;
        bool comandaPreluata;

    public:
        Client(){};
        // Client(Meniu, int, int);
        Client(Meniu);
        Client(Meniu, int, int);
        Client (const Client&);
        ~Client() = default;

        Client& operator=(const Client&);
        friend istream& operator>>(istream&, Client&);
        friend ostream& operator<<(ostream&, Client&);

        int cheamaChelnerul(istream&, ostream&);
        void preiaComanda(istream&);
        void afiseazaComanda(ostream&);
        int getTotalConsumat();

        
};

#endif
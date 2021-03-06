#ifndef MASA_H
#define MASA_H
#include <bits/stdc++.h>

#include "client.h"
#include "meniu.h"

class Masa
{
    protected:
        Meniu meniu;
        vector<Client> clienti;
        unsigned int nrClienti;
        unsigned int nrLocuri;
        int totalMasa;
        bool comandaPreluata;
    public:
        Masa();
        Masa(const Meniu&, unsigned int);
        Masa(const Meniu&, unsigned int, vector<Client>);
        Masa(const Masa&);
        ~Masa() = default;
        Masa& operator=(const Masa&);

        void preiaComanda(istream&);
        void afiseazaNota(ostream&);

        friend istream& operator>>(istream&, Masa&);
        friend ostream& operator<<(ostream&, Masa&);
        
        void setNrLocuri(int);
        void setClienti(vector <Client>);
        vector<Client> getclienti();
        void setMeniu(const Meniu&);

        int getNrLocuri();
        int getNrClienti();

        void cheamaChelnerul(istream&, ostream&);
};



#endif
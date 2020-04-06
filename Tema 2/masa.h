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
        int nrClienti;
        int nrLocuri;
        int totalMasa;
    public:
        Masa();
        Masa(Meniu, vector<Client>, int);
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
        int getNrLocuri();

        void cheamaChelnerul(istream&, ostream&);
};



#endif
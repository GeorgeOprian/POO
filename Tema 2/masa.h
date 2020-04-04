#ifndef MASA_H
#define MASA_H
#include <bits/stdc++.h>

#include "client.h"
#include "meniu.h"

class Masa
{
    protected:
        vector<Client*> clienti;
        int nrClienti;
        int nrLocuri;
    public:
        Masa(/* args */);
        ~Masa();

        void calculeazaNota();
        
};

Masa::Masa(/* args */)
{
}

Masa::~Masa()
{
}


#endif
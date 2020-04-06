#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "meniu.h"
#include "masa.h"

class Restaurant
{
    private:
        Meniu meniu;
        int nrMese;
        vector <Masa> mese;
        vector<Client> clienti;
        int nrClienti;

    public:
        Restaurant();
        Restaurant(int, Meniu, vector<Client>, int);
        Restaurant(const Restaurant&);
        ~Restaurant() = default;

        Restaurant& operator=(const Restaurant&);

        void citire(ifstream&, Restaurant&);
        void afisare(ostream&);

        friend ifstream& operator>>(ifstream&, Restaurant&);
        friend ostream& operator<<(ostream&, Restaurant&);

};




#endif
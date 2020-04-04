#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "meniu.h"
#include "masa.h"

class Restaurant
{
    private:
        Meniu meniu;
        int nrMese;
        vector <Masa*> mese;
        vector<Client*> clienti;
    public:
        Restaurant();
        Restaurant(int);
        Restaurant(const Restaurant&);
        ~Restaurant() = default;

        Restaurant& operator=(const Restaurant&);

};




#endif
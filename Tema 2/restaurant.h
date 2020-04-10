#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "meniu.h"
#include "masa.h"
#include "client.h"

class Restaurant
{
    private:
        Meniu meniu;
        int nrMese;
        vector <Masa> mese;
        int nrClienti;

    public:
        Restaurant();
        Restaurant(int, Meniu, int);
        Restaurant(const Restaurant&);
        ~Restaurant() = default;

        Restaurant& operator=(const Restaurant&);

        void citire(istream&);
        void afisare(ostream&);

        friend istream& operator>>(istream&, Restaurant&);
        friend ostream& operator<<(ostream&, Restaurant&);

        void afisareMeniu();
        void setMeniu(const Meniu&);
        Meniu getMeniu();
        bool cautaMasa(int);
        void aseazaLaMasa(int, int);
        void citesteMasa(int);

        int getNrMese();
        int getNrClientiMasa(int);
        int getNrClienti();
        void setNrClienti(int);
        void interactiune(int);

};




#endif
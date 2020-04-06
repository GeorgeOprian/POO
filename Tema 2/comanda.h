#ifndef COMANDA_H
#define COMANDA_H
#include "meniu.h"

class Comanda
{
    protected:
        Meniu meniu;
        vector <Produs*> listaProduse;
        int nrProduse;
        int total;
        friend class Client;
    public:
        Comanda();
        Comanda(Meniu);
        Comanda(Meniu, int, int);
        Comanda(const Comanda&);
        virtual ~Comanda() = default;

        Comanda& operator=(const Comanda&);
        
        void citire(istream&);
        void afisare(ostream&);

        friend istream& operator>>(istream&, Comanda&);
        friend ostream& operator<<(ostream&, Comanda&);

        void calculeazaNota();
        int getTotal();
        void setTotal();

};


#endif
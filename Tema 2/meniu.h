#ifndef MENIU_H
#define MENIU_H
// #include "mancare.cpp"
// #include "desert.cpp"
// #include "bauturi.cpp"
#include "desert.h"
#include "bauturi.h"
#include "mancare.h"
#include "produs.h"

class Meniu
{
    protected:
        vector <Produs*> supe;
        vector <Produs*> ciorbe;
        vector <Produs*> produsePui;
        vector <Produs*> produseVita;
        vector <Produs*> garnituri;
        vector <Produs*> deserturi;
        vector <Produs*> vinPahar;
        vector <Produs*> vinSticla;
        vector <Produs*> bere;
        vector <Produs*> apa;
        
        int nrSupe;
        int nrCiorbe;
        int nrPui;
        int nrVita;
        int nrGarnituri;
        int nrDeserturi;
        int nrVinPahar;
        int nrVinSticla;
        int nrBere;
        int nrApa;
        friend class Comanda;
    public:
        Meniu();
        Meniu(int, int, int, int, int, int, int, int, int, int);
        Meniu(const Meniu&);
        ~Meniu();
        Meniu& operator=(const Meniu&);

        virtual void citire(ifstream&);
        virtual void afisare(ostream&);

        friend ifstream& operator>>(ifstream&, Meniu&);
        friend ostream& operator<<(ostream&, Meniu&);
};



#endif
#ifndef MENIU_H
#define MENIU_H
// #include "mancare.cpp"
// #include "desert.cpp"
// #include "bauturi.cpp"
#include "mancare.h"
#include "desert.h"
#include "bauturi.h"

class Meniu
{
    protected:
        Ciorbe ciorbe;
        FeluriPrincipale feluriPrincipale;
        Deserturi deserturi;
        Bauturi bauturi;
    public:
        Meniu(){

        };
        //Meniu(Ciorbe, FeluriPrincipale, Deserturi, Bauturi);
        Meniu(const Meniu&);
        ~Meniu(){};
        Meniu& operator=(const Meniu&);

        void citire(istream&);
        void afisare(ostream&);

        friend istream& operator>>(istream&, Meniu&);
        friend ostream& operator<<(ostream&, Meniu&);
};



#endif
#ifndef TEATRUDB_TEATRU_H
#define TEATRUDB_TEATRU_H
#include "actor.h"
using namespace std;
class Teatru {
    private:
        char * nume_teatru;
        char* denumire_piesa;
        int numar_actori;
        Actor* actori;
        double rating;
        friend class Meniu;
    
    public:
        Teatru();
        Teatru(char *, char *, int, Actor*, double);
        Teatru(Teatru& t);
        ~Teatru();

        //set
        void setNume_teatru(char *);
        void setDenumire_piesa(char*);
        void setNumar_actori(int);
        void setActori(Actor*);
        void adauga_actor(Actor);
        void setRating(double);

        //get
        char* getNume_teatru();
        char* getDenumire_piesa();
        int getNumar_actori();
        double getRating();
        //citire
        void citire_teatru(istream &t);
        //afisare
        ostream& afisareTeatru(ostream &out);
        void afiseazaActori(ostream &out);
        //supraincarcare operatori
        friend istream& operator>>(istream &in, Teatru &t);
        friend ostream& operator<<(ostream &out, Teatru &t);
        Teatru& operator=(Teatru &sursa);
        friend bool operator>(const Teatru &stanga, const Teatru &dreapta);
        friend bool operator<(const Teatru &stanga, const Teatru &dreapta);
        
};
#endif
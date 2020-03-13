#ifndef MENIU_H
#define MENIU_H
#include "teatru.h"
class Meniu{
    private:
    int optiune;
    int numar_teatre;
    Teatru *vector_teatre;
    public:
    Meniu(); // in constructor citesc teatrele
    ~Meniu();
    void set_numar_teatre(int);
    int get_numar_teatre();
    int get_optiune();

    //actiuni
    void afiseaza_optiuni();
    void citeste_optiunea();
    void afisare_teatre();
    void append_vector_teatre();
    void modificare_info_teatru();
    void modifica_actori(int);
    void modifica_echipa_actori(int);
    void adauga_actor(int);
    void sterge_actor(int);
    void sorteaza_teatre();
};

#endif
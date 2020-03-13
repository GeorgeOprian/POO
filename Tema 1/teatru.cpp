#include <iostream>
#include <cstring>
#include "teatru.h"

using namespace std;

Teatru :: Teatru(){
    nume_teatru = new char[strlen("Lipsa denumire nume teatru") + 1];
    strcpy (nume_teatru, "Lipsa denumire nume teatru");
    denumire_piesa = new char[strlen("Lipsa denumire denumire_piesa") + 1];
    strcpy (denumire_piesa, "Lipsa denumire denumire_piesa");
    numar_actori = 0;
    actori = nullptr;
    rating = 0;
}
Teatru :: Teatru(char * nume_teatru, char* denumire_piesa, int numar_actori, Actor* actori, double rating){
    this -> nume_teatru = new char[strlen(nume_teatru) + 1];
    strcpy(this -> nume_teatru, nume_teatru);

    this -> denumire_piesa = new char[strlen(denumire_piesa) + 1];
    strcpy(this -> denumire_piesa, denumire_piesa);
    
    this -> numar_actori = numar_actori;
    
    this -> actori = new Actor[numar_actori];
    for(int i = 0; i < numar_actori; i++)
        this->actori[i]  = actori[i];
    this -> rating = rating;

}
Teatru::Teatru(Teatru& t){
    this -> nume_teatru = new char[strlen(t.nume_teatru) + 1];
    strcpy(this -> nume_teatru, t.nume_teatru);

    this -> denumire_piesa = new char[strlen(t.denumire_piesa) + 1];
    strcpy(this -> denumire_piesa, t.denumire_piesa);
    
    this -> numar_actori = t.numar_actori;
    
    this -> actori = new Actor[t.numar_actori];
    for(int i = 0; i < t.numar_actori; i++)
        this->actori[i]  = t.actori[i];
    this -> rating = t.rating;
}

Teatru :: ~Teatru(){
    delete[] nume_teatru;
    delete[] denumire_piesa;
    numar_actori = 0;
    delete[] actori;
    rating = 0;
}

void Teatru::setNume_teatru(char * nume_teatru){
    delete[] this -> nume_teatru;
    this -> nume_teatru = new char[strlen(nume_teatru) + 1];
    strcpy(this -> nume_teatru, nume_teatru);
}
void Teatru::setDenumire_piesa(char* denumire_piesa){
    delete[] this -> denumire_piesa;
    this->denumire_piesa = new char[strlen(denumire_piesa) + 1];
    strcpy(this->denumire_piesa, denumire_piesa);
}
void Teatru::setNumar_actori(int numar_actori){
    this -> numar_actori = numar_actori;
}
void Teatru::setActori(Actor * actori){
    delete[] this -> actori;
    this -> actori = new Actor [this -> numar_actori];
    this -> actori = actori;
}
void Teatru::setRating(double rating){
    if (rating >=1 && rating <= 5)
        this -> rating = rating;
    else{
        if (rating > 5)
            this -> rating = 5;
        if(rating < 1)
            this -> rating = 1;
    }
}

char * Teatru::getNume_teatru(){
    return nume_teatru;
}

char * Teatru::getDenumire_piesa(){
    return denumire_piesa;
}
int Teatru::getNumar_actori(){
    return numar_actori;
}
double Teatru::getRating(){
    return rating;
}

void Teatru::citire_teatru(istream &in){
    cout<<"\nNume teatru: ";
    char nume[256];
    in.get(nume, 256);
    delete[] nume_teatru;
    nume_teatru = new char[strlen(nume) + 1];
    strcpy(nume_teatru, nume);

    cout <<"Denumirea piesei: ";
    in.get();
    in.get(nume, 256);
     delete[] denumire_piesa;
    denumire_piesa = new char[strlen(nume) + 1];
    strcpy(denumire_piesa, nume);

    cout <<"Numar actori = ";
    in >>numar_actori;
    delete[] actori;
    actori = new Actor[numar_actori];
    for(int i =0; i < numar_actori; i++){
        in.get();
        in>>actori[i];
    }
    double r;
    cout <<"Rating = ";
    in >> r;
    this -> setRating(r);
    in.get();
}

istream& operator >> (istream& in, Teatru& a){
    a.citire_teatru(in);
    return in;
}

void Teatru::afiseazaActori(ostream &out){
    out <<"Actorii care joaca la teatrul " << nume_teatru <<" in piesa " << denumire_piesa << " sunt:\n";
    for (int i = 0; i < numar_actori; i++){
        out <<"\tNume: "<<actori[i].getNume_actor()<<"\n\tVarsta:"<<actori[i].getVarsta()<<endl;
    }
}

ostream& Teatru::afisareTeatru(ostream &out){
    out <<"\n##############################################";
    out << "\nNume teatru: " << nume_teatru<<endl;
    out << "Denumire piesa: " << denumire_piesa<<endl;
    out << "Numar actori: " << numar_actori<<endl;
    afiseazaActori(out);
    out << "Ratingul piesei este:  " << rating <<endl;
    out <<"\n##############################################";
    out <<endl;
    return out;
}

ostream& operator<<(ostream &out, Teatru &t){
    t.afisareTeatru(out);
    return out;
}
bool operator>(Teatru &stanga, Teatru &dreapta){
    return (stanga.getRating() > dreapta.getRating());
}
bool operator<(Teatru &stanga, Teatru &dreapta){
    return (stanga.getRating() < dreapta.getRating());
}

Teatru& Teatru::operator=(Teatru &sursa){
    if (this != &sursa){
        delete[] nume_teatru;
        nume_teatru = new char [strlen(sursa.nume_teatru) + 1];
        strcpy(nume_teatru, sursa.nume_teatru);
        delete[] denumire_piesa;
        denumire_piesa = new char [strlen(sursa.denumire_piesa) + 1];
        strcpy(denumire_piesa, sursa.denumire_piesa);
        numar_actori = sursa.numar_actori;
        delete[] actori;
        actori = new Actor[numar_actori];
        for(int i = 0; i < numar_actori; i++){
            actori[i] = sursa.actori[i];
        }
        rating = sursa.rating;
    }
    return *this;
}

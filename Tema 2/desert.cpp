#include "desert.h"
using namespace std;

//implemantare clasa Desert
Desert::Desert(string numeProdus ="", int pret = 0, int cantintate = 0, string unitateMasura = "", int nrMinUM = 0, int nrMAxUM = 0)
        :Produs(numeProdus, pret, cantintate, unitateMasura){
    this->nrMAxUM = nrMAxUM;
    this->nrMinUM = nrMinUM;
}
Desert::Desert(const Desert& d):Produs(d){
    this->nrMAxUM = d.nrMAxUM;
    this->nrMinUM = d.nrMinUM;
}
Desert& Desert::operator=(const Desert& d){
    if (this != &d){
        Produs::operator=(d);
        this->nrMAxUM = d.nrMAxUM;
        this->nrMinUM = d.nrMinUM;
    }
    return *this;
}
void Desert::citire(istream& in){
    citireNume(in);
    citirePret(in);
    citireUnitateMasura(in);
    cout << "Introduceti restrictii pentru unitate de masura? (0/1) ";
    bool optiune;
    in >> optiune;
    if(optiune){
        cout << "Introduceti numarul minim de " << unitateMasura << ": ";
        in >> nrMinUM; 
        cout << "Introduceti numarul maxim de " << unitateMasura << ": ";
        in >> nrMAxUM; 
    }
}
istream& operator>>(istream& in, Desert& d){
    d.citire(in);
    return in;
}
void Desert::afisare(ostream& out){
    out<< numeProdus << ":\n";
    out << "Pret: " << pret << " lei pe o " << unitateMasura;
}
ostream& operator<<(ostream& out, Desert& d){
    d.afisare(out);
    return out;
}
//implementare clasa Deserturi
Deserturi::Deserturi(vector<Desert> deserturi = {}, int nrDeserturi = 0){
    this->deserturi = deserturi;
    this->nrDeserturi = nrDeserturi;
}

Deserturi::Deserturi(const Deserturi& d){
    this->deserturi = d.deserturi;
    this->nrDeserturi = d.nrDeserturi;
}
Deserturi& Deserturi::operator=(const Deserturi& d){
    if (this != &d){
        this->deserturi = d.deserturi;
        this->nrDeserturi = d.nrDeserturi;
    }
    return *this;
}
void Deserturi::citire(istream& in){
    cout << "Introduceti numarul de Deserturi: ";
    in >> nrDeserturi;
    if (nrDeserturi){
        Desert d;
        for (int i = 0; i < nrDeserturi; i++){
            in.get();
            in >> d;
            deserturi.push_back(d);
        }
    }
}
istream& operator>>(istream& in, Deserturi& d){
    d.citire(in);
    return in;
}
void Deserturi::afisare(ostream& out){
    if (nrDeserturi){
        cout <<"Deserturi:\n";
        for (int i = 0; i < nrDeserturi; i++){
            out << deserturi[i]<<endl;
        }
        out <<endl;
    }
}
ostream& operator<<(ostream& out, Deserturi&d){
    d.afisare(out);
    return out;
}
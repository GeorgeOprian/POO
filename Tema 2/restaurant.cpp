#include "restaurant.h"

using namespace std;

Restaurant::Restaurant()
{
    this->nrMese = 0;
}

Restaurant::Restaurant(int nrMese, Meniu meniu, vector<Client> clienti, int nrClienti)
{
    this->nrMese = nrMese;
    this->meniu = meniu;
    this->clienti = clienti;
    this->nrClienti = nrClienti;
}

Restaurant::Restaurant(const Restaurant& r)
{
    this->nrMese = r.nrMese;
    this->meniu = r.meniu;
    this->clienti = r.clienti;
    this->nrClienti = r.nrClienti;
}
Restaurant& Restaurant::operator=(const Restaurant& r){
    if (this != &r){
        this->nrMese = r.nrMese;
        this->meniu = r.meniu;
        this->clienti = r.clienti;
        this->nrClienti = r.nrClienti;
    }
    return *this;
}

void Restaurant::citire(istream& in){
    cout << "Introduceti numarul de mese: ";
    in >> nrMese;
    int n;
    for (int i = 0; i < nrMese; i++){
        cout << "Introduceti numarul de locuri ale masei " << i + 1 << ": ";
        int n;
        in >> n;
        Masa m(meniu, n);
        mese.push_back(m);
    }
}
istream& operator>>(istream& in, Restaurant& r){
    r.citire(in);
    return in;
}
void Restaurant::afisare(ostream& out){
    cout << nrMese;
}

ostream& operator<<(ostream& out, Restaurant& r){
    r.afisare(out);
    return out;
}
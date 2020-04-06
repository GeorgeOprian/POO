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



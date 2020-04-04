#include "restaurant.h"

using namespace std;

Restaurant::Restaurant()
{
    this->nrMese = 0;
}

Restaurant::Restaurant(int nrMese)
{
    this->nrMese = nrMese;
}

Restaurant::Restaurant(const Restaurant& r)
{
    this->meniu = r.meniu;
    this->nrMese = nrMese;
}
Restaurant& Restaurant::operator=(const Restaurant& r){
    if (this != &r){
        this->meniu = r.meniu;
        this->nrMese = r.nrMese;
    }
    return *this;
}


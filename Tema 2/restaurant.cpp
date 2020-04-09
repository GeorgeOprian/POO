#include "restaurant.h"

using namespace std;

Restaurant::Restaurant()
{
    this->nrMese = 0;
    this->nrClienti = 0;
}

Restaurant::Restaurant(int nrMese, Meniu meniu, int nrClienti)
{
    this->nrMese = nrMese;
    this->meniu = meniu;
    this->nrClienti = nrClienti;
}

Restaurant::Restaurant(const Restaurant& r)
{
    this->nrMese = r.nrMese;
    this->meniu = r.meniu;
    this->nrClienti = r.nrClienti;
}
Restaurant& Restaurant::operator=(const Restaurant& r){
    if (this != &r){
        this->nrMese = r.nrMese;
        this->meniu = r.meniu;
        this->nrClienti = r.nrClienti;
    }
    return *this;
}

void Restaurant::citire(istream& in){
    cout << "Introduceti numarul de mese: ";
    in >> nrMese;
    cout << "Introduceti mesele in ordinea numarului de locuri.\n";
    for (int i = 0; i < nrMese; i++){
        cout << "Introduceti numarul de locuri ale mesei " << i + 1 << ": ";
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
    cout << "Restaurantul are " << nrMese << " mese.\n";
    for (int i = 0; i < nrMese; i++){
        cout << "Masa " << i + 1 << " are " << mese[i].getNrLocuri() << " locuri si ";
        cout << mese[i].getNrClienti() << " clienti.\n";
    }
}

ostream& operator<<(ostream& out, Restaurant& r){
    r.afisare(out);
    return out;
}
void Restaurant::afisareMeniu(){
    cout << meniu;
}
void Restaurant::setMeniu(Meniu m){
    this->meniu = m;
}
void Restaurant::aseazaLaMasa(int nrMasa, int nrClienti){
    vector <Client> grup(nrClienti);
    cout << "dimensiunea grupui: " << grup.size()<<endl;
    mese[nrMasa].setMeniu(meniu);
    mese[nrMasa].setClienti(grup);
}
bool Restaurant::cautaMasa(int nrClientiAjunsi){
    //cout << "Au ajuns " << nrClientiAjunsi<<endl;
    for (int i = 0; i < nrMese; i++){
        //cout << mese[i].getNrLocuri() << endl;
        if (nrClientiAjunsi <= mese[i].getNrLocuri() && mese[i].getNrClienti() == 0){
            aseazaLaMasa(i, nrClientiAjunsi);
            return 1;
        }
    }
    return 0;
}
int Restaurant::getNrMese(){
    return nrMese;
}
int Restaurant::getNrClientiMasa(int nrMasa){
    return mese[nrMasa].getNrClienti();
}
void Restaurant::citesteMasa(int nrMasa){
    cout << "Masa " << nrMasa + 1 << ":\n";
    cin >> mese[nrMasa];
}
int Client::nrClientiRestaurant;
int Restaurant::getNrClienti(){
    return nrClienti;
}
void Restaurant::setNrClienti(int n){
    this->nrClienti = n;
}
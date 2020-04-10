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
void Restaurant::setMeniu(const Meniu & m){
    this->meniu = m;
}
void Restaurant::aseazaLaMasa(int nrMasa, int nrClienti){
    vector <Client> grup(nrClienti);
    mese[nrMasa].setMeniu(meniu);
    mese[nrMasa].setClienti(grup);
}
bool Restaurant::cautaMasa(int nrClientiAjunsi){
    for (int i = 0; i < nrMese; i++){
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
    cout << "\nMasa " << nrMasa + 1 << ":\n";
    cin >> mese[nrMasa];
}
void Restaurant::interactiune(int nrMasa){
    cout << "1. Preia comanda;\n";
    cout << "2. Un client cheama chelenerul;\n";
    cout << "Orice valoare >= 3 iesire;\n";
    cout << "Introduceti o valoare: ";
    int optiune;
    cin >> optiune;
    switch (optiune)
    {
        case 1:
            system("CLS");
            citesteMasa(nrMasa);
            break;
        case 2:
            cout << "La masa sunt " << mese[nrMasa].getNrClienti() << " clienti.\n";
            mese[nrMasa].cheamaChelnerul(cin, cout);
            break;
        default:
            break;
    }
}
int Client::nrClientiRestaurant;
int Restaurant::getNrClienti(){
    return nrClienti;
}
void Restaurant::setNrClienti(int n){
    this->nrClienti = n;
}
Meniu Restaurant::getMeniu(){
    return meniu;
}
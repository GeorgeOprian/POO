#include "meniu.h"

using namespace std;

// Meniu::Meniu(Ciorbe ciorbe, FeluriPrincipale feluriPrincipale, Deserturi deserturi, Bauturi bauturi){
//     this->ciorbe = ciorbe;
//     this->feluriPrincipale = feluriPrincipale;
//     this->deserturi = deserturi;
//     this->bauturi = bauturi;
// }

Meniu::Meniu(const Meniu& m){
    this->ciorbe = m.ciorbe;
    this->feluriPrincipale = m.feluriPrincipale;
    this->deserturi = m.deserturi;
    this->bauturi = m.bauturi;
}
Meniu& Meniu::operator=(const Meniu& m){
    if (this!=&m){
        this->ciorbe = m.ciorbe;
        this->feluriPrincipale = m.feluriPrincipale;
        this->deserturi = m.deserturi;
        this->bauturi = m.bauturi;
    }
    return *this;
}
void Meniu::citire(istream& in){
    cout << "Introduceti ciorbele:\n";
    in >> ciorbe;
    cout << "Introduceti felurile principale:\n";
    in >> feluriPrincipale;
    cout << "Introduceti deserturile:\n";
    in>>deserturi;
    cout << "Introduceti bauturile:\n";
    in >> bauturi;
}
istream& operator>>(istream& in, Meniu& m){
    m.citire(in);
    return in;
}
void Meniu::afisare(ostream& out){
    out << ciorbe;
    out << feluriPrincipale;
    out << deserturi;
    out << bauturi;
}
ostream& operator<<(ostream& out, Meniu& m){
    m.afisare(out);
    return out;
}
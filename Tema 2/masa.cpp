#include "masa.h"

using namespace std;

Masa::Masa(){
    nrClienti = 0;
    nrLocuri = 0;
    totalMasa = 0;
}
Masa::Masa(Meniu meniu, vector<Client> clienti, int nrclienti){
    this->meniu = meniu;
    this->clienti = clienti;
    this->nrClienti = nrClienti;
    totalMasa = 0; 
}
Masa::Masa(const Masa& m){
    this->meniu = m.meniu;
    this->clienti = m.clienti;
    this->nrClienti = m.nrClienti;
    this->nrLocuri = m.nrLocuri;
    this->totalMasa = m.totalMasa;
}
Masa& Masa::operator=(const Masa& m){
    if (this != &m){
        this->meniu = m.meniu;
        this->clienti = m.clienti;
        this->nrClienti = m.nrClienti;
        this->nrLocuri = m.nrLocuri;
        this->totalMasa = m.totalMasa;
    }
    return *this;
}
void Masa::setClienti(vector<Client> c){
    this->clienti = c;
    this->nrClienti = c.size();
}
void Masa::setNrLocuri(int nrLocuri){
    this->nrClienti = nrLocuri;
}
vector<Client> Masa::getclienti(){
    return clienti;
}
int Masa::getNrLocuri(){
    return nrLocuri;
}

void Masa::preiaComanda(istream& in){
    for (int i = 0; i < nrClienti; i++){
        cout << "Clientul " << i + 1 << ":\n";
        in >>clienti[i];
        cout <<endl;
    }
}
istream& operator>>(istream& in, Masa& m){
    m.preiaComanda(in);
    return in;
}
void Masa::cheamaChelnerul(istream& in, ostream& out){
    cout << "Introduceti numarul clientului care cheama chelnerul: ";
    int nrClient;
    in >> nrClient;
    nrClient--;
    in.get();
    bool preferinta = clienti[nrClient].cheamaChelnerul(in, out);
    if(preferinta){
        if (preferinta == 1){
            clienti.erase(clienti.begin() + nrClient);
        }else{
            afiseazaNota(out);
        }
    }
}
void Masa::afiseazaNota(ostream& out){
    for (int i = 0; i < nrClienti; i++){
        clienti[i].afiseazaComanda(out);
        totalMasa +=clienti[i].getTotalConsumat();
    }
    cout << "Total: " << totalMasa << " lei.\n";
}
ostream& operator<<(ostream& out, Masa& m){
    m.afiseazaNota(out);
    return out;
}
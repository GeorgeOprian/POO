#include "masa.h"

using namespace std;

Masa::Masa(){
    nrClienti = 0;
    nrLocuri = 0;
    totalMasa = 0;
}
Masa::Masa(const Meniu&, int nrLocuri){
    this->meniu = meniu;
    this->nrLocuri = nrLocuri;
}
Masa::Masa(const Meniu& meniu, vector<Client> clienti){
    this->meniu = meniu;
    this->totalMasa = 0; 
    nrLocuri = 0;
    if (clienti.size() < nrLocuri){
        this->nrClienti = clienti.size();
        this->clienti = clienti;
    }else{
        cout << "Masa nu are suficiente locuri\n";
    }
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



void Masa::preiaComanda(istream& in){
    for (unsigned int i = 0; i < nrClienti; i++){
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
    totalMasa = 0;
    cout << "\n---------------------------------\n";
    for (unsigned int i = 0; i < nrClienti; i++){
        clienti[i].afiseazaComanda(out);
        totalMasa +=clienti[i].getTotalConsumat();
    }
    cout << "\n---------------------------------\n";
    cout << "Total: " << totalMasa << " lei.\n";
}
ostream& operator<<(ostream& out, Masa& m){
    m.afiseazaNota(out);
    return out;
}
void Masa::setMeniu(Meniu meniu){
    this->meniu = meniu;
}
void Masa::setClienti(vector<Client> clienti){
    if (clienti.size() < nrLocuri){
        this->nrClienti = clienti.size();
        this->clienti = clienti;
        this->nrClienti = clienti.size();
        for(unsigned int i = 0; i < nrClienti; i++){
            this->clienti.push_back(clienti[i]);
            this->clienti[i].setMeniu(meniu);
        }
    }else{
        cout << "Masa nu are suficiente locuri\n";
    }
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
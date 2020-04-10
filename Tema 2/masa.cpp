#include "masa.h"

using namespace std;

Masa::Masa(){
    nrClienti = 0;
    nrLocuri = 0;
    totalMasa = 0;
    comandaPreluata = 0;
}
Masa::Masa(const Meniu&, unsigned int nrLocuri){
    this->meniu = meniu;
    this->nrLocuri = nrLocuri;
    nrClienti = 0;
    comandaPreluata = 0;
}
Masa::Masa(const Meniu& meniu, unsigned int nrLocuri, vector<Client> clienti){
    this->meniu = meniu;
    this->totalMasa = 0; 
    this->nrLocuri = nrLocuri;
    this->nrClienti = 0;
    if (clienti.size() < nrLocuri){
        this->nrClienti = clienti.size();
        for(unsigned int i = 0; i < nrClienti; i++){
            this->clienti.push_back(clienti[i]);
            this->clienti[i].setMeniu(meniu);
        }
    }else{
        cout << "Masa nu are suficiente locuri\n";
    }
    comandaPreluata = 0;
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
    if (comandaPreluata) cout << "Comanda a fost deja preluata\n";
    else{
        cout << "Preia comanda la masa:\n";
        //cout << meniu;
        // for (int i =0; i <  nrClienti; i++){
        //     cout << "cleintul " << i<<endl;
        //     cout << clienti[i];
        // }
        in.get();
        for (unsigned int i = 0; i < nrClienti; i++){
            cout << "Clientul " << i + 1 << ":\n";
            in >> clienti[i];
            //cout <<endl;
        }
        comandaPreluata = 1;
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
    in.get();
    nrClient--;
    bool preferinta = clienti[nrClient].cheamaChelnerul(in, out);
    if (preferinta == 1){ // a vrut nota seaparat
        clienti.erase(clienti.begin() + nrClient);
        nrClienti--;
    }else{ //nota colectiva
        cout << "\nNota la masa este: \n";
        afiseazaNota(out);

        cout << "a sters clientii\n";
        nrClienti = 0;
        comandaPreluata = 0;
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
void Masa::setMeniu(const Meniu& meniu){
    this->meniu = meniu;
}
void Masa::setClienti(vector<Client> clienti){
    if (clienti.size() <= nrLocuri){
        this->nrClienti = clienti.size();
        for(unsigned int i = 0; i < this->nrClienti; i++){
            this->clienti.push_back(Client (clienti[i]));//apelez cc 
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
int Masa::getNrClienti(){
    return nrClienti;
}




#include "client.h"


using namespace std;

Client::Client(const Meniu& meniu):comanda(meniu){
    this->meniu = meniu;
    this->nrProduse = 0;
    this->totalConsumat = 0;
    this->comandaPreluata = 0;
}
Client::Client(const Meniu& meniu, int nrProduse, int totalConsumat):comanda(meniu){
    this->meniu = meniu;
    this->nrProduse = nrProduse;
    this->totalConsumat = totalConsumat;
    this->comandaPreluata = 0;
}
Client::Client(const Client& c){
    this->comanda = c.comanda;
    this->nrProduse = c.nrProduse;
    this->meniu = c.meniu;
    this->totalConsumat = c.totalConsumat;
    this->comandaPreluata = c.comandaPreluata;
}
Client& Client::operator=(const Client& c){
    if (this!=&c){
        this->comanda = c.comanda;
        this->nrProduse = c.nrProduse;
        this->meniu = c.meniu;
        this->totalConsumat = c.totalConsumat;
        this->comandaPreluata = c.comandaPreluata;
    }
    return *this;
}

void Client::preiaComanda(istream& in){
    in >> comanda;
}

int Client::cheamaChelnerul(istream& in, ostream& out){
    cout << "Doriti sa mai comandati ceva sau dortiti nota? (1/0) ";
    string optiune;
    getline(in, optiune);
    if(optiune == "1"){
        preiaComanda(in);
    }else{
        cout << "Individual sau la toata masa? (1/0)\n";
        bool individual;
        in >> individual;
        in.get();
        if(individual){
            afiseazaComanda(out);
            int total = comanda.getTotal();
            totalConsumat = total;
            out << "\nTotal: " << totalConsumat << " lei\n";
            return -1; //vrea nota individual
        }else{
            
            return 1; //vrea nota la masa
        }
    }
    return 0;
}
istream& operator>>(istream& in, Client& c){
    c.preiaComanda(in);
    c.comandaPreluata = 1;
    return in;
}
void Client::afiseazaComanda(ostream& out){
    out << comanda;
    comanda.calculeazaNota();
    totalConsumat = comanda.getTotal();
}
ostream& operator<<(ostream& out, Client& c){
    c.afiseazaComanda(out);
    return out;
}

int Client::getTotalConsumat(){
    return totalConsumat;
}

void Client::setMeniu(Meniu meniu){
    this->meniu = meniu;
    comanda.setMeniu(meniu);
}
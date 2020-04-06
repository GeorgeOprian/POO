#include "client.h"


using namespace std;

Client::Client(Meniu meniu):comanda(meniu){
    this->meniu = meniu;
    this->nrProduse = 0;
    this->totalCosumat = 0;
    this->comandaPreluata = 0;
}
Client::Client(Meniu meniu, int nrProduse, int totalConsumat):comanda(meniu){
    this->meniu = meniu;
    this->nrProduse = nrProduse;
    this->totalCosumat = totalCosumat;
    this->comandaPreluata = 0;
}
Client::Client(const Client& c){
    this->comanda = c.comanda;
    this->nrProduse = c.nrProduse;
    this->meniu = c.meniu;
    this->totalCosumat = c.totalCosumat;
    this->comandaPreluata = c.comandaPreluata;
}
Client& Client::operator=(const Client& c){
    if (this!=&c){
        this->comanda = c.comanda;
        this->nrProduse = c.nrProduse;
        this->meniu = c.meniu;
        this->totalCosumat = c.totalCosumat;
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
            cout << "\nTotal: " << comanda.getTotal() << " lei\n";
            comanda.setTotal();
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
}
ostream& operator<<(ostream& out, Client& c){
    c.afiseazaComanda(out);
    return out;
}

int Client::getTotalConsumat(){
    return totalCosumat;
}


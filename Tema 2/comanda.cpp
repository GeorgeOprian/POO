#include "comanda.h"

using namespace std;

Comanda::Comanda(){
    total = 0;
    nrProduse = 0;
}
Comanda::Comanda(Meniu meniu, int total, int nrProduse){
    this->meniu = meniu;
    this->total = total;
    this->nrProduse = nrProduse;
}
Comanda::Comanda(const Comanda& c){
    this->meniu = c.meniu;
    this->listaProduse = c.listaProduse;
    this ->total = c.total;
    this->nrProduse = c.nrProduse;
}
Comanda& Comanda::operator=(const Comanda& c){
    if (this != &c){
        this->meniu = meniu;
        this->listaProduse = c.listaProduse;
        this ->total = c.total;
        this->nrProduse = c.nrProduse;
    }
    return *this;
}
void Comanda::citire(istream& in){
    string optiune;
    cout << "Doriti supa sau ciorba?\n";
    getline(in, optiune);
    Produs* p;
    if (optiune == "supa"){
        p = (Supa*) new Produs;
        cout << "Avem de: ";
        for (int i =0; i < nrSupe; i++){
            cout << supe[i]->getNumeProdus() << " ";
        }
        cout << "\nDe care doriti?\n";
        getline(in, optiune);
        for (int i = 0; i< nrSupe; i++){
            if (supe[i]->getNumeProdus() == optiune){
                cout <<supe[i]->getNumeProdus();
                listaProduse.push_back(p);
                //dynamic_cast<Supa*>(listaProduse[nrProduse]);
                listaProduse[nrProduse] = supe[i];
                //listaProduse.push_back(dynamic_cast<Produs*>(supe[i]));
            }
        }
        nrProduse++;
        //nrSupe++;
    }
    // if (optiune == "ciorba"){
    //     p = (Ciorba*) new Produs;
    //     cout << "De care doriti?\n";
    //     for (int i =0; i < nrSupe; i++){
    //         cout << supe[i]->getNumeProdus() << " ";
    //     }
    //     getline(in, optiune);
    //     for (int i = 0; i< nrCiorbe; i++){
    //         if (ciorbe[i]->getNumeProdus() == optiune){
    //             listaProduse.push_back(dynamic_cast<Produs*>(ciorbe[i]));
    //         }
    //     }
    // }

}
istream& operator>>(istream& in, Comanda& c){
    c.citire(in);
    return in;
}
void Comanda::afisare(ostream& out){
    if (nrSupe){
        cout << *supe[0];
    }
    if (nrCiorbe){
        cout << *ciorbe[0];
    }
}
ostream& operator<<(ostream& out, Comanda& c){
    c.afisare(out);
    return out;
}
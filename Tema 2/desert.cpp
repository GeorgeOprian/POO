#include "desert.h"
using namespace std;

//implemantare clasa Desert
Desert::Desert(string numeProdus, int pret, int cantintate, string unitateMasura, int nrMinUM , int nrMAxUM)
        :Produs(numeProdus, pret, cantintate, unitateMasura){
    this->nrMAxUM = nrMAxUM;
    this->nrMinUM = nrMinUM;
}
Desert::Desert(const Desert& d):Produs(d){
    this->nrMAxUM = d.nrMAxUM;
    this->nrMinUM = d.nrMinUM;
}
Desert& Desert::operator=(const Desert& d){
    if (this != &d){
        Produs::operator=(d);
        this->nrMAxUM = d.nrMAxUM;
        this->nrMinUM = d.nrMinUM;
    }
    return *this;
}
void Desert::citire(ifstream& in){
    citireNume(in);
    citirePret(in);
    citireCantitate(in);
    citireUnitateMasura(in);
    cout << "Introduceti restrictii pentru unitate de masura? (0/1) ";
    bool optiune;
    in >> optiune;
    if(optiune){
        cout << "Introduceti numarul minim de " << unitateMasura << ": ";
        in >> nrMinUM; 
        cout << "Introduceti numarul maxim de " << unitateMasura << ": ";
        in >> nrMAxUM; 
    }
}
ifstream& operator>>(ifstream& in, Desert& d){
    d.citire(in);
    return in;
}
void Desert::afisare(ostream& out){
    out<< endl << numeProdus << ":\n";
    out << "Pret: " << pret * cantitate << " lei pe " << cantitate << " " << unitateMasura <<"\n";
}
ostream& operator<<(ostream& out, Desert& d){
    d.afisare(out);
    return out;
}

void Desert::setNrMinUM(int nr){
    nrMinUM = nr;
}
void Desert::setNrMaxUM(int nr){
    nrMAxUM = nr;
}
int Desert::getNrMinUM(){
    return nrMinUM;
}
int Desert::getNrMaxUM(){
    return nrMAxUM;
}
//implementare clasa Deserturi
// Deserturi::Deserturi(vector<Desert> deserturi = {}, int nrDeserturi = 0){
//     this->deserturi = deserturi;
//     this->nrDeserturi = nrDeserturi;
// }

// Deserturi::Deserturi(const Deserturi& d){
//     this->deserturi = d.deserturi;
//     this->nrDeserturi = d.nrDeserturi;
// }
// Deserturi& Deserturi::operator=(const Deserturi& d){
//     if (this != &d){
//         this->deserturi = d.deserturi;
//         this->nrDeserturi = d.nrDeserturi;
//     }
//     return *this;
// }
// void Deserturi::citire(ifstream& in){
//     cout << "Introduceti numarul de Deserturi: ";
//     in >> nrDeserturi;
//     if (nrDeserturi){
//         Desert d;
//         for (int i = 0; i < nrDeserturi; i++){
//             in.get();
//             in >> d;
//             deserturi.push_back(d);
//         }
//     }
// }
// ifstream& operator>>(ifstream& in, Deserturi& d){
//     d.citire(in);
//     return in;
// }
// void Deserturi::afisare(ostream& out){
//     if (nrDeserturi){
//         cout <<"Deserturi:\n";
//         for (int i = 0; i < nrDeserturi; i++){
//             out << deserturi[i]<<endl;
//         }
//         out <<endl;
//     }
// }
// ostream& operator<<(ostream& out, Deserturi&d){
//     d.afisare(out);
//     return out;
// }
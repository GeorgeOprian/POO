//#include <bits/stdc++.h>
#include "mancare.h"
//#include  "produs.h"
using namespace std;

//iplementare clasa Supa
Supa::Supa(string numeProdus , int pret, int cantitate, string unitateMasura)
            :Produs(numeProdus, pret, cantitate, unitateMasura){
}
Supa::Supa(const Supa& s):Produs(s){}
Supa& Supa::operator=(const Supa& s){
    if(this!= &s){
        Produs::operator=(s);
    }
    return *this;
}
void Supa::afisare(ostream& out){
    Produs::afisare(out);
    out<<endl;
}
Ciorba::Ciorba(string numeProdus , int pret, int cantitate, string unitateMasura , bool ardei, bool smantana)
                :Produs(numeProdus, pret, cantitate, unitateMasura){
    this->ardei = ardei;
    this->smantana = smantana;
}
Ciorba::Ciorba(const Ciorba& c):Produs(c){
    this->ardei = c.ardei;
    this->smantana = c.smantana;
}
Ciorba& Ciorba::operator=(const Ciorba& c){
    Produs::operator=(c);
    this->ardei = c.ardei;
    this->smantana = c.smantana;
    return *this;
}
void Ciorba::citire(ifstream& in){
    Produs::citire(in);
    // cout << "Adaugati si ardei? (0 / 1) ";
    // in >> this->ardei;
    // cout << "Adaugati si smantana? (0 / 1) ";
    // in >> this->smantana;
}
void Ciorba::afisare(ostream& out){
    Produs::afisare(out);
    cout << "Optional:\n";
    if (this->ardei) {
        cout <<"Ardei\n";
    }
    if (this->smantana){
        cout << "Smantana\n";
    }
    out <<endl;
}
void Ciorba::setArdei(bool ardei){
    this->ardei = ardei;
}
void Ciorba::setSmantana(bool smantana){
    this->smantana = smantana;
}
//implementare clasa ciorbe
// Ciorbe::Ciorbe(vector<Ciorba> c, int nrCiorbe, vector <Supa> s, int nrSupe){
//     this->ciorbe = c;
//     this->supe = s;
//     this->nrCiorbe = nrCiorbe;
//     this->nrSupe = nrSupe;
// }
// Ciorbe::Ciorbe(const Ciorbe& c){
//     this->ciorbe = c.ciorbe;
//     this->nrCiorbe = c.nrCiorbe;
//     this->supe = c.supe;
//     this->nrSupe = c.nrSupe;
// }

// Ciorbe& Ciorbe::operator=(const Ciorbe& c){
//     if (this != &c){
//         this->ciorbe = c.ciorbe;
//         this->nrCiorbe = c.nrCiorbe;
//         this->supe = c.supe;
//         this->nrSupe = c.nrSupe;
//     }
//     return *this;
// }

// void Ciorbe::citire(ifstream& in){
//     cout << "Puteti introduce date despre ciorbe si supe\n";
//     cout << "Cate ciorbe doriti sa cititi? ";
//     in >> nrCiorbe;
//     Ciorba c;
//     for (int i = 0; i < nrCiorbe; i++){
//         in.get();
//         in >> c;
//         ciorbe.push_back(c);
//     }
//     cout << "\nCate supe doriti sa cititi? ";
//     in >> nrSupe;
//     Supa s;
//     for (int i = 0; i < nrSupe; i++){
//         in.get();
//         in >> s;
//         supe.push_back(s);
//     }
//     //cout <<"citeste supele"<< nrSupe<<endl;
// }
// ifstream& operator>>(ifstream& in, Ciorbe& c){
//     c.citire(in);
//     return in;
// }
// void Ciorbe::afisare(ostream& out){
//     if (nrCiorbe){
//         out << "\nCiorbe:\n";
//         for (int i = 0; i < this->nrCiorbe; i++){
//             out << this->ciorbe[i];
//         }
//     }
//     if(nrSupe){
//         out << "\nSupe:\n";
//         //cout <<nrSupe<<endl;
//         for (int i = 0; i < this->nrSupe; i++){
//             out << this->supe[i];
//         }
//     }
// }
// ostream& operator<<(ostream& out, Ciorbe& c){
//     c.afisare(out);
//     return out;
// }

//implementare clasa Pui
Pui::Pui(string numeProdus, int pret, int cantintate, string unitateMasura)
        :Produs(numeProdus, pret, cantintate, unitateMasura){
}
Pui::Pui(const Pui& p):Produs(p){
}
void Pui::afisare(ostream& out){
    Produs::afisare(out);
    out<<endl;
}
//implementare clasa Vita
Vita::Vita(string numeProdus, int pret, int cantintate, string unitateMasura , string gradPregatire)
            :Produs(numeProdus, pret, cantintate, unitateMasura){
    this->gradPregatire = gradPregatire;
}
Vita::Vita(const Vita& v):Produs(v){
    this->gradPregatire = v.gradPregatire;
}
Vita& Vita::operator=(const Vita& v){
    if (this != &v){
        Produs::operator=(v);
        this->gradPregatire = v.gradPregatire;
    }
    return *this;
}
void Vita::afisare(ostream& out){
    Produs::afisare(out);
    out << "Grad de pregatire: " << gradPregatire<<endl;// << endl;
}
void Vita::setGradPregatire(string gradPregatire){
    this->gradPregatire = gradPregatire;
    //cout <<"seteaza gradul de pregatire\n";
}
string Vita::getGradPregatire(){
    return gradPregatire;
}

//implementare clasa FeluriPrincipale
// FeluriPrincipale::FeluriPrincipale(vector<Pui> feluriPui = {}, int nrFeluriPui = 0, vector <Vita> feluriVita = {}, int nrFeluriVita = 0, vector<Produs> garnituri = {}, int nrGarnituri = 0){
//     this->feluriPui = feluriPui;
//     this ->nrFeluriPui = nrFeluriPui;
//     this->feluriVita = feluriVita;
//     this->nrFeluriVita = nrFeluriVita;
//     this->garnituri = garnituri;
//     this->nrGarnituri = nrGarnituri;
// }
// FeluriPrincipale::FeluriPrincipale(const FeluriPrincipale& f){
//     this->feluriPui = f.feluriPui;
//     this ->nrFeluriPui = f.nrFeluriPui;
//     this->feluriVita = f.feluriVita;
//     this->nrFeluriVita = f.nrFeluriVita;
//     this->garnituri = f.garnituri;
//     this->nrGarnituri = f.nrGarnituri;
// }
// FeluriPrincipale& FeluriPrincipale::operator=(const FeluriPrincipale& f){
//     if (this != &f){
//         this->feluriPui = f.feluriPui;
//         this ->nrFeluriPui = f.nrFeluriPui;
//         this->feluriVita = f.feluriVita;
//         this->nrFeluriVita = f.nrFeluriVita;
//         this->garnituri = f.garnituri;
//         this->nrGarnituri = f.nrGarnituri;
//     }
//     return *this;
// }

// void FeluriPrincipale::citire(ifstream& in){
//     cout << "Puteti introduce date despre felurile principale, atat cele de pui, cat si cele de vita.\n";
//     cout << "Numarul felurilor de pui: ";
//     in >> nrFeluriPui;
//     if (nrFeluriPui){
//         Pui p; 
//         for (int i = 0; i < nrFeluriPui; i++){
//             in.get();
//             in >>p;
//             feluriPui.push_back(p);
//         }
//     }
//     cout << "Numarul felurilor de vita: ";
//     in >> nrFeluriVita;
//     if (nrFeluriVita){
//         Vita v; 
//         for (int i = 0; i < nrFeluriVita; i++){
//             in.get();
//             in >>v;
//             feluriVita.push_back(v);
//         }
//     }
//     cout << "Numarul garniturilor: ";
//     in >> nrGarnituri;
//     if (nrGarnituri){
//         Produs p; 
//         for (int i = 0; i < nrGarnituri; i++){
//             in.get();
//             in >>p;
//             garnituri.push_back(p);
//         }
//     }
// }

// ifstream& operator>>(ifstream& in, FeluriPrincipale& f){
//     f.citire(in);
//     return in;
// }

// void FeluriPrincipale::afisare(ostream& out){
//     if (nrFeluriPui){
//         out << "\nFeluri pui:\n";
//         for (int i = 0; i < this->nrFeluriPui; i++){
//             out << this->feluriPui[i];
//         }
//     }
//     if(nrFeluriVita){
//         out << "\nFeluri vita:\n";
//         //cout <<nrSupe<<endl;
//         for (int i = 0; i < this->nrFeluriVita; i++){
//             out << this->feluriVita[i];
//         }
//     }
//     if(nrGarnituri){
//         out << "\nGarnituri:\n";
//         //cout <<nrSupe<<endl;
//         for (int i = 0; i < this->nrGarnituri; i++){
//             out << this->garnituri[i];
//         }
//     }
//     out <<endl;
// }
// ostream& operator<<(ostream& out, FeluriPrincipale& f){
//     f.afisare(out);
//     return out;
// }

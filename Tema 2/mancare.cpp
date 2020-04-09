#include "mancare.h"

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
}
string Vita::getGradPregatire(){
    return gradPregatire;
}
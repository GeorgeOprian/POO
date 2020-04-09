#include "bauturi.h"
using namespace std;

 Vin::Vin(string numeProdus, int pret, int cantitate , string unitateMasura , string culoare )
        :Produs(numeProdus, pret, cantitate, unitateMasura){
        this->culoare = culoare;
}
Vin::Vin(const Vin& v):Produs(v){
    this->culoare = v.culoare;
}
Vin& Vin::operator=(const Vin& v){
    if (this != &v){
        Produs::operator=(v);
        this->culoare = v.culoare;
    }
    return *this;
}
void Vin::citire(ifstream& in){
    cout << "Vin pahar: \n";
    citireNume(in);
    citirePret(in);
    citireUnitateMasura(in);
    cout <<"Culoare: ";
    in >> culoare;
       
}
ifstream& operator>>(ifstream& in, Vin& v){
    v.citire(in);
    return in;
}
void Vin::afisare(ostream& out){
    out << numeProdus << " " << culoare << " " << pret * cantitate / 100 << " lei pe " << cantitate << " " << unitateMasura<< endl;
    out <<endl;
}
ostream& operator<<(ostream& out, Vin& v){
    v.afisare(out);
    return out;
}

string Vin::getCuloare(){
    return culoare;
}
void Vin::setCuloare(string culoare){
    this->culoare = culoare;
}
//implementare VinSticla
VinSticla::VinSticla(string numeProdus, int pret, int cantintate, string unitateMasura , 
                    string culoare , string brand , int):Vin(numeProdus, pret, cantintate, unitateMasura, culoare){

    this->brand = brand;
    this->an = an;
}

VinSticla::VinSticla(const VinSticla& v):Vin(v)
{
    this->brand = v.brand;
    this->an = v.an;
}
VinSticla& VinSticla::operator=(const VinSticla& v){
    if (this != &v){
        Vin::operator=(v);
        this->brand = v.brand;
        this->an = v.an;
    }
    return *this;
}

void VinSticla::citire(ifstream& in){
    cout << "Vin sticla: \n";
    cout << "Introduceti brand-ul: ";
    getline(in, brand);
    cout << "Introduceti anul: ";
    in >>an;
    citireCantitate(in);
    citireUnitateMasura(in);
    citirePret(in);
}
ifstream& operator>>(ifstream& in, VinSticla& v){
    v.citire(in);
    return in;
}
void VinSticla::afisare(ostream& out){
    out << brand << " "<< an << " " << cantitate << " " << unitateMasura << " " << pret << " lei"<<endl;
}
ostream& operator<<(ostream& out, VinSticla& v){
    v.afisare(out);
    return out;
}
void VinSticla::setBrand(string brand){
    this->brand = brand;
}
string VinSticla::getBrand(){
    return brand;
}

//implementare clasa bere
Bere::Bere(string numeProdus , int pret, int cantitate, string unitateMasura , string brand )
        :Produs(numeProdus, pret, cantitate, unitateMasura){
    this->brand = brand;
}
Bere::Bere(const Bere& b):Produs(b){
    this->brand = b.brand;
}
Bere& Bere::operator=(const Bere& b){
    if (this != &b){
        Produs::operator=(b);
        this->brand = b.brand;
    }
    return *this;
}
void Bere::citire(ifstream& in){
    cout << "Bere: \n";
    cout << "Brand: ";
    getline(in, brand);
    citireCantitate(in);
    citireUnitateMasura(in);
    citirePret(in);
}
ifstream& operator>>(ifstream& in, Bere& b){
    b.citire(in);
    return in;
}
void Bere::afisare(ostream& out){
    out << "Bere " << brand << " " << cantitate <<" "<< unitateMasura << " " << pret << " lei\n";
}

ostream& operator<<(ostream& out, Bere& b){
    b.afisare(out);
    return out;
}
void Bere::setBrand(string brand){
    this->brand = brand;
}
string Bere::getBrand(){
    return brand;
}
//implementare clasa Apa
Apa::Apa(string numeProdus, int pret, int cantitate, string unitateMasura, string brand, string aciditate)
        :Produs(numeProdus, pret, cantitate, unitateMasura){
    this->brand = brand;
    this->aciditate = aciditate;
}
Apa::Apa(const Apa& a):Produs(a){
    this->brand = a.brand;
    this->aciditate = a.aciditate;
}
Apa& Apa::operator=(const Apa& a){
    if (this != &a){
        Produs::operator=(a);
        this->brand = a.brand;
        this->aciditate = a.aciditate;
    }
    return *this;
}
void Apa::citire(ifstream& in){
    cout << "Apa: \n";
    cout << "Brand: ";
    getline(in, brand);
    citireCantitate(in);
    citireUnitateMasura(in);
    citirePret(in);
    cout << "Minerala sau plata? (1/0) ";
    bool optiune;
    in >> optiune;
    if(optiune){
        aciditate = "minerala";
    }else{
        aciditate = "plata";
    }
}
ifstream& operator>>(ifstream& in, Apa& a){
    a.citire(in);
    return in;
}
void Apa::afisare(ostream& out){
    out << "Apa " << brand << " " << aciditate << " " << cantitate <<" "<< unitateMasura << " " << pret << " lei\n";
}

ostream& operator<<(ostream& out, Apa& a){
    a.afisare(out);
    return out;
}
void Apa::setBrand(string brand){
    this->brand = brand;
}
string Apa::getBrand(){
    return brand;
}
void Apa::setAciditate(string aciditate){
    this->aciditate = aciditate;
}
string Apa::getAciditate(){
    return aciditate;
}
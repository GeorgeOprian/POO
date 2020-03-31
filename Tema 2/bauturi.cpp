#include "bauturi.h"
using namespace std;

 Vin::Vin(string numeProdus = "", int pret = 0, int cantitate = 0, string unitateMasura = "", string culoare = "")
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
void Vin::citire(istream& in){
    cout << "Vin pahar: \n";
    citireNume(in);
    citirePret(in);
    citireUnitateMasura(in);
    cout <<"Culoare: ";
    in >> culoare;
       
}
istream& operator>>(istream& in, Vin& v){
    v.citire(in);
    return in;
}
void Vin::afisare(ostream& out){
    out << numeProdus << " " << culoare;
    out <<endl;
}
ostream& operator<<(ostream& out, Vin& v){
    v.afisare(out);
    return out;
}
//implementare VinSticla
VinSticla::VinSticla(string numeProdus ="", int pret = 0, int cantintate = 0, string unitateMasura = "", 
                    string culoare = "", string brand = "", int an = 0):Vin(numeProdus, pret, cantintate, unitateMasura, culoare){

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

void VinSticla::citire(istream& in){
    cout << "Vin sticla: \n";
    cout << "Introduceti brand-ul: ";
    in >> brand;
    cout << "Introduceti anul: ";
    in >>an;
    citireCantitate(in);
    citireUnitateMasura(in);
    citirePret(in);
}
istream& operator>>(istream& in, VinSticla& v){
    v.citire(in);
    return in;
}
void VinSticla::afisare(ostream& out){
    out << brand << " "<< an << " " << cantitate << " " << unitateMasura <<endl;
}
ostream& operator<<(ostream& out, VinSticla& v){
    v.afisare(out);
    return out;
}

//implementare clasa bere
Bere::Bere(string numeProdus = "", int pret = 0, int cantitate = 0, string unitateMasura = "", string brand = "")
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
void Bere::citire(istream& in){
    cout << "Bere: \n";
    cout << "Brand: ";
    in >> brand;
    citireCantitate(in);
    citireUnitateMasura(in);
    citirePret(in);
}
istream& operator>>(istream& in, Bere& b){
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
//implementare clasa Apa
Apa::Apa(string numeProdus = "", int pret = 0, int cantitate = 0, string unitateMasura = "", string brand = "", string aciditate = "")
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
void Apa::citire(istream& in){
    cout << "Apa: \n";
    cout << "Brand: ";
    in >> brand;
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
istream& operator>>(istream& in, Apa& a){
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

//implementare clasa bauturi
Bauturi::Bauturi(vector<Vin> vinPahar = {}, int nrVinPahar = 0, vector<VinSticla> vinSticla = {}, int nrVinSticla = 0,
                vector<Bere> bere = {}, int nrBeri = 0, vector<Apa> apa = {}, int nrApe = 0){
    this->vinPahar = vinPahar;
    this->nrVinPahar = nrVinPahar;
    this->vinSticla = vinSticla;
    this->nrVinSticla = nrVinSticla;
    this->bere = bere;
    this->nrBeri = nrBeri;
    this->apa = apa;
    this->nrApe = nrApe;
}
 
Bauturi::Bauturi(const Bauturi& b){
    this->vinPahar = b.vinPahar;
    this->nrVinPahar = b.nrVinPahar;
    this->vinSticla = b.vinSticla;
    this->nrVinSticla = b.nrVinSticla;
    this->bere = b.bere;
    this->nrBeri = b.nrBeri;
    this->apa = b.apa;
    this->nrApe = b.nrApe;
}
Bauturi& Bauturi::operator=(const Bauturi& b){
    if(this != &b){
        this->vinPahar = b.vinPahar;
        this->nrVinPahar = b.nrVinPahar;
        this->vinSticla = b.vinSticla;
        this->nrVinSticla = b.nrVinSticla;
        this->bere = b.bere;
        this->nrBeri = b.nrBeri;
        this->apa = b.apa;
        this->nrApe = b.nrApe;
    }
    return *this;
}

void Bauturi::citire(istream& in){
    cout << "Introduceti numarul de vinuri la pahar: ";
    in >>nrVinPahar;
    if (nrVinPahar){
        Vin v;
        for (int i = 0; i < nrVinPahar; i++){
            in.get();
            in >> v;
            vinPahar.push_back(v);
        }
    }
    cout << "Introduceti numarul de branduri de vinuri la sticla: ";
    in >>nrVinSticla;
    if (nrVinSticla){
        VinSticla v;
        for (int i = 0; i < nrVinSticla; i++){
            in.get();
            in >> v;
            vinSticla.push_back(v);
        }
    }
    cout << "Introduceti numarul de branduri de bere: ";
    in >>nrBeri;
    if (nrBeri){
        Bere b;
        for (int i = 0; i < nrBeri; i++){
            in.get();
            in >> b;
            bere.push_back(b);
        }
    }
    cout << "Introduceti numarul de branduri de apa: ";
    in >>nrApe;
    if (nrApe){
        Apa a;
        for (int i = 0; i < nrApe; i++){
            in.get();
            in >> a;
            apa.push_back(a);
        }
    }
}
istream& operator>>(istream& in, Bauturi& b){
    b.citire(in);
    return in;
}

void Bauturi::afisare(ostream& out){
    out << endl;
    if (nrVinPahar){
        out << "Vin la Pahar:\n";
        for (int i = 0; i < nrVinPahar; i++){
            out << vinPahar[i];
        }
    }
    if (nrVinSticla){
        out << "Vin la Sticla:\n";
        for (int i = 0; i < nrVinSticla; i++){
            out << vinSticla[i];
        }
    }
    if (nrBeri){
        out << "Bere:\n";
        for (int i = 0; i < nrBeri; i++){
            out << bere[i];
        }
    }
    if (nrApe){
        out << "Apar:\n";
        for (int i = 0; i < nrApe; i++){
            out << apa[i];
        }
    }
}
ostream& operator<<(ostream& out, Bauturi& b){
    b.afisare(out);
    return out;
}
#include <bits/stdc++.h>

using namespace std;
const double limInfMica = 3.86;
const double limInfCompacta = 4.2;

class Automobil
{
    protected:
        string marca;
        int an;
        int pret;
        int putere; //CP
        int consum; //l
        double lungime;
    public:
        Automobil(string, int, int, int, int, double);
        Automobil(const Automobil&);
        virtual ~Automobil(){};

        Automobil& operator= (const Automobil&);
        friend istream& operator>>(istream&, Automobil&);
        friend ostream& operator<<(ostream&, Automobil&);

        virtual void citire(istream&);
        virtual void afisare(ostream&);

};
//  Prima varianta
///automobil -> masina <mica mini> (in plus categorie) -> compacta (in plus model)
//           -> monovolume (discounturi + ...)

// A doua varianta
/// masina <mica mini> (in plus categorie) -> compacta (in plus model)
//                                         -> monovolume (discounturi + ...)
// functia tip (mica/mini, compacta, monovolume in ifuri)
// 



Automobil::Automobil(string marca = "", int an = 0, int pret = 0, int putere = 0, int consum = 0, double lungime = 0)
{
    this->marca = marca;
    this->an = an;
    this->pret = pret;
    this->consum = consum;
    this->putere = putere;
    this->lungime = lungime;
}
Automobil::Automobil(const Automobil& a){
    this->marca = a.marca;
    this->an = a.an;
    this->pret = a.pret;
    this->consum = a.consum;
    this->putere = a.putere;
    this->lungime = a.lungime;
}

Automobil& Automobil::operator=(const Automobil& a){
    if (this != &a){
        this->marca = a.marca;
        this->an = a.an;
        this->pret = a.pret;
        this->consum = a.consum;
        this->putere = a.putere;
        this->lungime = a.lungime;
    }
    return *this;
}

void Automobil::citire(istream& in){
    cout << "Introduceti detalii despre masina:\n";
    cout << "Marca: ";
    in >> marca;
    cout << "Anul primei inmatriculari: ";
    in >> an;
    cout << "Pret in euro: ";
    in >> pret;
    cout << "Putere in CP: ";
    in >> putere;
    cout << "Consum in l/100km: ";
    in >> consum;
    cout << "Lungime: ";
    in >> lungime;
}

istream& operator>>(istream& in, Automobil& a){
    a.citire(in);
    return in;
}

void Automobil::afisare(ostream& out){
    out << "Marca: ";
    out << marca << endl;
    out << "Anul primei inmatriculari: ";
    out << an << endl;
    out << "Pret in euro: ";
    out << pret << endl;
    out << "Putere in CP: ";
    out << putere << endl;
    out << "Consum in l/100km: ";
    out << consum << endl;
    out << "Lungime: ";
    out << lungime << endl;
}

ostream& operator<<(ostream& out, Automobil& a){
    a.afisare(out);
    return out;
}
class Masina:public Automobil
{
    protected:
        string categorie;
    public:
        Masina(string, int, int, int, int, double, string);
        Masina(const Masina&);
        virtual ~Masina(){};

        Masina& operator= (const Masina&);

        virtual void citire(istream&);
        virtual void afisare(ostream&);
};

Masina::Masina(string marca = "", int an = 0, int pret = 0, int putere = 0, int consum = 0, double lungime = 0, string categorie = "")
                :Automobil(marca, an, pret, putere, consum, lungime)
{
    this->categorie = categorie;
}

Masina::Masina(const Masina& m):Automobil(m){
    this->categorie = m.categorie;
}

Masina& Masina::operator= (const Masina& m){
    if(this != & m){
        Automobil::operator=(m);
        this->categorie = m.categorie;
    }
    return *this;
}
void Masina::citire(istream& in){
    Automobil::citire(in);
    cout << ""
}

class Monovolume: public Masina
{
    private:
        bool nou;
        int discount;
        int nrLocuri;
        string lunaCumparare;
    public:
        Monovolume(string, int, int, int, int, double, string, bool, int, int, string);
        Monovolume(const Monovolume&);
        ~Monovolume();

        Monovolume& operator= (const Monovolume&);
        void citire(istream&);
        void afisare(ostream&);

};

Monovolume::Monovolume(string marca = "", int an = 0, int pret = 0, int putere = 0, int consum = 0, double lungime = 0, string categorie = "", 
                        bool nou = 0, int discount = 0, int nrLocuri = 0, string lunaCumparare = ""):Masina(marca, an, pret, putere, consum, lungime, categorie)
{
    this->nou = nou;
    this->discount = discount;
    this->nrLocuri = nrLocuri;
    this->lunaCumparare = lunaCumparare;
}
Monovolume::Monovolume(const Monovolume& m):Masina(m){
    this->nou = m.nou;
    this->discount = m.discount;
    this->nrLocuri = m.nrLocuri;
    this->lunaCumparare = m.lunaCumparare;
}

Monovolume& Monovolume::operator= (const Monovolume& m){
    if (this != &m){
        Masina::operator=(m);
        this->nou = m.nou;
        this->discount = m.discount;
        this->nrLocuri = m.nrLocuri;
        this->lunaCumparare = m.lunaCumparare;
    }
    return *this;
}

int main(){

    return 0;
} 
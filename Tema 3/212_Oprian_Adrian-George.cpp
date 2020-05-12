#include <bits/stdc++.h>

using namespace std;
const double limInfMica = 3.86;
const double limInfCompacta = 4.2;
vector <string> categorii = {"mini", "mica", "compacta", "monovolume"};
vector <string> modeleCompacte = {"hatchback", "combi", "sedan"};
vector <string> luni = {"ianurie", "februarie", "martie", "aprilie", "mai", "iunie", 
                        "iulie", "august", "septembrie", "octombrie", "noiembrie", "decembrie"};

string convertLower (string data){
    for_each(data.begin(), data.end(), [](char& c){
        c = ::tolower(c);
    });
    return data;
}

class Masina
{
    protected:
        string categorie;
        string marca;
        int an;
        int pret;
        int putere;
        double consum;
        double lungime;
        static int nrMasiniGestionate;
    public:
        Masina(string, string, int, int, double, double);
        Masina(const Masina&);
        virtual ~Masina(){
            nrMasiniGestionate--;
        };

        Masina& operator= (const Masina&);
        friend bool operator>(const Masina&, const Masina&);
        friend istream& operator>>(istream&, Masina&);
        friend ostream& operator<<(ostream&, Masina&);

        virtual void citire(istream&);
        virtual void afisare(ostream&);
        static void nrMasini(){
            cout << "Firma noasta a gestionat " << nrMasiniGestionate << endl;
        }
        int getAn() const;
        bool operator<(const Masina& m){
            return an < m.an;
        }
        bool getNou();
        bool operator==(const Masina&);
};
int Masina::nrMasiniGestionate;
Masina::Masina(string categorie ="", string marca = "", int pret = 0, int putere = 0, double consum = 0, double lungime = 0)
{
    try {
        if (categorie != ""){
            categorie = convertLower(categorie);
            if (find(categorii.begin(), categorii.end(), categorie) == categorii.end())
                throw 1;
        }
        this->categorie = categorie;
    }catch (int){
        cout << "Categoria introdusa nu a fost gasita\n";
        exit(EXIT_FAILURE);
    }
    this->marca = marca;
    time_t current_time = time(0);
    tm *ct = localtime(&current_time);
    an = 1900 + ct->tm_year; //setez anul ca anul curent pentru fiecare masina
                            //mai exact la construire fiecare masina o sa fie noua
                           //doar in monovolume ma intereseaza anul fabricatie asta daca e sh
    try{
        if (pret < 0) {
            throw 1;
        }
        this->pret = pret;
    }catch(int){
        cout << "Pretul trebuie sa fie un numar pozitiv\n";
        exit(EXIT_FAILURE);
    }
    try{
        if (consum < 0) {
            throw 1;
        }
        this->consum = consum;
    }catch(int){
        cout << "Consumul trebuie sa fie un numar pozitiv\n";
        exit(EXIT_FAILURE);
    }
    try{
        if (putere < 0) {
            throw 1;
        }
        this->putere = putere;
    }catch(int){
        cout << "Puterea trebuie sa fie un numar pozitiv\n";
        exit(EXIT_FAILURE);
    }
    try{
        if (lungime < 0) {
            throw 1;
        }
        this->lungime = lungime;
    }catch(int){
        cout << "Lungimea trebuie sa fie un numar pozitiv\n";
        exit(EXIT_FAILURE);
    }
    nrMasiniGestionate++;
}

Masina::Masina(const Masina& m){
    this->categorie = m.categorie;
    this->marca = m.marca;
    this->an = m.an;
    this->pret = m.pret;
    this->consum = m.consum;
    this->putere = m.putere;
    this->lungime = m.lungime;
    nrMasiniGestionate++;
}

Masina& Masina::operator= (const Masina& m){
    if(this != & m){
        this->categorie = m.categorie;
        this->marca = m.marca;
        this->an = m.an;
        this->pret = m.pret;
        this->consum = m.consum;
        this->putere = m.putere;
        this->lungime = m.lungime;
    }
    return *this;
}
void Masina::citire(istream& in){
    try {
        cout << "Introduceti detalii despre masina:\n";
        cout << "Marca: ";
        in >> marca;
        for (unsigned int i = 0; i<marca.size(); i++)
            if (marca[i] != ' '){
                if (marca[i] < 'A' || marca[i] > 'Z'){
                    if(marca[i] < 'a' || marca[i] > 'z'){
                        throw 1;
                    }
                }   
            }
    }catch (int x){
        cout <<"Marca masinii trebuie sa contina doar litere";
        exit(EXIT_FAILURE);
    }
    
    cout << "Pret in euro: ";
    in >> pret;
    while (pret <= 0){
        cout << "Pretul trebuie sa fie un numar pozitiv\n";
        cout << "Introduceti alta valoare: ";
        in >> pret;
    }
    cout << "Putere in CP: ";
    in >> putere;
    while (putere <= 0){
        cout << "Puterea trebuie sa fie un numar pozitiv\n";
        cout << "Introduceti alta valoare: ";
        in >> putere;
    }
    cout << "Consum in l/100km: ";
    in >> consum;
    while (consum <= 0){
        cout << "Consumul trebuie sa fie un numar pozitiv\n";
        cout << "Introduceti alta valoare: ";
        in >> consum;
    }
    cout << "Lungime: ";
    in >> lungime;
    while (lungime <= 0){
        cout << "Lungimea trebuie sa fie un numar pozitiv\n";
        cout << "Introduceti alta valoare: ";
        in >> lungime;
    }
    if (lungime < 3.85) categorie = "Mini";
    else{
        if (lungime < 4.2) categorie = "Mica";
        else categorie = "";
    }
}

istream& operator>>(istream& in, Masina& m){
    m.citire(in);
    return in;
}

void Masina::afisare(ostream& out){
    cout << "\n########################################\n";
    out << "Categorie: ";
    out << categorie << endl;
    out << "Marca: ";
    out << marca << endl;
    out << "Anul fabricatiei: ";
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

ostream& operator<<(ostream& out, Masina& m){
    m.afisare(out);
    return out;
}

int Masina::getAn() const{
    return an;
}
bool operator> (const Masina& m1, const Masina& m2){
    if (m1.getAn() > m2.getAn())
        return 1;
    return 0;
}

bool Masina::getNou(){
    time_t current_time = time(0);
    tm *ct = localtime(&current_time);
    int anCurent = 1900 + ct->tm_year;
    return (an == anCurent);
} 

bool Masina::operator==(const Masina& m){
    if (this->categorie != m.categorie)
        return 0;
    if (this->marca != m.marca)
        return 0;
    if (this->an != m.an)
        return 0;
    if (this->pret != m.pret)
        return 0;
    if (this->putere != m.putere)
        return 0;
    if (this->lungime != m.lungime)
        return 0;
    return 1;
}
class Compacta: public Masina
{
    private:
        string model;
    public:
        Compacta(string, string, int, int, double, double, string);
        Compacta(const Compacta&);
        ~Compacta(){};

        Compacta& operator=(const Compacta&);

        void citire(istream&);
        void afisare(ostream&);

        bool operator==(const Compacta&);

};

Compacta::Compacta(string categorie ="", string marca = "", int pret = 0,
                    int putere = 0, double consum = 0, double lungime = 0, string model = ""):
                    Masina(categorie, marca, pret, putere, consum, lungime)
{
    this->categorie = "Compacta";
    try {
        if (model != ""){
            model = convertLower(model);
            if (find(modeleCompacte.begin(), modeleCompacte.end(), model) == modeleCompacte.end())
                throw 1;
        }
        this->model = model;
    }catch (int){
        cout << "Modelul introdus nu a fost gasit\n";
        exit(EXIT_FAILURE);
    }
}
Compacta::Compacta(const Compacta& c):Masina(c){
    this->categorie = "Compacta";
    this->model = c.model;
}
Compacta& Compacta::operator=(const Compacta& c){
    if (this != &c){
        Masina::operator=(c);
        this->model = c.model;
    }
    return *this;

}
void Compacta::citire(istream& in){
    cout << "Citire Compacta:\n";
    Masina::citire(in);
    categorie = "Compacta";
    while (lungime < 4.2){
        cout << "Lungimea trebuie sa fie un numar intre 4.2 si 4.5\n";
        cout << "Introduceti alta valoare: ";
        in >> lungime;
    }
    cout << "Alegeti unul dintre cele 3 modele: \n";
    int count = 0;
    for (vector <string>::iterator s = modeleCompacte.begin(); s != modeleCompacte.end(); s++)
        cout << ++count << ") "  << *s << endl;
    cout << "Introduceti numarul modelului: ";
    int nrModel;
    in >> nrModel;
    model = modeleCompacte[nrModel - 1];
    model = convertLower(model);
    while (find(modeleCompacte.begin(), modeleCompacte.end(), model) == modeleCompacte.end()){
        cout << "Introduceti un model din lista de mai sus: ";
        getline(in, model);
    }
    this->model = model;
}
void Compacta::afisare(ostream& out){
    Masina::afisare(out);
    cout << "Model: " << model << endl; 
}

bool Compacta::operator==(const Compacta& c){
    Masina::operator==(c);
    if (this->model != c.model)
        return 0;
    return 1;
}
class Monovolume: public Masina
{
    private:
        bool nou;
        int discount; 
        int nrLocuri;
        int lunaCumparare;
    public:
        Monovolume(string, string, int, int, double, double, bool, int, int, int);
        Monovolume(const Monovolume&);
        ~Monovolume(){};

        Monovolume& operator= (const Monovolume&);
        void citire(istream&);
        void afisare(ostream&);

        void calculeazaDiscount();
        bool operator==(const Monovolume&);
};

Monovolume::Monovolume(string categorie ="", string marca = "", int pret = 0, int putere = 0, 
                    double consum = 0, double lungime = 0, bool nou = 0, int discount = 0, int nrLocuri = 0, int lunaCumparare = 0)
                    :Masina(categorie, marca, pret, putere, consum, lungime)
{
    this->nou = nou;
    try{
        if (discount < 0) {
            throw 1;
        }
        this->discount = discount;
    }catch(int){
        cout << "Discountul trebuie sa fie un numar pozitiv\n";
        exit(EXIT_FAILURE);
    }
    try{
        if (nrLocuri && (nrLocuri < 5 || nrLocuri > 7)) {
            throw 1;
        }
        this->nrLocuri = nrLocuri;
    }catch(int){
        cout << "Van-ul trebuie sa aiba intre 5 si 7 locuri\n";
        exit(EXIT_FAILURE);
    }
    try {
        if( lunaCumparare && (lunaCumparare < 1 || lunaCumparare > 12))
            throw 1;
        this->lunaCumparare = lunaCumparare;
    }catch (int){
        cout << "Valoarea introdusa pentru luna nu este valida\n";
        exit(EXIT_FAILURE);
    }
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

void Monovolume::calculeazaDiscount(){
    if(nou) discount = 0;
    else{
        time_t current_time = time(0);
        tm *ct = localtime(&current_time);
        int anCurent = 1900 + ct->tm_year;
        discount = 0.05 * (anCurent - an);
        if (lunaCumparare >= 6 && lunaCumparare <= 8)
            discount = discount + 0.1; 
    }
}
void Monovolume::citire(istream& in){
    cout << "Citire Monovolume\n";
    Masina::citire(in);
    categorie = "Monovolume";
    time_t current_time = time(0);
    tm *ct = localtime(&current_time);
    cout << "Nou sau sh? (1/0): ";
    in >> nou;
    if(!nou){
        cout << "Anul fabricatiei: ";
        in >> an;
        int anCurent = 1900 + ct->tm_year;
        while (an <= 1970 || an > anCurent){
            cout << "Anul trebuie sa fie intre 1970 si " << anCurent << endl;
            cout << "Introduceti alta valoare: ";
            in >> an;
        }
    }
    
    cout << "Nr locuri: (intre 5 si 7): ";
    in >> nrLocuri;
    while (nrLocuri < 5 || nrLocuri > 7){
        cout << "Introduceti un numar intre 5 si 7: ";
        in >> nrLocuri;
    }
    
    lunaCumparare = ct->tm_mon + 1;
    calculeazaDiscount();
    pret = pret - discount;
}
void Monovolume::afisare(ostream& out){
    Masina::afisare(out);
    cout << "Discount: " << discount<<endl;
    cout << "Numar locuri: " << nrLocuri << endl;
    cout << "Luna cumparare: " << luni[lunaCumparare - 1] << endl;
}

bool Monovolume::operator==(const Monovolume& m){
    Masina::operator==(m);
    if (this->nou != m.nou)
        return 0;
    if (this->discount != m.discount)
        return 0;
    if (this->nrLocuri != m.nrLocuri)
        return 0;
    if (this->lunaCumparare != m.lunaCumparare)
        return 0;
    return 1;
}

template <class T>
class Vanzare
{
    private:
        vector<T> masiniInStoc;
        vector<T> masiniVandute;
        int nrMasiniInStoc;
        int nrMasiniVandute;
    public:
        Vanzare(vector <T> masiniInStoc = {}, vector <T> masiniVandute = {},
                                int nrMasiniInStoc = 0, int nrMasiniVandute = 0)
        {
            for (auto & it : masiniInStoc){
                this->masiniInStoc.push_back(it);
            }
            for (auto & it : masiniVandute){
                this->masiniVandute.push_back(it);
            }
            this->nrMasiniInStoc = nrMasiniInStoc;
            this->nrMasiniVandute = nrMasiniVandute;
        }

        Vanzare(const Vanzare& v){
            for (auto & it : v.masiniInStoc){
                this->masiniInStoc.push_back(it);
            }
            for (auto & it : v.masiniVandute){
                this->masiniVandute.push_back(it);
            }
            this->nrMasiniInStoc = v.nrMasiniInStoc;
            this->nrMasiniVandute = v.nrMasiniVandute;
        }
        ~Vanzare(){};
        void adaugaInStoc(T m){
            masiniInStoc.push_back(m);
            nrMasiniInStoc++;
        }
        void vanzare(T m){
            typename vector <T>:: iterator it;
            it = find (masiniInStoc.begin(), masiniInStoc.end(), m);
            masiniVandute.push_back(*it);
            masiniInStoc.erase(it);
            nrMasiniVandute++;
            nrMasiniInStoc--;
        }
        
        void afisareMasiniInStoc(ostream& out){
            if (!nrMasiniInStoc)
                cout << "\nNu sunt masini in stoc\n";
            else{
                out << "\nIn stoc avem urmatoarele masini:\n";
                int counter = 1;
                for (auto& m : masiniInStoc){
                    cout << "Masina " << counter++ << ".";
                    out << m;
                }
            }
        }
        void afisareMasiniVandute(ostream& out){
            if (!nrMasiniVandute)
                cout << "\nNu am vandut nicio masina\n";
            else{
                out << "\nAm vandut urmatoarele masini:";
                for (auto& m : masiniVandute){
                    out << m;
                }
            }
        }
        friend ostream& operator<<(ostream& out, Vanzare<T> &m){
            m.afisareMasiniInStoc(out);
            m.afisareMasiniVandute(out);
            return out;
        }
        Vanzare& operator-=(T& v){
            this->vanzare(v);
            return *this;
        }
        T& getMasinaStocLaIndex(int index){
            return masiniInStoc[index];
        }
        int getNrMasiniStoc(){
            return nrMasiniInStoc;
        }
        int getNrMasiniVandute(){
            return nrMasiniVandute;
        }

};

template <>
class Vanzare<Monovolume>
{
    private:
        vector<Monovolume> masiniInStoc;
        vector<Monovolume> masiniVandute;
        int nrMasiniInStoc;
        int nrMasiniVandute;
    public:
        Vanzare(vector <Monovolume> masiniInStoc = {}, vector <Monovolume> masiniVandute = {},
                                int nrMasiniInStoc = 0, int nrMasiniVandute = 0)
        {
            for (auto & it : masiniInStoc){
                this->masiniInStoc.push_back(it);
            }
            for (auto & it : masiniVandute){
                this->masiniVandute.push_back(it);
            }
            this->nrMasiniInStoc = nrMasiniInStoc;
            this->nrMasiniVandute = nrMasiniVandute;
        }

        Vanzare(const Vanzare& v){
            for (auto & it : v.masiniInStoc){
                this->masiniInStoc.push_back(it);
            }
            for (auto & it : v.masiniVandute){
                this->masiniVandute.push_back(it);
            }
            this->nrMasiniInStoc = v.nrMasiniInStoc;
            this->nrMasiniVandute = v.nrMasiniVandute;
        }
        ~Vanzare(){};
        void adaugaInStoc(Monovolume m){
            masiniInStoc.push_back(m);
            nrMasiniInStoc++;
        }
        void vanzare(Monovolume m){
            typename vector <Monovolume>:: iterator it;
            it = find (masiniInStoc.begin(), masiniInStoc.end(), m);
            masiniVandute.push_back(*it);
            masiniInStoc.erase(it);
            nrMasiniVandute++;
            nrMasiniInStoc--;
        }
        
        void afisareMasiniInStoc(ostream& out){
            if (!nrMasiniInStoc)
                cout << "\nNu sunt masini in stoc\n";
            else{
                out << "\nIn stoc avem urmatoarele masini:\n";
                int counter = 1;
                for (auto& m : masiniInStoc){
                    cout << "Masina " << counter++ << ".";
                    out << m;
                }
            }
        }
        void afisareMasiniVandute(ostream& out){
            if (!nrMasiniVandute)
                cout << "\nNu am vandut nicio masina\n";
            else{
                out << "\nAm vandut urmatoarele masini:";
                for (auto& m : masiniVandute){
                    out << m;
                }
            }
        }
        friend ostream& operator<<(ostream& out, Vanzare<Monovolume> &m){
            m.afisareMasiniInStoc(out);
            m.afisareMasiniVandute(out);
            return out;
        }
        Vanzare& operator-=(Monovolume& v){
            this->vanzare(v);
            return *this;
        }
        Monovolume& getMasinaStocLaIndex(int index){
            return masiniInStoc[index];
        }
        int getNrMasiniStoc(){
            return nrMasiniInStoc;
        }
        int getNrMasiniVandute(){
            return nrMasiniVandute;
        }

};

void afisareMeniu(){
    cout << "\nPARC AUTO\n";
    cout << "\nOptiuni:\n";
    cout << "\n###############################################\n";
    cout << "\n1. Introduceti automobile in parcul auto;";
    cout << "\n2. Afisati numarul de automobile din parcul auto;";
    cout << "\n3. Afisati automobilele gestionate de la inceputul companiei;"; 
    cout << "\n4. Afisati automobilele de oras in stoc;";
    cout << "\n5. Afisati automobilele de oras vandute;"; 
    cout << "\n6. Afisati compactele in stoc;";
    cout << "\n7. Afisati compactele vandute;";
    cout << "\n8. Afisati monovolumele in stoc;";
    cout << "\n9. Afisati monovolumele vandute;";
    cout << "\n10. Cumparati o masina;"; 
    cout << "\n\nOrice numar mai mare decat 10 pentru a iesi.\n";
}

void tip(Masina *&p, int &i){
    cout << "\nAvem urmatoarele tipuri de masini: \n";
    cout << "Mica\n";
    cout << "Mini\n";
    cout << "Compacta\n";
    cout << "Monovolume\n";
    cout << "Introduceti tipul: ";
    string tip;
    getline(cin, tip);
    try{
        if ((tip == "Mini" || tip == "mini") || (tip == "Mica" || tip == "mica")){
            p = new Masina;
            cin >> *p;
            i++;
        }else
            if (tip == "Compacta" || tip == "compacta"){
                p = new Compacta;
                cin >> *p;
                i++;
            }else
                if (tip == "Monovolume" || tip == "monovolume"){
                    p = new Monovolume;
                    cin >> *p;
                    i++;
                }else
                    throw 1;
    }
    catch (bad_alloc var){
        cout << "Probleme la alocare\n";
        exit(EXIT_FAILURE);
    }
    catch(int){
        cout << "Nu ati introdus uun tip valid de automobil\n";
    }
}

/*
    Am facut functia pentru a putea tine masinile in set ordonate dupa an
*/
struct compara {
    bool operator() (pair<Masina*, bool>p1, pair<Masina*, bool> p2) const {
        return (*(p1.first) > *(p2.first));
    }
};
void introducetiAutomobile (set<pair<Masina*, bool>, compara> &masiniGestionate, Vanzare<Masina>& masiniDeOras, Vanzare<Compacta>& compacte,
                Vanzare<Monovolume>& monovolume){
    int n;
    cout << "Introduceti numarul de masini pe care vrei sa le adaugati in parcul auto: ";
    cin >> n;
    for (int i = 0; i < n;){
        Masina *p;
        cin.get();
        tip (p, i);
        Compacta *p1 = dynamic_cast<Compacta*>(p);
        if (p1){
            cout << "intra in comp\n";
            compacte.adaugaInStoc(*p1);
            masiniGestionate.insert(pair<Masina*, bool>(new Compacta(*p1), p->getNou()));
        }else{
            Monovolume *p2 = dynamic_cast<Monovolume*>(p);
            if (p2){
                cout << "intra in mono\n";
                monovolume.adaugaInStoc(*p2);
                masiniGestionate.insert(pair<Masina*, bool>(new Monovolume(*p2), p->getNou()));
            }else{
                Masina *p3 = dynamic_cast<Masina*>(p);
                if(p3){
                    cout << "intra in masina\n";
                    masiniDeOras.adaugaInStoc(*p3);
                    masiniGestionate.insert(pair<Masina*, bool>(new Masina(*p3), p->getNou()));
                }
            }
        }

    }
}


void afizeazaAtutomobileleGestionate(set<pair<Masina*, bool>, compara> &masiniGestionate){
    if (masiniGestionate.empty()) 
        cout << "\nNu sunt masini din parcul auto.\n";
    else{
        for(auto& pm: masiniGestionate){
            cout << *pm.first;
            if (pm.second)
                cout << "Masina este noua\n";
            else 
                cout << "Masina este sh\n";
        }
    }
}
/*
    Nu puteam compara prechile de Masina* cu supraincarea din pair
*/
bool comparaPerechi(pair<Masina*, bool>p1, pair<Masina*, bool> p2){
    return (*(p1.first) == *(p2.first) && p1.second == p2.second);
}

/*
    find ul din c++ nu functiona asa ca mi-am implementat singur o functie de cautare
*/
set<pair<Masina*, bool>, compara>::iterator cautaElement(set<pair<Masina*, bool>, compara> &masiniGestionate, pair<Masina*, bool> el){
    set<pair<Masina*, bool>, compara>::iterator it;
    for (it = masiniGestionate.begin(); it != masiniGestionate.end(); it++){
        if (comparaPerechi(*it, el))
            return it;
    }
    return masiniGestionate.end();
}
void Cumparare(set<pair<Masina*, bool>, compara> &masiniGestionate, Vanzare<Masina> &masiniDeOras, Vanzare<Compacta> &masiniCompacte, Vanzare<Monovolume> &monovolume){
    cout << "Avem urmatoarele categorii de automobile:\n";
    cout << "1. Mica/Mini\n";
    cout << "2. Compacta\n";
    cout << "3. Monovolume\n";
    cout << "Introduceti numarul categoriei: ";
    int optiune;
    cin >> optiune;
    int nrMasina;
    switch (optiune)
    {
    case 1:
        masiniDeOras.afisareMasiniInStoc(cout);
        cout << "Introduceti numarul masinii: ";
        cin >> nrMasina;
        if (masiniDeOras.getNrMasiniStoc() < nrMasina)
            cout << "Nu exista in stoc masina cu indexul " << nrMasina << endl;
        else{ 
            masiniDeOras -= masiniDeOras.getMasinaStocLaIndex(nrMasina - 1);
            Masina *masinaCautata = new Masina(masiniDeOras.getMasinaStocLaIndex(nrMasina - 1));
            bool nou = masinaCautata->getNou();
            set<pair<Masina*, bool>, compara> :: iterator it = cautaElement(masiniGestionate, pair<Masina*, bool>(new Masina(*masinaCautata), nou));
            masiniGestionate.erase(it);
        }
        break;
    case 2:
        masiniCompacte.afisareMasiniInStoc(cout);
        cout << "Introduceti numarul masinii: ";
        cin >> nrMasina;
        if (masiniCompacte.getNrMasiniStoc() < nrMasina)
            cout << "Nu exista in stoc masina cu indexul " << nrMasina << endl;
        else{ 
            masiniCompacte -= masiniCompacte.getMasinaStocLaIndex(nrMasina - 1);
            Compacta *masinaCautata = new Compacta(masiniCompacte.getMasinaStocLaIndex(nrMasina - 1));
            bool nou = masinaCautata->getNou();
            set<pair<Masina*, bool>, compara> :: iterator it = cautaElement(masiniGestionate, pair<Masina*, bool>(new Masina(*masinaCautata), nou));
            masiniGestionate.erase(it);
        }
        break;
    case 3:
        monovolume.afisareMasiniInStoc(cout);
        cout << "Introduceti numarul masinii: ";
        cin >> nrMasina;
        if (monovolume.getNrMasiniStoc() < nrMasina)
            cout << "Nu exista in stoc masina cu indexul " << nrMasina << endl;
        else{ 
            monovolume -= monovolume.getMasinaStocLaIndex(nrMasina - 1);
            Monovolume *masinaCautata = new Monovolume(monovolume.getMasinaStocLaIndex(nrMasina - 1));
            bool nou = masinaCautata->getNou();
            set<pair<Masina*, bool>, compara> :: iterator it = cautaElement(masiniGestionate, pair<Masina*, bool>(new Masina(*masinaCautata), nou));
            masiniGestionate.erase(it);
        }
        break;
    default:
        cout << "Nu ati introdus un numar valid\n";
        break;
    }
}
int main(){
    
    int n;
    set<pair<Masina*, bool>, compara> masiniGestionate;
    Vanzare<Masina> masiniDeOras;
    Vanzare<Compacta> masiniCompacte;
    Vanzare<Monovolume> monovolume;
    bool stop = 0;
    short int optiune;
    while (!stop){
        system("CLS");
        afisareMeniu();
        cout << "\nIntroduceti o valoare: ";
        cin >> optiune;
        cin.get();
        switch (optiune)
        {
        case 1:
            introducetiAutomobile(masiniGestionate, masiniDeOras, masiniCompacte, monovolume);
            break;
        case 2:
            Masina::nrMasini();
            break;
        case 3:
            afizeazaAtutomobileleGestionate(masiniGestionate);
            break;
        case 4:
            masiniDeOras.afisareMasiniInStoc(cout);
            break;
        case 5:
            masiniDeOras.afisareMasiniVandute(cout);
            break;
        case 6:
            masiniCompacte.afisareMasiniInStoc(cout);
            break;
        case 7:
            masiniCompacte.afisareMasiniVandute(cout);
            break;
        case 8:
            monovolume.afisareMasiniInStoc(cout);
            break;
        case 9:
            monovolume.afisareMasiniVandute(cout);
            break;
        case 10:
            Cumparare(masiniGestionate, masiniDeOras, masiniCompacte, monovolume);
            break;
        default:
            stop = 1;
            system("CLS");
            cout << "\n#####################################\n";
            cout << "\nMultumesc ca ai folosit aplicatia mea\n";
            cout << "\n#####################################\n";
            break;
        }
        system("Pause");
    }
    
    return 0;
} 

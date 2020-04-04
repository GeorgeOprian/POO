#include "meniu.h"

using namespace std;

Meniu::Meniu(){
    nrSupe = 0;
    nrCiorbe = 0;
    nrPui = 0;
    nrVita = 0;
    nrGarnituri = 0;
    nrDeserturi = 0;
    nrVinPahar = 0;
    nrVinSticla = 0;
    nrBere = 0;
    nrApa = 0;
}
Meniu::Meniu(int nrSupe, int nrCiorbe, int nrPui, int nrVita, int nrGarnituri, int nrDeserturi, int nrVinPahar, int nrVinSticla, int nrBere, int nrApa){
    this->nrSupe = nrSupe;
    this->nrCiorbe = nrCiorbe;
    this->nrPui = nrPui;
    this->nrVita = nrVita;
    this->nrGarnituri = nrGarnituri;
    this->nrDeserturi = nrDeserturi;
    this->nrVinPahar = nrVinPahar;
    this->nrVinSticla = nrVinSticla;
    this->nrBere = nrBere;
    this->nrApa = nrApa;
}
Meniu::Meniu(const Meniu& m){
    this->supe = m.supe;
    this->ciorbe = m.ciorbe;
    this->produsePui = m.produsePui;
    this->produseVita = m.produseVita;
    this->garnituri = m.garnituri;
    this->deserturi = m.deserturi;
    this->vinPahar = m.vinPahar;
    this->vinSticla = m.vinSticla;
    this->bere = m.bere;
    this->apa = m.apa;

    this->nrSupe = m.nrSupe;
    this->nrCiorbe = m.nrCiorbe;
    this->nrPui = m.nrPui;
    this->nrVita = m.nrVita;
    this->nrGarnituri = m.nrGarnituri;
    this->nrDeserturi = m.nrDeserturi;
    this->nrVinPahar = m.nrVinPahar;
    this->nrVinSticla = m.nrVinSticla;
    this->nrBere = m.nrBere;
    this->nrApa = m.nrApa;
    
}
Meniu& Meniu::operator=(const Meniu& m){
    if (this!=&m){
        this->supe = m.supe;
        this->ciorbe = m.ciorbe;
        this->produsePui = m.produsePui;
        this->produseVita = m.produseVita;
        this->garnituri = m.garnituri;
        this->deserturi = m.deserturi;
        this->vinPahar = m.vinPahar;
        this->vinSticla = m.vinSticla;
        this->bere = m.bere;
        this->apa = m.apa;
    
        this->nrSupe = m.nrSupe;
        this->nrCiorbe = m.nrCiorbe;
        this->nrPui = m.nrPui;
        this->nrVita = m.nrVita;
        this->nrGarnituri = m.nrGarnituri;
        this->nrDeserturi = m.nrDeserturi;
        this->nrVinPahar = m.nrVinPahar;
        this->nrVinSticla = m.nrVinSticla;
        this->nrBere = m.nrBere;
        this->nrApa = m.nrApa;
    }
    return *this;
}
void Meniu::citire(ifstream& in){
    bool optiune;
    Produs* p;
    
    try{
        cout << "Doriti sa cititi supe/ciorbe? (0/1) ";
        in >> optiune;
        if (optiune){
            cout << "Introduceti numarul de supe: ";;
            in >> nrSupe;
            for (int i =0; i < nrSupe; i++){
                p = new Supa;
                in.get();
                in  >> *p;
                supe.push_back(p);
            }
            cout << "Introduceti numarul de ciorbe: ";;
            in >> nrCiorbe;
            for (int i =0; i < nrCiorbe; i++){
                p = new Ciorba;
                in.get();
                in >> *p;
                ciorbe.push_back(p);
            }
        }
        cout << "Doriti sa cititi produse din felul principal? (0/1) ";
        in >> optiune;
        if (optiune){
            cout << "Introduceti numarul de produse de pui: ";;
            in >> nrPui;
            for (int i =0; i < nrPui; i++){
                p = new Pui;
                in.get();
                in  >> *p;
                produsePui.push_back(p);
            }
            cout << "Introduceti numarul de produse de vita: ";;
            in >> nrVita;
            for (int i =0; i < nrVita; i++){
                p = new Vita;
                in.get();
                in  >> *p;
                produseVita.push_back(p);
            }
        }
        cout  << "Doriti sa cititi ganituri? (0/1) ";
        in >> optiune;
        if (optiune){
            cout << "Introduceti numarul de garnituri: ";;
            in >> nrGarnituri;
            for (int i =0; i < nrGarnituri; i++){
                p = new Produs;
                in.get();
                in  >> *p;
                garnituri.push_back(p);
            }
        }
        cout << "Doriti sa cititi deserturi? (0/1) ";
        in >> optiune;
        if (optiune){
            cout << "Introduceti numarul de deserturi: ";;
            in >> nrDeserturi;
            for (int i =0; i < nrDeserturi; i++){
                p = new Desert;
                in.get();
                in  >> *p;
                deserturi.push_back(p);
            }
        }
        cout << "Doriti sa cititi bauturi? (0/1) ";
        in >> optiune;
        if (optiune){
            cout << "Introduceti numarul de vinuri la pahar: ";;
            in >> nrVinPahar;
            for (int i =0; i < nrVinPahar; i++){
                p = new Vin;
                in.get();
                in  >> *p;
                vinPahar.push_back(p);
            }
            cout << "Introduceti numarul de vinuri la sticla: ";;
            in >> nrVinSticla;
            for (int i =0; i < nrVinSticla; i++){
                p = new VinSticla;
                in.get();
                in  >> *p;
                vinSticla.push_back(p);
            }
            cout << "Introduceti numarul de branduri de bere: ";;
            in >> nrBere;
            for (int i =0; i < nrBere; i++){
                p = new Bere;
                in.get();
                in  >> *p;
                bere.push_back(p);
            }
            cout << "Introduceti numarul de branduri de apa: ";;
            in >> nrApa;
            for (int i =0; i < nrApa; i++){
                p = new Apa;
                in.get();
                in  >> *p;
                apa.push_back(p);
            }
        }
    }catch(bad_alloc var){
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    
}
ifstream& operator>>(ifstream& in, Meniu& m){
    m.citire(in);
    return in;
}
void Meniu::afisare(ostream& out){
    if (nrSupe){
        out << "\nSupe:\n";
        Produs * p = new Supa; //upcasting
        for (int i = 0 ; i < nrSupe; i++){
            p = supe[i];
            out << *p;
        }
        out << endl;
    }
    if (nrCiorbe){
        out << "\nCiorbe:\n";
        for (int i = 0 ; i < nrCiorbe; i++){
            out << *ciorbe[i];
        }
        out << endl;
    }
    if (nrPui){
        out << "\nProduse din pui:\n";
        for (int i = 0 ; i < nrPui; i++){
            out << *produsePui[i];
        }
        out << endl;
    }
    if (nrVita){
        out << "\nProduse din vita:\n";
        for (int i = 0 ; i < nrVita; i++){
            out << *produseVita[i];
        }
        out << endl;
    }
    if (nrGarnituri){
        out << "\nGarnituri:\n";
        for (int i = 0 ; i < nrGarnituri; i++){
            out << *garnituri[i];
        }
        out << endl<<endl;
    }
    if (nrDeserturi){
        out << "\nDeserturi:";
        for (int i = 0 ; i < nrDeserturi; i++){
            out << *deserturi[i];
        }
        out << endl;
    }
    if (nrVinPahar){
        out << "\nVinuri la pahar:\n";
        for (int i = 0 ; i < nrVinPahar; i++){
            out << *vinPahar[i];
        }
        out << endl;
    }
    if (nrVinSticla){
        out << "\nVinuri la sticla:\n";
        for (int i = 0 ; i < nrVinSticla; i++){
            out << *vinSticla[i];
        }
        out << endl;
    }
    if (nrBere){
        out << "\nBere:\n";
        for (int i = 0 ; i < nrBere; i++){
            out << *bere[i];
        }
        out << endl;
    }
    if (nrApa){
        out << "\nApa:\n";
        for (int i = 0 ; i < nrApa; i++){
            out << *apa[i];
        }
        out << endl;
    }

    
}
ostream& operator<<(ostream& out, Meniu& m){
    m.afisare(out);
    return out;
}
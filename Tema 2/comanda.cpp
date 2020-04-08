#include "comanda.h"

using namespace std;

Comanda::Comanda(){
    total = 0;
    nrProduse = 0;
}
Comanda::Comanda(Meniu m){
    this->meniu = m;
}
Comanda::Comanda(Meniu meniu, int total, int nrProduse){
    this->meniu = meniu;
    this->nrProduse = 0;
    this->total = 0;
}
Comanda::Comanda(const Comanda& c){
    this->meniu = c.meniu;
    this ->total = c.total;
    this->nrProduse = c.nrProduse;
    for(unsigned int i = 0; i < listaProduse.size(); i++)
            delete listaProduse[i]; 
    for(unsigned int i = 0; i < c.listaProduse.size(); i++)
        listaProduse.push_back(new Produs(*(c.listaProduse[i])));
}
Comanda& Comanda::operator=(const Comanda& c){
    if (this != &c){
        this->meniu = meniu;
        this ->total = c.total;
        this->nrProduse = c.nrProduse;
        for(unsigned int i = 0; i < listaProduse.size(); i++)
            delete listaProduse[i]; 
        for(unsigned int i = 0; i < c.listaProduse.size(); i++)
            listaProduse.push_back(new Produs(*(c.listaProduse[i])));
    }
    return *this;
}
void Comanda::citire(istream& in){
    string optiune;
    cout << "\nDoriti supa sau ciorba?\n";
    getline(in, optiune);
    //Produs* p;
    if (optiune == "Da" || optiune == "da"){
        cout << "Ce sa fie?\n";
        getline(in, optiune);
        if (optiune == "supa" || optiune == "Supa"){
            cout << "\nDe care doriti?\n";
            getline(in, optiune);
            //cout <<" citeste supa\n";
            bool ok = 0;
            for (int i = 0; i< meniu.nrSupe; i++){
                if (meniu.supe[i]->getNumeProdus() == optiune){
                    ok = 1;
                    Supa* p;
                    p = new Supa;
                    listaProduse.push_back(p);
                    //dynamic_cast<Supa*>(listaProduse[nrProduse]);
                    listaProduse[nrProduse] = meniu.supe[i];
                    string nume = meniu.supe[i]->getNumeProdus();
                    listaProduse[nrProduse]->setNumeProdus("supa de " + nume);
                    //cout <<"Atribuie\n";
                    //listaProduse.push_back(dynamic_cast<Produs*>(supe[i]));
                    nrProduse++;
                    delete p;
                }
            }
            if (!ok){
                cout << "Obtiunea nu se afla in meniu\n";
            }
            //nrSupe++;
        }
        if (optiune == "ciorba" || optiune == "Ciorba"){
            cout << "\nDe care doriti?\n";
            getline(in, optiune);
            bool ok = 0;
            for (int i = 0; i< meniu.nrCiorbe; i++){
                if (meniu.ciorbe[i]->getNumeProdus() == optiune){
                    ok = 1;
                    bool smantana, ardei;
                    cout << "Doriti smantana? (0/1) ";
                    in >> smantana;
                    cout << "Doriti ardei? (0/1) ";
                    in >> ardei;
                    in.get();
                    Ciorba* p;
                    p = new Ciorba;
                    *p = *(Ciorba*)meniu.ciorbe[i];
                    p->setArdei(ardei);
                    p->setSmantana(smantana);
                    listaProduse.push_back(new Ciorba);
                    string nume = meniu.ciorbe[i]->getNumeProdus();
                    p->setNumeProdus("ciorba de " + nume);
                    *(Ciorba*)listaProduse[nrProduse] = *p;
                    //cout << *listaProduse[nrProduse];
                    nrProduse++;
                    delete p;
                }
            }
            if (!ok){
                cout << "Obtiunea nu se afla in meniu\n";
            }
            
        }
    }
    cout << "Doriti fel principal?\n";
    getline(in, optiune);
    if (optiune == "da" || optiune == "Da"){
        bool amComandat = 0;
        cout << "Pui sau vita?\n";
        getline(in, optiune);
        if (optiune == "Pui" || optiune == "pui"){
            cout << "Ce sa fie?\n";
            getline(in, optiune);
            bool ok = 0;
            Pui *p = new Pui;
            for (int i = 0; i< meniu.nrPui; i++){
                if (meniu.produsePui[i]->getNumeProdus() == optiune){
                    ok = 1;
                    amComandat = 1;
                    listaProduse.push_back(p);
                    //dynamic_cast<Supa*>(listaProduse[nrProduse]);
                    listaProduse[nrProduse] = meniu.produsePui[i];
                    string nume = meniu.produsePui[i]->getNumeProdus();
                    listaProduse[nrProduse]->setNumeProdus(nume + " de pui");
                    //listaProduse.push_back(dynamic_cast<Produs*>(supe[i]));
                    nrProduse++;
                }
            }
            if (!ok){
                cout << "Obtiunea nu se afla in meniu\n";
            }
            delete p;
        }
        if (optiune == "Vita" || optiune == "vita"){
            cout << "Ce sa fie?\n";
            getline(in, optiune);
            bool ok = 0;
            for (int i = 0; i< meniu.nrVita; i++){
               
                if (meniu.produseVita[i]->getNumeProdus() == optiune){
                    string gradPregatire;
                    cout << "Cum sa fie?\n"; 
                    getline(in, gradPregatire);
                    Vita *p = new Vita;
                    *p = *(Vita*)meniu.produseVita[i];
                    p->setGradPregatire(gradPregatire);
                    //cout << *p;
                    string nume = meniu.produseVita[i]->getNumeProdus();
                    //cout <<"trece de nume\n";
                    p->setNumeProdus(nume + " de vita");
                    //cout << "seteaza numele\n"<<*p;
                    listaProduse.push_back(new Vita);
                    *(Vita*)listaProduse[nrProduse] = *p;
                    delete p;
                    ok = 1;
                    amComandat = 1;
                    nrProduse++;
                }
            }
            if (!ok){
                cout << "Obtiunea nu se afla in meniu\n";
            }
        }
        if (amComandat){
            cout << "Garnitura doriti?\n";
            getline(in, optiune);
            if (optiune == "Da" || optiune == "da"){
                cout << "Ce sa fie?\n";
                //in.get();
                getline(in, optiune);
                bool ok = 0;
                for (int i = 0; i< meniu.nrGarnituri; i++){
                    if (meniu.garnituri[i]->getNumeProdus() == optiune){
                        ok = 1;
                        listaProduse.push_back(new Produs);
                        //dynamic_cast<Supa*>(listaProduse[nrProduse]);
                        *listaProduse[nrProduse] = *meniu.garnituri[i];
                        //listaProduse.push_back(dynamic_cast<Produs*>(supe[i]));
                        nrProduse++;
                    }
                }
                if (!ok){
                    cout << "Obtiunea nu se afla in meniu\n";
                }
            }
        }
    }
    cout << "Vreti desert?\n";
    getline(in, optiune);
    if (optiune == "da" || optiune == "Da"){
        cout << "Ce doriti?\n";
        getline(in, optiune);
        if (optiune == "Tort" || optiune == "tort"){
            bool ok = 0;
            for (int i = 0; i< meniu.nrDeserturi; i++){
                if (meniu.deserturi[i]->getNumeProdus() == optiune){
                    ok = 1;
                    //cout << *meniu.deserturi[i];
                    listaProduse.push_back(new Desert);
                    *listaProduse[nrProduse] = *meniu.deserturi[i];
                    nrProduse++;
                }
            }
            if (!ok){
                cout << "Obtiunea nu se afla in meniu\n";
            }
            
        }
        if(optiune == "Inghetata" || optiune == "inghetata"){
            bool ok = 0;
            for (int i = 0; i< meniu.nrDeserturi; i++){
                if (meniu.deserturi[i]->getNumeProdus() == optiune){
                    ok = 1;
                    Desert* p;
                    p = new Desert;
                    *p = *(Desert*)meniu.deserturi[i];
                    cout << "Cate cupe?\n";
                    int nrCupe;
                    in >> nrCupe;
                    in.get();
                    //cout << "citeste\n";
                    if (nrCupe < p->getNrMinUM() || nrCupe > p->getNrMaxUM()){
                        if (nrCupe < p->getNrMinUM()){
                            cout << "Nu puteti alege mai putin de " << p->getNrMinUM() << " " << p->getUnitateMasura();
                            cout << "\nO sa primiti "<<  p->getNrMinUM() << " " << p->getUnitateMasura()<<endl;
                            p->setCantitate( p->getNrMinUM());
                        }else
                        if (nrCupe > p->getNrMaxUM()){
                            cout << "Nu puteti alege mai putin de " << p->getNrMaxUM() << " " << p->getUnitateMasura() << " ";
                            cout << "\nO sa primiti "<<  p->getNrMaxUM() << " " << p->getUnitateMasura()<<endl;
                            p->setCantitate( p->getNrMaxUM());
                        }
                    }else{
                        //cout << nrCupe;
                        p->setCantitate(nrCupe);
                    }
                    //cout << p->getCantitate()<<endl;
                    listaProduse.push_back(new Desert);
                    *(Desert*)listaProduse[nrProduse] = *p;
                    //cout << "atribuie\n";
                    nrProduse++;
                    delete p;
                }
            }
            if (!ok){
                cout << "Obtiunea nu se afla in meniu\n";
            }
        }
    }

    cout << "De baut va aduc ceva?\n";
    getline(in, optiune);
    if (optiune == "Da" || optiune == "da"){
        cout << "Vin, bere sau apa?\n";
        getline(in, optiune);
        if (optiune == "Vin" || optiune == "vin"){
            cout << "La sticla sau la pahar?\n";
            getline(in, optiune);
            if (optiune == "Pahar" || optiune == "pahar"){
                cout << "Ce brand?\n";
                string brand;
                getline(in, brand);
                cout << "Ce culoare?\n";
                string culoare;
                getline(in, culoare);
                bool gasit = 0;
                for (int i = 0; i < meniu.nrVinPahar; i++){
                    Vin* p = new Vin;
                    *p = *(Vin*) meniu.vinPahar[i];
                    if (p->getCuloare()== culoare && p->getNumeProdus() == brand){
                        gasit = 1;
                        cout << "Cati ml?\n";
                        int cantitate;
                        in >> cantitate;
                        in.get();
                        p->setCantitate(cantitate);
                        p->setNumeProdus("\nVin " + brand);
                        listaProduse.push_back(new Vin);
                        *(Vin*)listaProduse[nrProduse] = *p;
                        nrProduse++;
                    }
                    delete p;
                }
                if (!gasit){
                    cout << "Optiunea nu se afla in meniu\n";
                }

            }
            if (optiune == "Sticla" || optiune == "sticla"){
                cout << "Ce brand?\n";
                string brand;
                getline(in, brand);
                bool gasit = 0;
                for (int i = 0; i < meniu.nrVinSticla; i++){
                    VinSticla* p = new VinSticla;
                    *p = *(VinSticla*) (meniu.vinSticla[i]);
                    //cout << *p;
                    if (p->getBrand() == brand){
                        gasit = 1;
                        //cout << *p;
                        p->setNumeProdus("\nVin " + brand);
                        listaProduse.push_back(new VinSticla);
                        *(VinSticla*)listaProduse[nrProduse] = *p;
                        //cout <<*listaProduse[nrProduse]<<endl;
                        nrProduse++;
                    }
                    delete p;
                }
                if (!gasit){
                    cout << "Optiunea nu se afla in meniu\n";
                }
            }
        }
        if(optiune == "Bere" || optiune == "bere"){
            cout << "Ce brand?\n";
            string brand;
            getline(in, brand);
            bool gasit = 0;
            for (int i = 0; i < meniu.nrBere; i++){
                Bere* p = new Bere;
                *p = *(Bere*) (meniu.bere[i]);
                //cout << *p;
                if (p->getBrand() == brand){
                    gasit = 1;
                    //cout << *p;
                    p->setNumeProdus("\nBere " + brand);
                    listaProduse.push_back(new Bere);
                    *(Bere*)listaProduse[nrProduse] = *p;
                    //cout <<*listaProduse[nrProduse]<<endl;
                    nrProduse++;
                }
                delete p;
            }
            if (!gasit){
                cout << "Optiunea nu se afla in meniu\n";
            }
            
        }
        if(optiune == "Apa" || optiune == "apa"){
            cout << "Ce brand?\n";
            string brand;
            getline(in, brand);
            string aciditate;
            cout << "Plata sau minerala?\n";
            getline(in, aciditate);
            bool gasit = 0;
            for (int i = 0; i < meniu.nrApa; i++){
                Apa* p = new Apa;
                *p = *(Apa*) (meniu.apa[i]);
                //cout << *p;
                if (p->getBrand() == brand && p->getAciditate() == aciditate){
                    gasit = 1;
                    //cout << *p;
                    p->setNumeProdus("/nApa " + brand);
                    //p->setAciditate(aciditate);
                    listaProduse.push_back(new Apa);
                    *(Apa*)listaProduse[nrProduse] = *p;
                    
                    nrProduse++;
                }
                delete p;
            }
            if (!gasit){
                cout << "Optiunea nu se afla in meniu\n";
            }
            
        }
    }
}
istream& operator>>(istream& in, Comanda& c){
    c.citire(in);
    return in;
}
void Comanda::afisare(ostream& out){
    //cout << "dimensiunea listei: "<< listaProduse.size()<<endl;
    for (int i = 0; i< nrProduse; i++){
        out << *listaProduse[i];
    }
}
ostream& operator<<(ostream& out, Comanda& c){
    c.afisare(out);
    return out;
}
void Comanda::calculeazaNota(){
    // cout << "in torala:\n";
    total = 0;
    for (int i = 0; i < nrProduse; i++){
        //cout << *listaProduse[i];
        //cout << "****" << listaProduse[i]->getPret() << "***\n";
        total += listaProduse[i]->getPret();
        //cout << "****" << total<< "***\n";
        //cout << listaProduse[i]->getPret()<<"\n";
    }
    //cout << total;
}

int Comanda::getTotal(){
    return total;
}
void Comanda::setMeniu(Meniu meniu){
    this->meniu = meniu;
}
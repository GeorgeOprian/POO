#include "client.h"


using namespace std;

Client::Client(Meniu meniu){
    this->meniu = meniu;
    this->nrProduse = 0;
    this->totalCosumat = 0;
    this->comandaPreluata = 0;
}
Client::Client(Meniu meniu, int nrProduse, int totalConsumat){
    this->meniu = meniu;
    this->nrProduse = nrProduse;
    this->totalCosumat = totalCosumat;
    this->comandaPreluata = 0;
}
Client::Client(const Client& c){
    this->comanda = c.comanda;
    this->nrProduse = c.nrProduse;
    this->meniu = c.meniu;
    this->totalCosumat = c.totalCosumat;
    this->comandaPreluata = c.comandaPreluata;
}
Client& Client::operator=(const Client& c){
    if (this!=&c){
        this->comanda = c.comanda;
        this->nrProduse = c.nrProduse;
        this->meniu = c.meniu;
        this->totalCosumat = c.totalCosumat;
        this->comandaPreluata = c.comandaPreluata;
    }
    return *this;
}

void Client::preiaComanda(istream& in){
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
                    comanda.push_back(p);
                    //dynamic_cast<Supa*>(comanda[nrProduse]);
                    comanda[nrProduse] = meniu.supe[i];
                    string nume = comanda[nrProduse]->getNumeProdus();
                    comanda[nrProduse]->setNumeProdus("supa de " + nume);
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
                    cout << "Dorti smantana? (0/1) ";
                    in >> smantana;
                    cout << "Dorti ardei? (0/1) ";
                    in >> ardei;
                    in.get();
                    Ciorba* p;
                    p = new Ciorba;
                    p = (Ciorba*)meniu.ciorbe[i];
                    p->setArdei(ardei);
                    p->setSmantana(smantana);
                    comanda.push_back(new Ciorba);
                    string nume = comanda[nrProduse]->getNumeProdus();
                    p->setNumeProdus("ciorba de " + nume);
                    *(Ciorba*)comanda[nrProduse] = *p;
                    //cout << *comanda[nrProduse];
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
                    comanda.push_back(p);
                    //dynamic_cast<Supa*>(comanda[nrProduse]);
                    comanda[nrProduse] = meniu.produsePui[i];
                    string nume = comanda[nrProduse]->getNumeProdus();
                    comanda[nrProduse]->setNumeProdus(nume + " de pui");
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
                    p = (Vita*)meniu.produseVita[i];
                    p->setGradPregatire(gradPregatire);
                    //cout << *p;
                    string nume = meniu.produseVita[nrProduse]->getNumeProdus();
                    //cout <<"trece de nume\n";
                    p->setNumeProdus(nume + " de vita");
                    //cout << "seteaza numele\n"<<*p;
                    comanda.push_back(new Vita);
                    *(Vita*)comanda[nrProduse] = *p;
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
                        comanda.push_back(new Produs);
                        //dynamic_cast<Supa*>(comanda[nrProduse]);
                        *comanda[nrProduse] = *meniu.garnituri[i];
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
                    cout << *meniu.deserturi[i];
                    comanda.push_back(new Desert);
                    *comanda[nrProduse] = *meniu.deserturi[i];
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
                    comanda.push_back(new Desert);
                    *comanda[nrProduse] = *p;
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
                    p = (Vin*) meniu.vinPahar[i];
                    if (p->getCuloare()== culoare && p->getNumeProdus() == brand){
                        gasit = 1;
                        cout << "Cati ml?\n";
                        int cantitate;
                        in >> cantitate;
                        in.get();
                        p->setCantitate(cantitate);
                        p->setNumeProdus("Vin " + brand);
                        comanda.push_back(new Vin);
                        *(Vin*)comanda[nrProduse] = *p;
                        nrProduse++;
                    }
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
                    p = (VinSticla*) (meniu.vinSticla[i]);
                    //cout << *p;
                    if (p->getBrand() == brand){
                        gasit = 1;
                        //cout << *p;
                        p->setNumeProdus("Vin " + brand);
                        comanda.push_back(new VinSticla);
                        *(VinSticla*)comanda[nrProduse] = *p;
                        //cout <<*comanda[nrProduse]<<endl;
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
                p = (Bere*) (meniu.bere[i]);
                //cout << *p;
                if (p->getBrand() == brand){
                    gasit = 1;
                    //cout << *p;
                    p->setNumeProdus("Bere " + brand);
                    comanda.push_back(new Bere);
                    *(Bere*)comanda[nrProduse] = *p;
                    //cout <<*comanda[nrProduse]<<endl;
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
                p = (Apa*) (meniu.apa[i]);
                //cout << *p;
                if (p->getBrand() == brand && p->getAciditate() == aciditate){
                    gasit = 1;
                    //cout << *p;
                    p->setNumeProdus("Apa " + brand);
                    //p->setAciditate(aciditate);
                    comanda.push_back(new Apa);
                    *(Apa*)comanda[nrProduse] = *p;
                    
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
void Client::calculeazaNota(){
    for (int i = 0; i < nrProduse; i++){
        totalCosumat += comanda[i]->getPret();
    }
}
void Client::cheamaChelnerul(istream& in){
    if(!comandaPreluata){
        preiaComanda(in);
        comandaPreluata = 1;
    }else{
        cout << "Doriti sa mai comandati ceva sau dortit nota? (0/1)";
        string optiune;
        getline(in, optiune);
        if(optiune == "0"){
            preiaComanda(in);
        }else{
            calculeazaNota();
            ///gandeste-te cum faci cu masa
        }
    }
}
istream& operator>>(istream& in, Client& c){
    c.preiaComanda(in);
    return in;
}

void Client::afiseazaComanda(ostream& out){
    for (int i = 0; i< nrProduse; i++){
        out << *comanda[i];
    }
}
ostream& operator<<(ostream& out, Client& c){
    c.afiseazaComanda(out);
    return out;
}

int Client::getTotalConsumat(){
    return totalCosumat;
}

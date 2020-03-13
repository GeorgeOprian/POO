#include <iostream>
#include <cstring>
#include "meniu.h"

using namespace std;

Meniu :: Meniu(){
    cout <<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
    cout <<"Aceasta e o baza de date pentru teatre citite de la tastatura.\n";
    cout <<"Introduceti numarul de teatre pe care doriti sa le cititi: ";
    cin >> numar_teatre;
    cin.get();
    vector_teatre = new Teatru[numar_teatre];
    for (int i = 0; i < numar_teatre; i++){
        cin >> vector_teatre[i];
    }
    optiune = 0;
    system("CLS");
}

Meniu :: ~Meniu(){
    delete[] vector_teatre;
}
int Meniu::get_optiune(){
    return optiune;
}
void Meniu::afiseaza_optiuni(){
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "1. Afiseaza Teatrele;\n";
    cout << "2. Adauga un teatru;\n";
    cout << "3. Modificare info teatru;\n";
    cout << "4. Sorteaza Teatrele dupa rating;\n";
    cout << "Orice input >= 5 ==> Iesire.\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
}
void Meniu::citeste_optiunea(){
    cout <<"Introduceti optiunea dorinta: ";
    cin >> optiune;
    cin.get();
    system("CLS");
}
//optiunea 1
void Meniu::afisare_teatre(){
    
    for (int i =0; i < numar_teatre; i++){
        cout <<"\nTeatrul "<<i+1<<":";
        cout<<vector_teatre[i];
    }
}
//optiunea 2
void Meniu::append_vector_teatre(){
    Teatru *vector;
    vector = new Teatru[numar_teatre + 1];
    for (int i =0; i<numar_teatre; i++){
        vector[i] = vector_teatre[i];
    }
    delete[] vector_teatre;
    Teatru t;
    cin >> t;
    vector[numar_teatre] = t;
    numar_teatre++;
    vector_teatre = new Teatru[numar_teatre];
    for (int i =0; i<numar_teatre; i++){
        vector_teatre[i] = vector[i];
    }
    delete[] vector;

}
void Meniu::modifica_echipa_actori(int nr_teatru){
    cout <<"Noul numar de actori: ";
    cin >> vector_teatre[nr_teatru].numar_actori;
    delete[] vector_teatre[nr_teatru].actori;
    vector_teatre[nr_teatru].actori = new Actor[vector_teatre[nr_teatru].numar_actori];
    cout <<"\nNoul vector de actori:\n";
    for(int i =0; i < vector_teatre[nr_teatru].numar_actori; i++){
        cin.get();
        cin>>vector_teatre[nr_teatru].actori[i];
    }
}
void Meniu::adauga_actor(int nr_teatru){
    Actor a;
    Actor *vector;
    int nr_actori = vector_teatre[nr_teatru].numar_actori;
    vector = new Actor[nr_actori + 1];
    for (int i =0; i<nr_actori; i++){
        vector[i] = vector_teatre[nr_teatru].actori[i];
    }
    delete[] vector_teatre[nr_teatru].actori;
    cin.get();
    cin >>a;
    vector[nr_actori] = a;
    nr_actori++;
    vector_teatre[nr_teatru].actori = new Actor[nr_actori];
    for (int i =0; i<nr_actori; i++){
        vector_teatre[nr_teatru].actori[i] = vector[i];
    }
    delete[] vector;
    vector_teatre[nr_teatru].numar_actori++;
}
void Meniu::sterge_actor(int nr_teatru){
    int nr_actori = vector_teatre[nr_teatru].numar_actori;
    if (nr_actori == 0) cout <<"\nTeatrul nu are actori\n";
    else{
        char nume[256];
        int actori_stersi = 0;
        Actor a;
        cout <<"Introduceti numele actorului pe care doriti sa-l stergeti:\n";
        cin.get();
        cin.get(nume, 256);
        Actor *vector;
        bool gasit = 0;
        int poz = 0;
        vector = new Actor[nr_actori - 1];
        for (int i =0; i <nr_actori; i++){

            if (strcmp(vector_teatre[nr_teatru].actori[i].nume_actor, nume) == 0 && gasit == 0){
                gasit = 1;
            }
            else{
                vector[poz] = vector_teatre[nr_teatru].actori[i];
                poz++;
            }
        }
        if (!gasit) cout <<"Actorul nu a fost gasti in teatru\n";
        else{
            nr_actori--;
            vector_teatre[nr_teatru].numar_actori--;
            delete[] vector_teatre[nr_teatru].actori;
            vector_teatre[nr_teatru].actori = new Actor[nr_actori];
            for (int i = 0; i<nr_actori; i++){
                vector_teatre[nr_teatru].actori[i] = vector[i];
            }
        }
        delete[] vector;
    }
}
void Meniu::modifica_actori(int nr_teatru){
    bool modifica = 1;
    int optiune;
    while(modifica){
        cout <<"\n1. Modifica toata echipa de actori;";
        cout <<"\n2. Adauga actor;";
        cout <<"\n3. Sterge actor;";
        cout << "\nOrice input >= 4 ==> Iesire.\n";
        cout << "\nIntroduceti optiunea: ";
        cin >> optiune;
        
        switch(optiune){
            case 1:
                modifica_echipa_actori(nr_teatru);
                
                break;
            case 2:
                adauga_actor(nr_teatru);;
                break; 
            case 3:

                sterge_actor(nr_teatru);
                break;
            default:
                modifica = 0;
                break;
        }
        system("CLS");
        if (modifica) cout <<vector_teatre[nr_teatru];
        
    }
    cin.get();
}

void Meniu::modificare_info_teatru(){
    afisare_teatre();
    cout <<"\nIntroduceti numarul teatrului pe care vreti sa-l modificati: ";
    int nr_teatru;
    cin>>nr_teatru;
    while (nr_teatru < 1 || nr_teatru > numar_teatre){
        cout <<"Nu exista teatru cu numarul "<<nr_teatru<<endl;
        cout <<"Introduceti un numar valid: ";
        cin>>nr_teatru;
    }
    system("CLS");
    nr_teatru--;
    int modifica = true;
    int optiune_modifica;
    char *nume;
    int r;
    while (modifica){
        cout << vector_teatre[nr_teatru];
        cout << "\n1. Modfica numele;";
        cout << "\n2. Modfica denumire piesa;";
        cout << "\n3. Modfica actori;";
        cout << "\n4. Modfica rating;";
        cout << "\nOrice input >= 5 ==> Iesire.\n";
        cout << "\nIntroduceti optiunea: ";
        cin>>optiune_modifica;
        
        nume = new char [256];
        switch (optiune_modifica)
        {
        case 1:
            cout <<"Noul nume ala teatrului: ";
            cin.get();
            cin.get(nume, 255);
            vector_teatre[nr_teatru].setNume_teatru(nume);
            delete[] nume;
            break;
        case 2:
            cout <<"Noua denumire a piesei: ";
            cin.get();
            cin.get(nume, 255);
            vector_teatre[nr_teatru].setDenumire_piesa(nume);
            delete[]nume;
            break;
        case 3:
            system("CLS");
            cout << vector_teatre[nr_teatru];
            this->modifica_actori(nr_teatru);
            break;
        case 4:
            cout <<"Noul rating: ";
            cin >> r;
            vector_teatre[nr_teatru].setRating(r);
            break;
        default:
            modifica = 0;
            break;
        }
        system("CLS");
        
    }

}
void Meniu::sorteaza_teatre(){
    bool ok =0;
    while (!ok){
        ok = 1;
        for (int i = 0; i< numar_teatre - 1; i++)
            if (vector_teatre[i].rating < vector_teatre[i+1].rating){
                Teatru aux;
                aux = vector_teatre[i];
                vector_teatre[i] = vector_teatre[i + 1];
                vector_teatre[i + 1] = aux;
                ok = 0;
            }
    }
}
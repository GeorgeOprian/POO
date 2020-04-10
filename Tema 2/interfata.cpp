#include "interfata.h"

using namespace std;

Interfata::Interfata(){
    restaurantCitit = 0;
    optiune = 0;
    ifstream f("input.in");
    Meniu meniu;
    f>>meniu;
    restaurant.setMeniu(meniu);
}
Interfata::Interfata(const Interfata& i){
    this->restaurant = i.restaurant;
    this->restaurantCitit = i.restaurantCitit;
    this->optiune = i.optiune;
}
Interfata& Interfata::operator=(const Interfata& i){
    if (this != & i){
        this->restaurant = i.restaurant;
        this->restaurantCitit = i.restaurantCitit;
    }
    return *this;
}
void Interfata::afiseaza_optiuni(){
    cout << "%\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "1. Citeste restaurantul;\n";
    cout << "2. Afisare informatii mese;\n";
    cout << "3. Afisare meniu;\n";
    cout << "4. Adauga clienti in restaurant;\n";
    cout << "5. Interactioneaza cu o masa;\n";
    cout << "6. Afiseaza numarul de clienti din restaurant;\n";
    cout << "Orice input >= 7 ==> Iesire.\n";
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
}
void Interfata::citeste_optiunea(){
    cout <<"Introduceti optiunea dorinta: ";
    cin >> optiune;
    cin.get();
    system("clear");
}

void Interfata::afisareMeniu(){
    restaurant.afisareMeniu();
}

void Interfata::citireRestaurant(istream& in){
    if (!restaurantCitit){
        in >> restaurant;
        restaurantCitit = 1;
    }else{
        cout << "Ati citit deja restaurantul.\n";
    }
}
istream& operator>>(istream& in, Interfata& i){
    i.citireRestaurant(in);
    return in;
}
void Interfata::afisareRestaurant(ostream& out){
    if (!restaurantCitit){
        cout << "Nu a fost citit nicio masa.\n";
        return;
    }
    out << restaurant;
}
ostream& operator<<(ostream& out, Interfata& i){
    i.afisareRestaurant(out);
    return out;
}
void Interfata::interactiune(){
    if (restaurant.getNrMese() == 0) cout << "Nu a fost citit restaurantul\n";
    else{
        if(restaurant.getNrClienti()){
            cout << "Alegeti masa cu care vreti sa interactionati:\n";
            for(int i = 0; i < restaurant.getNrMese(); i++){
                cout << "Masa " << i + 1 << " -> " << restaurant.getNrClientiMasa(i) << " clienti.\n";
            }
            int nrMasa;
            cout << "Introduceti numarul mesei: ";
            cin >> nrMasa;
            if (nrMasa > restaurant.getNrMese()) cout << "Nu exista masa " << nrMasa << " in restaurant\n";
            else{
                restaurant.interactiune(nrMasa - 1);
            }
        }else{
            cout << "Nu sunt clienit la mese.\n";
        }
    }
}
void Interfata::sosescClienti(){
    cout << "Introduceti un numar de clienti care ajung in restaurant: ";
    int n;
    cin >> n;
    cin.get();
    if (n < 0) cout << "Numarul de clienti trebuie sa fie mai mare decat 0\n";
    else 
        if(!restaurant.cautaMasa(n)){
            cout << "Nu avem o masa suficient de mare pentru " << n << " clienti\n";
        }else{
            restaurant.setNrClienti(restaurant.getNrClienti() + n);
        }
}
void Interfata::afiseazaNumarClientiRestaurant(){
    Client::numarClienitIntratiInRestaurant();
}

int Interfata::get_optiune(){
    return optiune;
}
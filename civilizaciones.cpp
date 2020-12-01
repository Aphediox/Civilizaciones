#include "civilizaciones.h"

civilizacion::civilizacion(){
    nombre = " ";
    x = 0;
    y = 0;
    puntuacion = 0;
}
civilizacion::civilizacion(string nombre, float x, float y, unsigned int punt){
    this->nombre = nombre;
    this ->x = x;
    this->y = y;
    this->puntuacion = punt;
}

void civilizacion::setNombre(string nombre){
    this->nombre = nombre;
}
void civilizacion::setX(float x){
    this->x = x;
}
void civilizacion::setY(float y){
    this->y = y;
}
void civilizacion::setPunt(unsigned int punt){
    this->puntuacion = punt;
}
string civilizacion::getNombre(){return nombre;}
float civilizacion::getX(){return x;}
float civilizacion::getY(){return y;}
unsigned int civilizacion::getPunt(){return puntuacion;}

void civilizacion::agregarAP(const Aldeano &a){
    L1.push_front(a);
    puntuacion += 100;
}

void civilizacion::agregarAF(const Aldeano &a){
    L1.push_back(a);
    puntuacion += 100;
    
}

void civilizacion::eliminarA(string nombre){
    auto it = find_if(L1.begin(), L1.end(),[nombre](Aldeano a){return a.getNom() == nombre;});
    if(it == L1.end()){
        cout << "No se encontro el aldeano." << endl;
        cout << endl;
    }
    else{
        L1.erase(it);
    }
    
}
void civilizacion::eliminarA(int salu){
    for(auto it2 = L1.begin(); it2 != L1.end(); it2++){
        auto it = find_if(L1.begin(), L1.end(),[salu](Aldeano a){return a.getSal() < salu;});
        if(it != L1.end()){
            L1.erase(it);    
        }   
    }
    
}
void civilizacion::eliminar3(int e){
    for(auto it2 = L1.begin(); it2 != L1.end(); it2++){
        auto it = find_if(L1.begin(), L1.end(),[e](Aldeano a){return a.getEdad() >= e;});
        if(it != L1.end()){
            L1.erase(it);    
        }   
    }
}
    
void civilizacion::ordenarnom(){
    L1.sort([](Aldeano a, Aldeano b){ return a.getNom() < b.getNom();});
}

void civilizacion::ordenareda(){
    L1.sort([](Aldeano a, Aldeano b){ return a.getEdad() > b.getEdad();});
}

void civilizacion::ordenasal(){
    L1.sort([](Aldeano a, Aldeano b){ return a.getSal() > b.getSal();});
}

Aldeano* civilizacion::buscar(string nombre){
    auto it = find_if(L1.begin(), L1.end(), [nombre](Aldeano a){return a.getNom() == nombre;});
    if(it == L1.end()){
        return nullptr;

    }else{
        return &(*it);
    }
}

void civilizacion::resum(){
    cout << "============================================================" << endl;
    cout << left << setw(18) << "Nombre";
    cout << setw(15) << "Edad";
    cout << setw(17) << "Genero";
    cout << setw(15) << "Salud" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (auto it = L1.begin(); it != L1.end(); it++)
    {
       cout << *it;
    }
    cout << "============================================================" << endl;
    cout << endl;
}

void civilizacion::Backup(){
    ofstream archivo;
        archivo.open(getNombre() + ".txt");
    for(auto it = L1.begin(); it != L1.end(); it ++){
        archivo << it->getNom() << endl;
        archivo << it->getEdad() << endl;
        archivo << it->getGen() << endl;
        archivo << it->getSal() << endl;
    }
    archivo.close();
}
void civilizacion::Recovery(){
    ifstream archivo(nombre +".txt");
    string n;
    unsigned int i;
    int num;
    if(archivo.is_open()){
        while (true)
        {
            Aldeano *a = new Aldeano;
            getline(archivo, n);
            if(archivo.eof()){
                break;
            }
            a->setNombre(n);

            getline(archivo, n);
            i = stoi(n);
            a->setEdad(i);

            getline(archivo, n);
            a->setGenero(n);

            getline(archivo, n);
            num = stoi(n);
            a->setSalud(num);
            L1.push_back(*a);
        }
    }archivo.close();
}
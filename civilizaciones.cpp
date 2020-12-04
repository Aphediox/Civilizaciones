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
    L1.remove_if([salu](Aldeano a){return a.getSal() < salu;});
    
}
void civilizacion::eliminar3(int e){
    L1.remove_if([e](Aldeano a){return a.getEdad() >= e;});
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
    Aldeano a;
    string n;
    unsigned int i;
    int num;
    if(archivo.is_open()){
        while (true)
        {
            getline(archivo, n);
            if(archivo.eof()){
                break;
            }
            a.setNombre(n);

            getline(archivo, n);
            i = stoi(n);
            a.setEdad(i);

            getline(archivo, n);
            a.setGenero(n);

            getline(archivo, n);
            num = stoi(n);
            a.setSalud(num);
            L1.push_back(a);
        }
    }archivo.close();
}

void civilizacion::resB(){
    cout << "============================================================" << endl;
    cout << left << setw(10) << "ID";
    cout << setw(13) << "Combustible";
    cout << setw(10) << "Velocidad";
    cout << setw(10) << "Armadura";
    cout << setw(10) << "Cantidad de Guerreros" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (auto it = B.begin(); it != B.end(); it++)
    {
       cout << *(*it);
    }
    cout << "============================================================" << endl;
    cout << endl;
}

Barco* civilizacion::buscarB(const int &id){
    auto it = find_if(B.begin(), B.end(), [id](Barco *b){return b->getID() == id;});
    if(it == B.end()){
        return nullptr;
    }else{
        return *it;
    }
}
void civilizacion::eliminarB(int id){
    auto it = find_if(B.begin(), B.end(), [id](Barco *b){return b->getID() == id;});
    if(it == B.end()){
        cout << "No se encontro el ID" << endl;
    }else{
        B.erase(it);
        Barco *b = *it;
        free(b);
    }
    
}

void civilizacion::eliminarBc(float c){
    for(size_t t = 0; t < tamB(); t++ ){
    auto it = find_if(B.begin(), B.end(), [c](Barco *b){return b->getComb() < c;});
    if(it != B.end()){
        B.erase(it);
        free(*it);
    }
    }
}
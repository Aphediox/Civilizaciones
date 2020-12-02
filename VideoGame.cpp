#include "VideoGame.h"
#include <algorithm>

videogame::videogame(){

}

void videogame::setUser(string &user){
    this->usuario = user;
}

string videogame::getUser(){
    return usuario;
}
void videogame::agregar_civ(const civilizacion &c){
    C1.push_back(c);
}

void videogame::insertar(const civilizacion &c, size_t &p){
    C1.insert(C1.begin()+p, c);
}
void videogame::crear_civ(size_t &n, const civilizacion &c){
    C1 = vector<civilizacion>(n, c);
}
civilizacion videogame::primer_civ(){
    return C1.front();
}
civilizacion videogame::ultima_civ(){
    return C1.back();
}

void videogame::resumen(){
    cout << "============================================================" << endl;
    cout << left << setw(18) << "Nombre";
    cout << setw(15) << "Posicion X";
    cout << setw(17) << "Posicion Y";
    cout << setw(15) << "Puntuacion" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (size_t i = 0; i < C1.size(); i++)
    {
        civilizacion &c = C1[i];
        cout << c << endl;
    }
    cout << "============================================================" << endl;
    cout << endl;
}
void videogame::ordenarNombre(){
    sort(C1.begin(), C1.end(), [](civilizacion c, civilizacion c2){return c.getNombre() < c2.getNombre();});
}
void videogame::ordenarX(){
    sort(C1.begin(), C1.end(), [](civilizacion c, civilizacion c2){return c.getX() < c2.getX();});
}
void videogame::ordenarY(){
    sort(C1.begin(), C1.end(), [](civilizacion c, civilizacion c2){return c.getY() < c2.getY();});
}
void videogame::ordenarPunt(){
    sort(C1.begin(), C1.end(), [](civilizacion c, civilizacion c2){return c.getPunt() < c2.getPunt();});
}
void videogame::eliminar(string &nombr){
    for (size_t i = 0; i < C1.size(); i++)
    {
        civilizacion &c = C1[i];
        if(c.getNombre() == nombr){
            C1.erase(C1.begin()+i);
            cout << "Civilizacion eliminada con exito." << endl;
            break;
        }else{
            cout << "Nombre no encontrado" << endl;
        }
    }
    
}
civilizacion* videogame::buscar(string nombr){
    auto it = find_if(C1.begin(), C1.end(),[nombr](civilizacion c){return c.getNombre() == nombr;});
    if(it == C1.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}

 void videogame::backup(){
     ofstream archivo;
     archivo.open("Civilizaciones.txt");
     for(auto it = C1.begin(); it != C1.end(); it ++){
         archivo << it->getNombre()<<endl;
         archivo << it->getX()<<endl;
         archivo << it->getY()<<endl;
         archivo << it->getPunt()<<endl;
         it->Backup();
     }
     archivo.close();
 }
 
 void videogame::recovery(){
     ifstream archivo("Civilizaciones.txt");
     string aux;
     float f;
     unsigned int i;
     if(archivo.is_open()){
         while(true){
             civilizacion *Z = new civilizacion;
             getline(archivo, aux);
             if (archivo.eof())
             {
                 break;
             }
             
             Z->setNombre(aux);

             getline(archivo, aux);
             f = stof(aux);
             Z->setX(f);

             getline(archivo, aux);
             f = stof(aux);
             Z->setY(f);

             getline(archivo, aux);
             i = stoi(aux);
             Z->setPunt(i);

             Z->Recovery();
             
             C1.push_back(*Z);
         }
     }
     archivo.close();
 }
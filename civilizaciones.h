#ifndef CIVILIZACIONES_H
#define CIVILIZACIONES_H
#include <iostream>
#include "Aldeano.h"
#include "Barco.h"
#include <iomanip>
#include <list>
#include <algorithm>
#include <fstream>
using namespace std;

class civilizacion {
    private:
    string nombre;
    float x;
    float y;
    unsigned int puntuacion;
    list<Aldeano> L1;
    list<Barco*> B;

    public:
    civilizacion();
    civilizacion(string nombre, float x, float y, unsigned int punt);
    void setNombre(string nombre);
    void setX(float x);
    void setY(float y);
    void setPunt(unsigned int punt);

    string getNombre();
    float getX();
    float getY();
    unsigned int getPunt();

    void agregarAP(const Aldeano &a);
    void agregarAF(const Aldeano &a);
    void eliminarA(string nombre);
    void eliminarA(int salu);
    void eliminar3(int e);
    void ordenarnom();
    void ordenareda();
    void ordenasal();
    Aldeano* buscar(string nombre);
    void resum();
    void Backup();
    void Recovery();

    void AgregarB(Barco *b){B.push_back(b);};
    void resB();
    Barco* buscarB(const int &id);
    void eliminarB(int id);
    void eliminarBc(float com);
    size_t tam(){return L1.size();}
    size_t tamB(){return B.size();}

    friend istream& operator>> (istream &in, civilizacion &c){
        cout << "Nombre: ";
        getline(cin, c.nombre);
        cout << "Posicion X: ";
        cin >> c.x; cin.ignore();
        cout << "Posicion y: ";
        cin >> c.y; cin.ignore();
        cout << "Puntuacion: ";
        cin >> c.puntuacion; cin.ignore();
        return in;
    }
     friend ostream& operator<< (ostream &out, civilizacion &c){
        out << left << setw(21) << c.nombre;
        out << setw(16) << c.x ;
        out << setw(17) << c.y ;
        out << setw(15) << c.puntuacion << endl;
        
        return out;
    }
    friend ostream& operator<< (ostream &out, const civilizacion &c){
        out << left << setw(21) << c.nombre;
        out << setw(16) << c.x ;
        out << setw(17) << c.y ;
        out << setw(15) << c.puntuacion << endl;
        
        return out;
    }

};


#endif
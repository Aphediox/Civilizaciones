#ifndef CIVILIZACIONES_H
#define CIVILIZACIONES_H
#include <iostream>
using namespace std;
#include <iomanip>
class civilizacion{
    private:
    string nombre;
    float x;
    float y;
    unsigned int puntuacion;

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
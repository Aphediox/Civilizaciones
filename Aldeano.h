#ifndef ALDEANO_H
#define ALDEANO_H
#include <iostream>
#include <iomanip>
using namespace std;



class Aldeano{
    private:
    string nombre;
    unsigned int edad;
    string genero;
    int salud;  

    public:
    
    void setNombre(string n){this->nombre = n;}
    void setEdad(int e){this->edad = e;}
    void setGenero(string g){this->genero = g;}
    void setSalud(int s){this->salud = s;}
    string getNom(){return nombre;}
    unsigned int getEdad(){return edad;}
    string getGen(){return genero;}
    int getSal(){return salud;}

    friend istream& operator>> (istream &in, Aldeano &a){
        cout << "Nombre: ";
        getline(cin, a.nombre);
        cout << "Edad: ";
        cin >> a.edad; cin.ignore();
        cout << "Genero: ";
        getline(cin, a.genero);
        cout << "Salud: ";
        cin >> a.salud; cin.ignore();
        return in;
    }
    friend ostream& operator<< (ostream &out, Aldeano &a){
        out << left << setw(21) << a.nombre;
        out << setw(16) << a.edad ;
        out << setw(17) << a.genero ;
        out << setw(15) << a.salud << endl;
        return out;
    }
};


#endif
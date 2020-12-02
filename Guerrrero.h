#ifndef GUERRERO_H
#define GUERRERO_H
#include <iostream>
#include <iomanip>
using namespace std;
class Guerrero{

    private:

    int ID;
    int salud;
    float fuerza;
    float escudo;
    string tipo;

    public:
    void setID(int i){this->ID = i;}
    void setSalud(int sal){this->salud = sal;}
    void setFuerza(float f){this->fuerza = f;}
    void setEscudo(float f){this->escudo = f;}
    void setTipo(string t){this->tipo = t;}

    int getID(){return ID;}
    int getSalud(){return salud;}
    float getFuerza(){return fuerza;}
    float getEscudo(){return escudo;}
    string getTipo(){return tipo;}
    
    friend ostream& operator<< (ostream &out, Guerrero g){
        out << left << setw(10) << g.ID;
        out << setw(10) << g.tipo;
        out << setw(10) << g.salud;
        out << setw(10) << g.fuerza;
        out << setw(10) << g.escudo << endl;
        return out;
    }

};

#endif
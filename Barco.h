#ifndef BARCO_H
#define BARCO_H
#include "Guerrrero.h"
#include <stack>

class Barco{
    private:
    int ID;
    float combustible;
    float velocidad;
    float armadura;
    stack<Guerrero> G;

    public:
    Barco(){this->velocidad = 0.0; this->armadura = 100.00;}
    void setID(int id){this->ID = id;}
    void setCombus(float com){this->combustible = com;}
    void setVel(float vel){this->velocidad = vel;}
    void setArm(float arm){this->armadura = arm;}

    int getID(){return ID;}
    float getComb(){return combustible;}
    float getVel(){return velocidad;}
    float getArm(){return armadura;}

    void agregarG(Guerrero &g){G.push(g);}
    void eliminarG(){G.pop();}
    void resumG(){
        cout << "============================================================" << endl;
        cout << left << setw(10) << "ID";
        cout << setw(10) << "Tipo";
        cout << setw(10) << "Salud";
        cout << setw(10) << "Fuerza";
        cout << setw(10) << "Escudo" << endl;
        cout << "------------------------------------------------------------" << endl;
        stack<Guerrero> aux = G;
        for(size_t t = 0; t < tam(); t++){
            cout << aux.top();
            aux.pop();
        }
        cout << "============================================================" << endl;
    }
    Guerrero tope(){return G.top();}

    size_t tam(){return G.size();}

    friend ostream& operator<< (ostream &out, Barco &a){
        out << left << setw(10) << a.ID;
        out << setw(13) << a.combustible;
        out << setw(10) << a.velocidad;
        out << setw(10) << a.armadura;
        out << setw(10) << a.tam() << endl;
        return out;
    }
};

#endif
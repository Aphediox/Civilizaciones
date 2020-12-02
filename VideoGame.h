#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "civilizaciones.h"
#include <vector>

class videogame {
    private:
    string usuario;
    vector<civilizacion> C1;

    public:
    videogame();
    
    void setUser(string &user);
    string getUser();
    void agregar_civ(const civilizacion &c);
    void insertar(const civilizacion &c, size_t &p);
    void resumen();
    void crear_civ(size_t &n, const civilizacion &c);
    civilizacion primer_civ();
    civilizacion ultima_civ();
    void ordenarNombre();
    void ordenarX();
    void ordenarY();
    void ordenarPunt();
    void eliminar(string &nombr);
    civilizacion* buscar(string nombr);
    void backup();
    void recovery();
    size_t Total(){
        return C1.size();
    }


    
};

#endif
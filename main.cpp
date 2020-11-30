#include "VideoGame.h"

int main(int argc, char const *argv[])
{
    videogame c1;
    while(true){
        cout << "1) Nombre de usuario" << endl;
        cout << "2) Agregar civilizacion" << endl;
        cout << "3) Insertar civilizacion" << endl;
        cout << "4) Crear civilizaciones" << endl;
        cout << "5) Primera civilizacion" << endl;
        cout << "6) Ultima civilizacion" << endl;
        cout << "7) Ordenar" << endl;
        cout << "8) Eliminar" << endl;
        cout << "9) Buscar" << endl;
        cout << "10) Modificar" << endl;
        cout << "11) Resumen" << endl;
        cout << "0) Salir" << endl;
        string op;
        getline(cin, op);
        if(op == "1"){
            string aux;
            cout << "Nombre de usuario: ";
            getline(cin, aux);
            c1.setUser(aux);       
        }
        if(op == "2"){
            civilizacion aux;
            cin >> aux;
            c1.agregar_civ(aux);
        }
        if(op == "3"){
            size_t a;
            civilizacion aux;
            cin >> aux;
            cout << "Posicion: ";
            cin >> a; cin.ignore();
            if (a >= c1.Total())
            {
                cout << "Posicion no valida" << endl;
            }
            else{
                c1.insertar(aux, a);
            }
        }
        if(op == "4"){
            civilizacion aux;
            size_t n;
            cout << "Numero de civilizaciones:  ";
            cin >> n; cin.ignore();
            cin >> aux;
            c1.crear_civ(n, aux);
        }
        if(op == "5"){
            if (c1.Total() == 0)
            {
                cout << "Vector vacio." << endl;
            }
            else{
                cout << c1.primer_civ();
            }
        }
        if(op == "6"){
            if (c1.Total() == 0)
            {
                cout << "Vector vacio." << endl;
            }
            else{
                cout << c1.ultima_civ();
            }
        }
        if(op == "7"){
            if(c1.Total() == 0){
                cout << "Vector vacio, no hay nada que ordenar" << endl;
            }
            else{
                while (true)
                {
                    cout << "1) Ordenar por nombre" << endl;
                    cout << "2) Ordenar por posicion X" << endl;
                    cout << "3) Ordenar por posicion Y" << endl;
                    cout << "4) Ordenar por puntuacion" << endl;
                    cout << "0) Salir" << endl;
                    string op;
                    getline(cin, op);
                    if(op == "1"){
                        c1.ordenarNombre();
                    }
                    if(op == "2"){
                        c1.ordenarX();
                    }
                    if(op == "3"){
                        c1.ordenarY();
                    }
                    if(op == "4"){
                        c1.ordenarPunt();
                    }
                    if (op == "0")
                    {
                        break;
                    }
                }    
            }      
        }
        if(op == "8"){
            if(c1.Total() == 0){
                cout << "Vector vacio, no puedes eliminar nada" << endl;
            }else{
                string aux;
                cout << "Nombre de la civilizacion: " ;
                getline(cin, aux);
                c1.eliminar(aux);
            }
        }
        if(op == "9"){
            if(c1.Total() == 0){
                cout << "Vector vacio, no puedes buscar nada" << endl;
            }else{
            string aux;
            cout << "Nombre de la civilizacion: ";
            getline(cin, aux);
            civilizacion *au = c1.buscar(aux);
            if(au == nullptr){
                cout << "La civilizacion no se encontro" << endl;
            }else{
                cout << left << setw(18) << "Nombre";
                cout << setw(15) << "Posicion X";
                cout << setw(17) << "Posicion Y";
                cout << setw(15) << "Puntuacion" << endl;
                cout << *au << endl;
            }}
            
        }
        if(op == "10"){
            if(c1.Total() == 0){
                cout << "Vector vacio, no puedes modificar nada" << endl;
            }else{
            string aux;
            cout << "Nombre de la civilizacion: ";
            getline(cin, aux);
            civilizacion *au = c1.buscar(aux);
            if(au == nullptr){
                cout << "La civilizacion no se encontro" << endl;
            }else{
                while (true)
                {
                    cout << left << setw(18) << "Nombre";
                    cout << setw(15) << "Posicion X";
                    cout << setw(17) << "Posicion Y";
                    cout << setw(15) << "Puntuacion" << endl;
                    cout << *au << endl;
                    cout << "1) Modificar nombre." << endl;
                    cout << "2) Modificar posicion X" << endl;
                    cout << "3) Modificar posicion Y" << endl;
                    cout << "4) Modificar puntuacion" << endl;
                    cout << "0) Salir" << endl;
                    string op;
                    getline(cin, op);
                    if(op == "1"){
                        string aux;
                        cout << "Nuevo nombre: ";
                        getline(cin, aux);
                        au->setNombre(aux);
                    }
                    if(op == "2"){
                        float x;
                        cout << "Nueva posicion X: ";
                        cin >> x; cin.ignore();
                        au->setX(x);
                    }
                    if(op == "3"){
                        float y;
                        cout << "Nueva posicion y: ";
                        cin >> y; cin.ignore();
                        au->setY(y);
                    }
                    if(op == "4"){
                        unsigned int p;
                        cout << "Nueva posicion X: ";
                        cin >> p; cin.ignore();
                        au->setPunt(p);
                    }
                    if (op == "0")
                    {
                        break;
                    }
                }
            }
        }}
        if(op == "11"){
            if(c1.Total() == 0){
                cout << "Vector vacio." << endl;
            }
            else{
                c1.resumen();
            }
        }
        if(op == "0"){
            break;
        }

    }
    
}

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
        cout << "12) Backup " << endl;
        cout << "13) Recovery " << endl;
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
                    while(true){
                        cout << "============================================================" << endl;    
                        cout << left << setw(18) << "Nombre";
                        cout << setw(15) << "Posicion X";
                        cout << setw(17) << "Posicion Y";
                        cout << setw(15) << "Puntuacion" << endl;
                        cout << "------------------------------------------------------------" << endl;
                        cout << *au << endl;
                        cout << "============================================================" << endl;
                        cout << "1) Menu Aldeanos" << endl;
                        cout << "2) Menu Barcos" << endl;
                        cout << "0) Salir "<<endl;
                        string oo;
                        getline(cin, oo);
                        if(oo == "1"){
                            while(true){
                                
                            cout << "============================================================" << endl;    
                            cout << left << setw(18) << "Nombre";
                            cout << setw(15) << "Posicion X";
                            cout << setw(17) << "Posicion Y";
                            cout << setw(15) << "Puntuacion" << endl;
                            cout << "------------------------------------------------------------" << endl;
                            cout << *au << endl;
                            cout << "============================================================" << endl;
                            cout << "1) Agregar aldeano." << endl;
                            cout << "2) Eliminar aldeano." << endl;
                            cout << "3) Clasificar aldeanos." << endl;
                            cout << "4) Buscar aldeano." << endl;
                            cout << "5) Modificar aldeano." << endl;
                            cout << "6) Mostrar aldeanos." << endl;
                            cout << "0) Salir." << endl;
                            string op2;
                            getline(cin, op2);
                    
                            if(op2 == "1"){
                                Aldeano a;
                                cin >> a;
                                while (true)
                                {
                                    cout << "1) Agregar objeto aldeano al principio" << endl;
                                    cout << "2) Agregar objeto aldeano al final" << endl;
                                    string op3;
                                    getline(cin, op3);
                                    if(op3=="1"){
                                        au->agregarAP(a);
                                        break;
                                    }
                                    if(op3 == "2"){
                                        au->agregarAF(a);
                                        break;
                                    }
                                }   
                            }
                                    if(op2 == "2"){
                                        if(au->tam() > 0){
                                            while (true)
                                            {
                                                cout << "1) Eliminar por nombre" << endl;
                                                cout << "2) Eliminar por salud < x" << endl;
                                                cout << "3) Eliminar donde su edad >= 60 " << endl;
                                                cout << "0) Salir " << endl;
                                                string selec;
                                                getline(cin, selec);
                                                if(selec == "1"){
                                                    string nom;
                                                    cout << "Nombre del Aldeano: ";
                                                    getline(cin, nom);
                                                    au->eliminarA(nom);
                                                }
                                                if(selec == "2"){
                                                    int salu;
                                                    cout << "Salud menor a: " ;
                                                    cin >> salu; cin.ignore();
                                                    au->eliminarA(salu);
                                                }
                                                if(selec == "3"){
                                                    au->eliminar3(60);
                                                }
                                                if(selec == "0"){
                                                    break;
                                                }
                                            }
                                        }else{
                                            cout << "Lista vacia, no hay nada que eliminar." << endl;
                                            cout << endl;
                                        }
                                    }
                                    if(op2 == "3"){
                                        if(au->tam() > 0){
                                        {
                                            cout << "1) Clasificar la lista de aldeanos por nombre (ascendente)." << endl;
                                            cout << "2) Clasificar la lista de aldeanos por edad (descendente)." << endl;
                                            cout << "3) Ordenar la lista de aldeanos por salud (descendente)." << endl;
                                            string oc;
                                            getline(cin, oc);
                                            if(oc == "1"){
                                                au->ordenarnom();
                                            }
                                            if(oc == "2"){
                                                au->ordenareda();
                                            }
                                            if(oc == "3"){
                                                au->ordenasal();
                                            }
                                            }
                                        }
                                        else{
                                            cout << "Lista vacia, no hay nada por ordenar." << endl;
                                            cout << endl;
                                        }
                                    }
                                    if(op2 == "4"){
                                        if(au->tam() > 0){
                                            string aus;
                                            cout << "Nombre del Aldeano : ";
                                            getline(cin, aus);
                                            
                                            Aldeano* x = au->buscar(aus);
                                            if( x == nullptr){
                                                cout << "Aldeano no encontrado." << endl;
                                            }else{
                                                cout << "============================================================" << endl;
                                                cout << left << setw(18) << "Nombre";
                                                cout << setw(15) << "Edad";
                                                cout << setw(17) << "Genero";
                                                cout << setw(15) << "Salud" << endl;
                                                cout << "------------------------------------------------------------" << endl;
                                                cout << *x;
                                                cout << "============================================================" << endl;
                                                cout << endl;
                                            }
                                            
                                        }else{
                                            cout << "Lista vacia, no puedes buscar." << endl;
                                            cout << endl;
                                        }
                                    }
                                    if(op2 == "5"){
                                        if(au->tam() > 0){
                                            string aus;
                                            cout << "Nombre del Aldeano : ";
                                            getline(cin, aus);
                                            
                                            Aldeano* x = au->buscar(aus);
                                            if( x == nullptr){
                                                cout << "Aldeano no encontrado." << endl;
                                            }else{
                                                while(true){
                                                cout << "============================================================" << endl;
                                                cout << left << setw(18) << "Nombre";
                                                cout << setw(15) << "Edad";
                                                cout << setw(17) << "Genero";
                                                cout << setw(15) << "Salud" << endl;
                                                cout << "------------------------------------------------------------" << endl;
                                                cout << *x;
                                                cout << "============================================================" << endl;
                                                cout << endl;
                                                cout << "1) Modificar nombre " << endl;
                                                cout << "2) Modificar edad " << endl;
                                                cout << "3) Modificar genero " << endl;
                                                cout << "4) Modificar salud " << endl;
                                                cout << "0) Salir " << endl;
                                                string ox;
                                                getline(cin, ox);
                                                if(ox == "1"){
                                                    string a;
                                                    cout << "Nuevo nombre: ";
                                                    getline(cin, a);
                                                    x->setNombre(a);
                                                }
                                                if(ox == "2"){
                                                    unsigned int n;
                                                    cout << "Nueva edad: ";
                                                    cin >> n; cin.ignore();
                                                    x->setEdad(n);
                                                }
                                                if(ox == "3"){
                                                    string s;
                                                    cout << "Nuevo genero: ";
                                                    getline(cin, s);
                                                    x->setGenero(s);
                                                }
                                                if(ox == "4"){
                                                    int n;
                                                    cout << "Nueva salud: ";
                                                    cin >> n; cin.ignore();
                                                    x->setSalud(n);
                                                }
                                                if( ox == "0"){
                                                    break;
                                                }
                                            }
                                        }
                                            
                                        }else{
                                            cout << "Lista vacia, no puedes modificar nada." << endl;
                                            cout << endl;
                                        }
                                    }
                                    if(op2 == "6"){
                                        au->resum();
                                    }
                                    if(op2 == "0"){
                                        break;
                                    }

                                }}
                        if(oo == "2"){
                            while(true){
                                
                            cout << "============================================================" << endl;    
                            cout << left << setw(18) << "Nombre";
                            cout << setw(15) << "Posicion X";
                            cout << setw(17) << "Posicion Y";
                            cout << setw(15) << "Puntuacion" << endl;
                            cout << "------------------------------------------------------------" << endl;
                            cout << *au << endl;
                            cout << "============================================================" << endl;
                            cout << "1) Agregar barco" << endl;
                            cout << "2) Mostrar todos los barcos" << endl;
                            cout << "3) Buscar barcos" << endl;
                            cout << "4) Eliminar barcos" << endl;
                            cout << "0) Salir" << endl;
                            string ok;
                            getline(cin, ok);
                            if(ok == "1"){
                                Barco *b = new Barco();
                                int id;
                                cout << "ID: "; cin >> id; cin.ignore();b->setID(id);
                                float com;
                                cout << "Combustible: "; cin >> com; cin.ignore();b->setCombus(com);
                                au->AgregarB(b);
                                
                            }
                            if(ok == "2"){
                                if(au->tamB() > 0){
                                    au->resB();
                                }else{
                                    cout << "Lista de Barcos vacia" << endl;
                                } 
                                
                            }
                            if(ok == "3"){
                                if(au->tamB() > 0){
                                int st;
                                cout << "ID del barco: " ; cin>>st; cin.ignore();
                                Barco *b = au->buscarB(st);
                                    if(b == nullptr){
                                        cout << "No se encuentra el ID"<<endl;
                                    }else{
                                        while(true){
                                        cout << "============================================================" << endl;
                                        cout << left << setw(10) << "ID";
                                        cout << setw(13) << "Combustible";
                                        cout << setw(10) << "Velocidad";
                                        cout << setw(10) << "Armadura";
                                        cout << setw(10) << "Cantidad de Guerreros" << endl;
                                        cout << "------------------------------------------------------------" << endl;
                                        cout << *b ;
                                        cout << "============================================================" << endl;
                                        cout << "1) Agregar guerrero " << endl;
                                        cout << "2) Eliminar guerrero " << endl;
                                        cout << "3) Mostrar ultimo guerrero" << endl;
                                        cout << "4) Mostrar todods los guerreros" << endl;
                                        cout << "0) Salir" << endl;
                                        string gue;
                                        getline(cin, gue);
                                        if(gue == "1"){
                                            Guerrero ge;
                                            int id;cout << "ID: "; cin>>id; cin.ignore(); ge.setID(id);
                                            while(true){
                                                cout << "\t\t====Tipo====" << endl;
                                                cout << "1) Arquero" << endl;
                                                cout << "2) Paladin" << endl;
                                                cout << "3) Ladron" << endl;
                                                cout << "4) Berserker" << endl;
                                                string sk;
                                                getline(cin, sk);
                                                if(sk == "1"){
                                                    ge.setTipo("Arquero");
                                                    ge.setSalud(500);
                                                    ge.setFuerza(350);
                                                    ge.setEscudo(100);
                                                    b->agregarG(ge);
                                                    break;
                                                }
                                                if(sk == "2"){
                                                    ge.setTipo("Paladin");
                                                    ge.setSalud(1500);
                                                    ge.setFuerza(450);
                                                    ge.setEscudo(600);
                                                    b->agregarG(ge);
                                                    break;
                                                }
                                                if(sk == "3"){
                                                    ge.setTipo("Ladron");
                                                    ge.setSalud(300);
                                                    ge.setFuerza(400);
                                                    ge.setEscudo(200);
                                                    b->agregarG(ge);
                                                    break;
                                                }
                                                if(sk == "4"){
                                                    ge.setTipo("Berserker");
                                                    ge.setSalud(3000);
                                                    ge.setFuerza(1000);
                                                    ge.setEscudo(1000);
                                                    b->agregarG(ge);
                                                    break;
                                                }
                                            }
                                        }
                                        if(gue == "2"){
                                            if(b->tam() > 0){
                                                b->eliminarG();
                                            }else{
                                                cout << "No hay guerreros, no puedes eliminar" << endl;
                                                cout << endl;
                                            }
                                        }
                                        if(gue == "3"){
                                            if(b->tam()>0){
                                                cout << "============================================================" << endl;
                                                cout << left << setw(10) << "ID";
                                                cout << setw(10) << "Tipo";
                                                cout << setw(10) << "Salud";
                                                cout << setw(10) << "Fuerza";
                                                cout << setw(10) << "Escudo" << endl;
                                                cout << "------------------------------------------------------------" << endl;
                                                cout << b->tope();
                                                cout << "============================================================" << endl;
                                            }else{
                                                cout << "No hay guerreros que mostrar" << endl;
                                            }
                                        }
                                        if(gue == "4"){
                                            if(b->tam() > 0){
                                                b->resumG();
                                            }else{
                                                cout << "No hay guerreros que mostrar" << endl;
                                            }

                                        }
                                        if(gue == "0"){
                                            break;
                                        }
                                        }
                                    }
                                }else{
                                    cout << "Lista vacia, no hay nada que buscar."<< endl;
                                }
                            }
                            if(ok == "4"){
                                if(au->tamB() > 0){
                                    while(true){
                                        cout << "1) Eliminar por ID" << endl;
                                        cout << "2) Eliminar por combustible < x" << endl;
                                        string acc;
                                        getline(cin, acc);
                                        if(acc == "1"){
                                            int i;
                                            cout << "ID: "; cin >> i; cin.ignore();
                                            au->eliminarB(i);
                                            break;
                                        }
                                        if(acc == "2"){
                                            float c;
                                            cout << "Combustible menor a: " ; cin>>c ; cin.ignore();
                                            au->eliminarBc(c);
                                            break;

                                        }
                                    }
                                }else{
                                    cout << "No hay barcos que eliminar" << endl;
                                }
                            }
                            if(ok == "0"){
                                break;
                            }
                        }}
                        if(oo == "0"){
                            break;
                        }
                }
                }
            }
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
                    cout << "============================================================" << endl;
                    cout << left << setw(18) << "Nombre";
                    cout << setw(15) << "Posicion X";
                    cout << setw(17) << "Posicion Y";
                    cout << setw(15) << "Puntuacion" << endl;
                    cout << "------------------------------------------------------------" << endl;
                    cout << *au << endl;
                    cout << "============================================================" << endl;
                    cout << endl;
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
                        cout << "Nueva puntuacion: ";
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
        if(op == "12"){
            c1.backup();
        }
        if(op == "13"){
            c1.recovery();
        }
        if(op == "0"){
            break;
        }

    }
    
}
    
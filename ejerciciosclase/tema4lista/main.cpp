#include <iostream>
using namespace std;

/*
// CLASE NODO **NO** PLANTILLA
typedef int Dato;

class Nodo{
    private:
        Dato dato;
        Nodo* enlace;
    public:
        Nodo(Dato d){
            dato = d;
            enlace = 0;
        }

        Nodo(Dato a, Nodo* n){
            dato = a;
            enlace = n;
        }

        Dato datoNodo() const{
            return dato;
        }

        Nodo* enlaceNodo() const{
            return enlace;
        }

        void ponerEnlace(Nodo* next){
            enlace = next;
        }
};
*/

template <typename T> class Nodo{
    protected:
        T dato;
        Nodo<T>* enlace;
    public:
        Nodo(T d){
            Nodo::dato = d;
            Nodo::enlace = 0; //Valor null en C++
        }
        Nodo(T d, Nodo<T>* e){
            Nodo::dato = d;
            Nodo::enlace = e; //Valor null en C++
        }

        T datoNodo(){
            return Nodo::dato;
        }

        Nodo<T>* enlaceNodo(){
            return Nodo::enlace;
        }

        void ponerEnlace(Nodo<T>* e){
            Nodo::enlace = e;
        }
};

template <typename T> void recorrerPseudolista(Nodo<T>* pseudolista){
    bool existeEnlace = true;
    while (existeEnlace == true){
        cout << pseudolista->datoNodo() << endl;
        if (pseudolista->enlaceNodo() == NULL){
            existeEnlace = false;
        } else {
            pseudolista = pseudolista->enlaceNodo();
        }
    }
}

//Con lo visto hasta ahora en clase, haz una pseudolista enlazada, creando 3 nodos con datos y conectándolos entre sí.
//Al terminar, recorrer la pseudolista mostrando los datos de los nodos.
int main(int, char**) { 
    std::cout << "Clase 29/11 PEL\n";

    //Nodo n1(1);
    Nodo<int>* n0 = new Nodo<int>(4);
    Nodo<int>* n1 = new Nodo<int>(6);
    Nodo<int>* n2 = new Nodo<int>(8);

    n0->ponerEnlace(n1);
    n1->ponerEnlace(n2);

    recorrerPseudolista<int>(n0);
}
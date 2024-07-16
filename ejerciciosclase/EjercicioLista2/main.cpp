#include <iostream>
using namespace std;

template <typename T>
class Nodo
{
protected:
    T dato;
    Nodo<T> *enlace;

public:
    Nodo(T d)
    {
        Nodo::dato = d;
        Nodo::enlace = 0; // Valor null en C++
    }
    Nodo(T d, Nodo<T> *e)
    {
        Nodo::dato = d;
        Nodo::enlace = e; // Valor null en C++
    }

    T datoNodo()
    {
        return Nodo::dato;
    }

    Nodo<T> *enlaceNodo()
    {
        return Nodo::enlace;
    }

    void ponerEnlace(Nodo<T> *e)
    {
        Nodo::enlace = e;
    }
};

template <typename T> class ListaEnlazada{
private:
    Nodo<T> cabeza;
    class NodoLista{
        public:
            T elemento;
            NodoLista* siguiente;
            Nodolista(T x){
                elemento = x;
                siguiente = 0;
            };
    };

    NodoLista* primero;

public:

    ListaPEL(){
        primero = 0;
    }

    // Funciones de inserción

        //Inserción cabeza
        void insert_head(T elemento){
            NodoLista* nuevo = new NodoLista(elemento);
            nuevo->siguiente = primero;
            primero = nuevo;
        }

        //Inserción cola
        void insert_cola(T elemento){
            NodoLista* aux = primero;
            NodoLista* nuevo = new NodoLista(elemento);
            bool existe_enlace = true;
            if(esVacia() == false){
                while(existe_enlace == true){
                    if(aux->siguiente == NULL){
                        aux->siguiente = nuevo;
                        existe_enlace = false;
                    } 
                }            
            }
        }

        //Inserción entre dos nodos
        void insert_posicion(T elemento, int posicion){
            if (posicion > size()){
                cout << "No se puede insertar en dicha posición";
            } else {
                NodoLista* aux = primero;
                for (int i = 0; i < posicion; ++i){
                    aux = aux->siguiente;
                }

                nuevo->siguiente = aux->siguiente;
                aux->siguiente = nuevo;
            }
        }

    //Funciones de tamaño

    bool esVacia(){
        return primero == NULL;
    }

    int size(){
        bool existe_enlace = true;
        NodoLista* aux = primero;
        int contador = 0;
        while (existe_enlace == true){
            if (aux->siguiente != NULL){
                ++contador;
            } else  {
                existe_enlace == false;
            }
        }
        return contador;
    }

    //Funciones de extracción

        // Extraccion por la cabeza
        void extract_cabeza(){
            NodoLista* aux = primero;
            primero = primero->siguiente;
            delete aux;
        }

        // Extracción por cola
        void extract_cola(){
            NodoLista* aux = primero;
            for (int i = 0; i < size(); ++i){
                aux = aux->siguiente;
            }
            NodoLista* aux2 = aux->siguiente:
            aux->siguiente = 0;
            delete aux2;
        }

        // Extracción de una posición concreta
        void extract_posicion(int pos){
            NodoLista* aux = primero;
            if (pos > size() && pos <= 0){
                cout << "No existen tantos elementos en la lista";
            } else {
                for(int = 0; i < pos-1; ++i){
                    aux = aux->siguiente
                }
                NodoLista* aux2 = aux->siguiente:
                aux->siguiente = aux2->siguiente;
                delete aux2;
            }
        }

    //Funciones de acceso
        //Funciones de búsqueda
        bool element_exist(T elemento){
            NodoLista* aux = primero;
            int cont = 0;
            bool exist = false;
            while(contador < size()){
                if (aux->elemento == elemento){
                    exist = true;
                    //cont = size();
                } else {
                    ++cont;
                }
            }
            return exist;
        }
    
        //Funcion de busqueda posicional
        int element_posicion(){
            
        }

        //Función de obtención de dato por la cabeza
        //Función de obtención de dato por la cola
        //Función de obtención de dato por una posición concreta
};

template <typename T>
void recorrerPseudolista(Nodo<T> *pseudolista)
{
    bool existeEnlace = true;
    while (existeEnlace == true)
    {
        cout << pseudolista->datoNodo() << endl;
        if (pseudolista->enlaceNodo() == NULL)
        {
            existeEnlace = false;
        }
        else
        {
            pseudolista = pseudolista->enlaceNodo();
        }
    }
}

int main(int, char **)
{
    std::cout << "Clase  PEL\n";

    // Nodo n1(1);
    Nodo<int> *n0 = new Nodo<int>(4);
    Nodo<int> *n1 = new Nodo<int>(6);
    Nodo<int> *n2 = new Nodo<int>(8);

    n0->ponerEnlace(n1);
    n1->ponerEnlace(n2);

    recorrerPseudolista<int>(n0);
}

// Ejercicio 1ª parte de la clase
// Utilizando la pseudolista enlazada. crear funciones para insertarelementos al principio, al final,
// y después de dos elementos concretos del nodo.

// Ejercicio 2ª parte de la clase
// Crear clase lista enlazada
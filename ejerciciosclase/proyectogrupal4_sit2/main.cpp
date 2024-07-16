#include <iostream>
using namespace std;

/*
Escribir una función, copiarPila(), que copie el contenido de una pila en otra. La
función tendrá dos argumentos de tipo pila, uno la pila fuente y otro la pila destino.
Utilizar las operaciones definidas sobre el TAD Pila para una pila enlazada.
*/

template <typename T>
class NodoGenerico
{
public:
    T dato;
    NodoGenerico<T> *siguienteNodo;

public:
    NodoGenerico(T dato)
    {
        this->dato = dato;
        this->siguienteNodo = 0;
    };
    NodoGenerico(){

    };
    NodoGenerico(T dato, NodoGenerico<T> *sig)
    {
        this->dato = dato;
        this->siguienteNodo = sig;
    };
    T getDato()
    {
        return dato;
    }
    NodoGenerico<T> getSiguienteNodo()
    {
        return siguienteNodo;
    }
    void setEnlace(NodoGenerico<T> *n)
    {
        this->siguienteNodo = n;
    }

    ~NodoGenerico();
};

template <typename T>
class ListaEnlazada
{
private:
    NodoGenerico<T> *primero;
    NodoGenerico<T> *ultimo;

public:
    ListaEnlazada()
    {
        primero = NULL;
        ultimo = NULL;
    };

    void push(T dato)
    {
        NodoGenerico<T> *nuevoNodo = new NodoGenerico<T>();
        nuevoNodo->dato = dato;
        if (listaVacia())
        {
            // asigno el nuevo nodo como primero y ultimo
            primero = nuevoNodo;
            ultimo = nuevoNodo;
            // el siguiente nodo del ultimo es NULL
            primero->siguienteNodo = NULL;
        }
        else
        {
            // el siguiente nodo del nuevo nodo es el primero
            nuevoNodo->siguienteNodo = primero;
            // el nuevo nodo es el primero
            primero = nuevoNodo;
        }
        // cout << "Nodo con valor(" << dato << ") insertado correctamente" << endl;
    };

    T pop()
    {
        if (listaVacia())
        {
            cout << "La lista esta vacia" << endl;
        }
        else
        {
            T dato = primero->dato;
            NodoGenerico<T> *nodoAEliminar = primero;
            primero = primero->siguienteNodo;
            // delete nodoAEliminar;
            return dato;
        }
    }

    void insertarNodoDespuesDe(T dato, T datoDespuesDe)
    {
        NodoGenerico<T> *nuevoNodo = new NodoGenerico<T>();
        nuevoNodo->dato = dato;
        NodoGenerico<T> *nodoActual = new NodoGenerico<T>();
        nodoActual = primero;
        // recorro la lista hasta que el nodo actual sea nulo o hasta que encuentre el dato
        while (nodoActual != NULL && nodoActual->dato != datoDespuesDe)
        {
            nodoActual = nodoActual->siguienteNodo;
        }
        if (nodoActual == NULL)
        {
            cout << "El nodo no existe" << endl;
        }
        else
        {
            nuevoNodo->siguienteNodo = nodoActual->siguienteNodo;
            nodoActual->siguienteNodo = nuevoNodo;
            cout << "Nodo con valor(" << dato << ") insertado correctamente" << endl;
        }
    };
    void mostrarLista()
    {
        if (!listaVacia())
        {
            NodoGenerico<T> *nodoActual = new NodoGenerico<T>();
            nodoActual = primero;
            while (!nodoVacio(nodoActual))
            {
                cout << nodoActual->dato << " -> ";
                nodoActual = nodoActual->siguienteNodo;
                if (nodoVacio(nodoActual))
                {
                    cout << "NULL";
                }
            }
        }
        else
        {
            cout << "La lista esta vacia" << endl;
        }
    };

    int size(){
        return ultimo - primero;
    }

    bool listaVacia()
    {
        return primero == NULL;
    };
    bool nodoVacio(NodoGenerico<T> *nodo)
    {
        return nodo == NULL;
    };
    T get_dato_primero()
    {
        return primero->dato;
    }
};

template <typename T>
void copiarPila(ListaEnlazada<T> *lista1, ListaEnlazada<T> *lista2)
{
    while(!lista1->listaVacia()){
        lista2->push(lista1->pop());
    }
}

template <typename T>
void leerLista(ListaEnlazada<T> *l){
    ListaEnlazada<T> *l2 = new ListaEnlazada<T>();
    while(!l->listaVacia()){
        l2->push(l->pop());
    }
    while(!l2->listaVacia()){
        T aux = l2->pop();
        cout << aux;
        l->push(aux);
    }
}

int main()
{
    ListaEnlazada<string>* pila0 = new ListaEnlazada<string>;
    ListaEnlazada<string>* pila1 = new ListaEnlazada<string>;
    cout << "Ejercicio 4-2: ";
    cout << "Introduce que 3 elementos que quieras meter en la pila: " << endl;
    string x, y, z;
    cin >> x;
    cout << endl;
    cin >> y;
    cout << endl;
    cin >> z;

    pila0->push(x);
    pila0->push(y);
    pila0->push(z);

    cout << "La pila antigua es: ";
    leerLista(pila0);

    cout << "\nLa pila nueva es: ";    
    leerLista(pila1);
    
    cout << "\nCambiando los datos de la antigua pila a la nueva: " << endl;
    copiarPila(pila0, pila1);

    cout << "La pila antigua es: ";
    leerLista(pila0);

    cout << "\nLa pila nueva es: ";    
    leerLista(pila1);
};
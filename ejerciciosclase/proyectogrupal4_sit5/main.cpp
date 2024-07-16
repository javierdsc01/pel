#include <iostream>
using namespace std;

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
public:
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
    while (!lista1->listaVacia())
    {
        lista2->push(lista1->pop());
    }
}

/*
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
*/

template <typename T>
void borrarElementoTest(ListaEnlazada<T> *l, T element)
{
    NodoGenerico<T> *nuevoNodo = new NodoGenerico<T>();
    nuevoNodo->element = element;
    NodoGenerico<T> *nodoActual = new NodoGenerico<T>();
    nodoActual = l->primero;
    // recorro la lista hasta que el nodo actual sea nulo o hasta que encuentre el dato
    while (nodoActual != NULL && nodoActual->element != l->element)
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
        cout << "Nodo con valor(" << element << ") insertado correctamente" << endl;
    }
}

template <typename T>
void borrarElemento(ListaEnlazada<T> *lista, T dato)
{
    NodoGenerico<T> *nodoActual = new NodoGenerico<T>();
    nodoActual = lista->primero;
    NodoGenerico<T> *nodoAnterior = new NodoGenerico<T>();
    nodoAnterior = NULL;
    // recorro la lista hasta que el nodo actual sea nulo o hasta que encuentre el dato
    while (nodoActual != NULL && nodoActual->dato != dato)
    {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->siguienteNodo;
    }
    if (nodoActual == NULL)
    {
        cout << "El nodo no existe" << endl;
    }
    else
    {
        if (nodoAnterior == NULL)
        {
            lista->primero = lista->primero->siguienteNodo;
        }
        else
        {
            nodoAnterior->siguienteNodo = nodoActual->siguienteNodo;
        }
        delete nodoActual;
        cout << "Nodo con valor(" << dato << ") eliminado correctamente" << endl;
    }
};

template <typename T>
void leerLista(ListaEnlazada<T> *l)
{
    ListaEnlazada<T> *l2 = new ListaEnlazada<T>();
    while (!l->listaVacia())
    {
        l2->push(l->pop());
    }
    while (!l2->listaVacia())
    {
        T aux = l2->pop();
        cout << aux;
        l->push(aux);
    }
};

template <typename T>
// borrar todos los elementos de la lista
void borrarTodo(ListaEnlazada<T> *lista)
{
    while (!lista->listaVacia())
    {
        lista->pop();
    }
};

/*
    Escribe un programa en el que se manejen un total de 5 pilas. La entrada de datos
    será de pares de enteros (i, j), tal que 1<= abs(1) <= n. De tal forma que el criterio de
    selección de pila sea:
    • Si i es positivo, debe introducirse el dato j en la Pila i.
    • Si i es negativo, debe eliminarse el dato j en la Pila j.
    • Si i es 0, fin del proceso de entrada.
    Los datos de entrada se introducen por teclado. Cuando termine el proceso, el
    programa debe escribir el contenido de las pilas en pantalla
*/

int main(int, char **)
{
    cout << "Ejercicio 4-4: " << endl;
    ListaEnlazada<int> *pila1 = new ListaEnlazada<int>;
    ListaEnlazada<int> *pila2 = new ListaEnlazada<int>;
    ListaEnlazada<int> *pila3 = new ListaEnlazada<int>;
    ListaEnlazada<int> *pila4 = new ListaEnlazada<int>;
    ListaEnlazada<int> *pila5 = new ListaEnlazada<int>;

    ListaEnlazada<int> *pi = new ListaEnlazada<int>;
    ListaEnlazada<int> *pj = new ListaEnlazada<int>;

    int i, j, k = -1;
    while (i != 0)
    {
        cout << "Introduce dos numeros '(i, j, k)' contando con que k solo puede ser -1 o 0" << endl;
        cout << "Siendo -1 borrar todos los elementos de la pila y 0 hacer el proceso" << endl;
        cin >> i;
        cout << endl;
        cin >> j;
        cout << endl;
        cin >> k;
        cout << endl;

        cout << "\nLa pila 1 es: ";
        leerLista(pi);

        cout << "\nLa pila 2 es: ";
        leerLista(pj);

        cout << endl;
        if (k = 0)
        {
            cout << "Introduce dos numeros '(i, j)'" << endl;
            cin >> i;

            cout << endl;
            cin >> j;

            cout << endl;

            if (i > 0)
            {
                pi->push(j);
            }
            else
            {
                borrarElemento(pj, j);
            }

            cout << "\nLa pila i es: ";
            leerLista(pi);

            cout << "\nLa pila j es: ";
            leerLista(pj);
            cout << endl;
        }
        else if (k = -1)
        {
            borrarTodo(pi);
            borrarTodo(pj);
        }
    }
}

template <typename T>
NodoGenerico<T>::~NodoGenerico()
{
}
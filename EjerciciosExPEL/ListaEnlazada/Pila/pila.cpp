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

            //retornar 0 si T es int o NULL si T es Persona
            return T();

           
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

    void vaciarLista()
    {
        while (!listaVacia())
        {
            pop();
        }
    };

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
//------------------------------------------------------------------------------------------CLASS PERSONA
class Persona
{
private:
    string nombre;
    int edad;

public:
    Persona(string nombre, int edad)
    {
        this->nombre = nombre;
        this->edad = edad;
    }
    // SIEMPRE PONER CONSTRUCTOR VACIO
    Persona() {}
    int getEdad()
    {
        return this->edad;
    }
    string to_string()
    {
        return "Nombre: " + this->nombre + " Edad: " + std::to_string(this->edad);
    }
};


template <typename T>
void leerPila(ListaEnlazada<T> *l)
{
    ListaEnlazada<T> *l2 = new ListaEnlazada<T>();
    while (!l->listaVacia())
    {
        l2->push(l->pop());
    }
    while (!l2->listaVacia())
    {
        T aux = l2->pop();
        // aux.to_string(); por si usas una clase implementa el tostring
        cout << aux << endl;
        l->push(aux);
    }
}

template <typename T>
void leerPilaObj(ListaEnlazada<T> *l)
{
    ListaEnlazada<T> *l2 = new ListaEnlazada<T>();
    while (!l->listaVacia())
    {
        l2->push(l->pop());
    }
    while (!l2->listaVacia())
    {
        T aux = l2->pop();
        // aux.to_string(); por si usas una clase implementa el tostring
        cout <<  aux.to_string() << endl;
        l->push(aux);
    }
}

//Ordena con lista de int
void sortPila(ListaEnlazada<int> *l)
{
    ListaEnlazada<int> *l2 = new ListaEnlazada<int>();
    while (!l->listaVacia())
    {
        int aux = l->pop();
        //Aqui cambiamos a < o > para ordenar de forma ascendente o descendente
        //_________________________________________________!____________________
        while (!l2->listaVacia() && l2->get_dato_primero() > aux)
        {
            l->push(l2->pop());
        }
        l2->push(aux);
    }
    while (!l2->listaVacia())
    {
        l->push(l2->pop());
    }
}

//Ordena con lista de Persona
void sortPila(ListaEnlazada<Persona> *l)
{
    ListaEnlazada<Persona> *l2 = new ListaEnlazada<Persona>();
    while (!l->listaVacia())
    {
        Persona aux = l->pop();
        //Aqui cambiamos a < o > para ordenar de forma ascendente o descendente
        //___________________________________________________________!____________________
        while (!l2->listaVacia() && l2->get_dato_primero().getEdad() > aux.getEdad())
        {
            l->push(l2->pop());
        }
        l2->push(aux);
    }
    while (!l2->listaVacia())
    {
        l->push(l2->pop());
    }
}

int main()
{
    ListaEnlazada<int> *l = new ListaEnlazada<int>();

    l->push(5);
    l->push(2);
    l->push(4);
    l->push(3);
    l->push(1);

    sortPila(l);

    //l->pop();
   
    leerPila(l);

    l->vaciarLista();
    l->push(1234);

    cout << "Pila vacia con dato 1234" << endl;
    leerPila(l);
    //____________________________________________________
    ListaEnlazada<Persona> *l2 = new ListaEnlazada<Persona>();
    l2->push(Persona("Juan", 20));
    l2->push(Persona("Pedro", 30));
    l2->push(Persona("Maria", 10));
    l2->push(Persona("Jose", 40));

    sortPila(l2);

    leerPilaObj(l2);




    return 0;
}
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------Clase de la cola
template <class T>
class colaGenerica
{
protected:
    class nodoCola
    {
    public:
        nodoCola *siguiente;
        T elemento;
        nodoCola(T x)
        {
            elemento = x;
            siguiente = NULL;
        }
    };
    nodoCola *frente;
    nodoCola *final;

public:
    colaGenerica()
    {
        frente = final = NULL;
    }
    void insertar(T elemento)
    {
        nodoCola *nuevo = new nodoCola(elemento);
        if (colaVacia())
            frente = nuevo;
        else
            final->siguiente = nuevo;
        final = nuevo;
    };
    T quitar()
    {
        T elemento = frente->elemento;
        nodoCola *aux = frente;
        if (frente == final)
            frente = final = NULL;
        else
            frente = frente->siguiente;
        delete aux;
        return elemento;
    };

    void borrarCola()
    {
        while (frente != NULL)
        {
            nodoCola *aux = frente;
            frente = frente->siguiente;
            delete aux;
        }
        final = NULL;
    };
    T frenteCola() const
    {
        return frente->elemento;
    };
    bool colaVacia() const
    {
        return frente == NULL;
    };
    ~colaGenerica()
    {
        borrarCola();
    }

    int size()
    {
        int contador = 0;
        nodoCola *aux = frente;
        while (aux != NULL)
        {
            contador++;
            aux = aux->siguiente;
        }
        return contador;
    }

    //FUNCIONES EXTRA---------------------------------------------------------------------------------------------------------------------------------------

};
//---------------------------------------------------------------------------------------------------------------------------------------Funciones de la cola
/*
Escribir una función que crea un clon (una copia idéntica) de una cola determinada. Las
operaciones que se han de utilizar son únicamente las del TAD Cola.
*/
template <class T>
colaGenerica<T> clonarCola(colaGenerica<T> cola)
{
    colaGenerica<T> colaClonada;
    colaGenerica<T> colaAuxiliar;
    while (!cola.colaVacia())
    {
        colaAuxiliar.insertar(cola.quitar());
    }

    while (!colaAuxiliar.colaVacia())
    {
        colaClonada.insertar(colaAuxiliar.frenteCola());
        cola.insertar(colaAuxiliar.quitar());
    }

    return colaClonada;
}

/**
 Escribir una función que tenga como argumentos dos colas del mismo tipo. En caso de ser
idénticas en sus valores, lo indique por consola al usuario.
*/

template <class T>
void compararColas(colaGenerica<T> cola1, colaGenerica<T> cola2)
{
    colaGenerica<T> colaAuxiliar1;
    colaGenerica<T> colaAuxiliar2;
    bool iguales = true;
    while (!cola1.colaVacia() && !cola2.colaVacia())
    {


        colaAuxiliar1.insertar(cola1.quitar());
        colaAuxiliar2.insertar(cola2.quitar());
    }

    while (!colaAuxiliar1.colaVacia() && !colaAuxiliar2.colaVacia())
    {
        if (colaAuxiliar1.frenteCola() != colaAuxiliar2.frenteCola())
        {
            iguales = false;
        }
        cola1.insertar(colaAuxiliar1.quitar());
        cola2.insertar(colaAuxiliar2.quitar());
    }

    if (iguales)
    {
        cout << "Las colas son iguales" << endl;
    }
    else
    {
        cout << "Las colas no son iguales" << endl;
    }
}

//Invertir una cola
//haciendo que el frente de la cola sea el final y viceversa
template <class T>
void invertirCola(colaGenerica<T> &cola)
{
    colaGenerica<T> colaAuxiliar;
    while (!cola.colaVacia())
    {
        colaAuxiliar.insertar(cola.quitar());
    }

    while (!colaAuxiliar.colaVacia())
    {
        cola.insertar(colaAuxiliar.quitar());
    }
 
}


//Funcion para leer los valores de una cola
template <class T>
void leerColaNoPuntera(colaGenerica<T> cola)
{
    colaGenerica<T> colaAuxiliar;
    while (!cola.colaVacia())
    {
        colaAuxiliar.insertar(cola.quitar());
    }

    while (!colaAuxiliar.colaVacia())
    {
        cout << colaAuxiliar.frenteCola() << endl;
        //Si fuese un objeto se podria hacer colaAuxiliar.frenteCola().imprimir();
        cola.insertar(colaAuxiliar.quitar());
    }
}

//Funcion para leer los valores de una cola puntero
template <class T>
void leerColaPuntero(colaGenerica<T> *cola)
{
    colaGenerica<T> colaAuxiliar;
    while (!cola->colaVacia())
    {
        colaAuxiliar.insertar(cola->quitar());
    }

    while (!colaAuxiliar.colaVacia())
    {
        cout << colaAuxiliar.frenteCola() << endl;
        //Si fuese un objeto se podria hacer colaAuxiliar.frenteCola().imprimir();
        cola->insertar(colaAuxiliar.quitar());
    }
}


//Funcion para buscar un elemento en una cola
template <class T>
bool buscarElementoCola(colaGenerica<T> cola, T elemento)
{
    colaGenerica<T> colaAuxiliar;
    bool encontrado = false;
    while (!cola.colaVacia())
    {
        colaAuxiliar.insertar(cola.quitar());
    }

    while (!colaAuxiliar.colaVacia())
    {
        if (colaAuxiliar.frenteCola() == elemento)
        {
            encontrado = true;
        }
        cola.insertar(colaAuxiliar.quitar());
    }
    return encontrado;
}



//--------------------------------------------------------------------------------------------------------------------------------------------------Funcion main
int main(int, char **)
{
    colaGenerica<int> *cola = new colaGenerica<int>();
    cola->insertar(1);
    cola->insertar(2);
    cola->insertar(3);
    cola->insertar(4);
    cola->insertar(5);
    cola->insertar(5);
   // cola->quitar();
   
   //leerColaNoPuntera(invertirCola(*cola));
    

    colaGenerica<int> colaClonada = clonarCola(*cola);
    cout << "Impresion de cola clonada" << endl;
    //  invertirCola(colaClonada);
    cout << ((buscarElementoCola(colaClonada, 5)) ? "Encontrado" : "No encontrado") << endl;
    leerColaNoPuntera(colaClonada);

    


   /* Funciona
    colaGenerica<int> *cola1 = new colaGenerica<int>();
    cola1->insertar(2);


    colaGenerica<int> *cola2 = new colaGenerica<int>();
    cola2->insertar(1);


    cout << "Comparacion de colas" << endl;
    compararColas(*cola1, *cola2) ;

*/

    return 0;
}

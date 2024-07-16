#include <iostream>
using namespace std;

//El deque es una estructura de datos que permite meter y sacar por cola y cabeza. Lo que no tiene es un metodo buscar

// Clase nodo que contiene un valor y dos punteros a nodo (siguiente y anterior)
// El tipo de dato del valor es T
// Con este nodo se puede crear una lista doblemente enlazada conocida como deque
template <typename T>
class nodo
{
public:
// Valor del nodo de tipo T
    T valor;
// Puntero al siguiente nodo
    nodo<T> *siguiente;
// Puntero al nodo anterior
    nodo<T> *anterior;
};

// Clase deque que contiene un puntero al primer nodo, 
//un puntero al último nodo y un entero que indica el tamaño
// El tipo de dato del valor es T
// Con esta clase se puede crear un deque
//Contiene los métodos push_back, push_front, 
//pop_back, pop_front, front, back, size, empty, clear
template <typename T>
class deque
{
private:
    nodo<T> *primero;
    nodo<T> *ultimo;
    int tamano;

public:
// Constructor vacío ya que no se le pasa ningún 
//parámetro y al principio el deque está vacío
    deque()
    {
        primero = NULL;
        ultimo = NULL;
        tamano = 0;
    };
// Destructor que llama al método clear 
//para eliminar todos los nodos
    ~deque()
    {
        clear();
    };
    //Metodo que añade un nodo al final del deque
    void push_back(T valor)
    {
        nodo<T> *nuevo = new nodo<T>;
        nuevo->valor = valor;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
        if (primero == NULL)
        {
            primero = nuevo;
            ultimo = nuevo;
        }
        else
        {
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
            ultimo = nuevo;
        }
        tamano++;
    };
    //Metodo que añade un nodo al principio del deque
    void push_front(T valor)
    {
        nodo<T> *nuevo = new nodo<T>;
        nuevo->valor = valor;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
        if (primero == NULL)
        {
            primero = nuevo;
            ultimo = nuevo;
        }
        else
        {
            primero->anterior = nuevo;
            nuevo->siguiente = primero;
            primero = nuevo;
        }
        tamano++;
    };
    //Metodo que elimina el último nodo del deque
    T pop_back()
    {
        if (tamano == 0)
        {
            return 0;
        }
        else
        {
            nodo<T> *aux = ultimo;
            ultimo = ultimo->anterior;
            ultimo->siguiente = NULL;
            T valor = aux->valor;
            delete aux;
            tamano--;
            return valor;
        }
    };
    //Metodo que elimina el primer nodo del deque
    T pop_front()
    {
        if (tamano == 0)
        {
            return 0;
        }
        else
        {
            nodo<T> *aux = primero;
            primero = primero->siguiente;
            primero->anterior = NULL;
            T valor = aux->valor;
            delete aux;
            tamano--;
            return valor;
        }
    };
    //Metodos que devuelven el valor del primer nodo del deque
    T front()
    {
        return primero->valor;
    };
    //Metodos que devuelven el valor del  último nodo del deque
    T back()
    {
        return ultimo->valor;
    };
    //Metodos que devuelven el tamaño del deque
    int size()
    {
        return tamano;
    };
    //Metodo que devuelve true si el deque está vacío y false si no lo está
    bool empty()
    {
        return tamano == 0;
    };
    //Metodo que elimina todos los nodos del deque
    void clear()
    {
        while (tamano > 0)
        {
            pop_back();
        }
    };
    //Metodo que imprime todos los valores del deque
    void print()
    {
        nodo<T> *aux = primero;
        while (aux != NULL)
        {
            cout << aux->valor << " ";
            aux = aux->siguiente;
        }
        cout << endl;
    };
    //Metodo que devuelve el valor del nodo en la posición index
    T getByindex(int index)
    {
        nodo<T> *aux = primero;
        for (int i = 0; i < index; i++)
        {
            aux = aux->siguiente;
        }
        return aux->valor;
    };
    //Metodo que cambia el valor del nodo en la posición index
    void setByindex(int index, T valor)
    {
        nodo<T> *aux = primero;
        for (int i = 0; i < index; i++)
        {
            aux = aux->siguiente;
        }
        aux->valor = valor;
    };
};

// Función que ordena el deque de mayor a menor
// Se utiliza el método de la burbuja
// No se utiliza recursividad sino iteración
void sort(deque<double> &cola)
{
    // Se obtiene el tamaño del deque
    int n = cola.size();
    for (int i = 0; i < n - 1; i++)
    {
        // Se recorre el deque desde el principio hasta el final
        for (int j = 0; j < n - i - 1; j++)
        {
            // Si el valor de la posición j es menor que el de la posición j+1
            if (cola.getByindex(j) < cola.getByindex(j + 1))
            {
                // Se intercambian los valores
                double aux = cola.getByindex(j);
                cola.setByindex(j, cola.getByindex(j + 1));
                cola.setByindex(j + 1, aux);
            }
        }
    }
}

int main()
{
    // Crear un deque de doubles
    deque<double> *cola = new deque<double>;
    // Insertar los siguientes valores: 7.8, 8.9, 3.4, 4.5, 9.1, 5.6, 6.7, 10.2, 1.2, 2.3
    cola->push_back(7.8);
    cola->push_back(8.9);
    cola->push_back(3.4);
    cola->push_back(4.5);
    cola->push_back(9.1);
    cola->push_back(5.6);
    cola->push_back(6.7);
    cola->push_back(10.2);
    cola->push_back(1.2);
    cola->push_back(2.3);
    // Imprimir el deque desordenado
    cout << "Desordenado: " << endl;
    cola->print();
    cout << "-----------------" << endl;
    // Ordenar el deque
    sort(*cola);
    // Imprimir el deque ordenado
    cout << "Ordenado de mayor a menor: " << endl;
    cola->print();
    cout << "-----------------" << endl;

    return 0;
}

#include <iostream>
using namespace std;

template <typename T>
class VectorPEL
{
private:
    T *v_,
        *space_,
        *last_;

public:
    // Constructor vacío para el caso 0
    VectorPEL() : v_{new T[0]}, space_{v_}, last_{v_} {} // Constructor vacío
    VectorPEL(VectorPEL<T> const &v) : v_{new T[v.capacity()]}, space_{v_ + v.size()}, last_{v_ + v.capacity()}
    { // Constructor copia
        try
        {
            for (auto i = size_t{0}; i < v.size(); ++i)
            {
                v_[i] = v[i];
            }
        }
        catch (...)
        { // Tres puntos significa todas las excepciones
            delete[] v_;
            throw;
        }
    }
    ~VectorPEL() { delete[] v_; } // Destructor

    auto capacity() const -> size_t { return last_ - v_; } // Nos valen todas las variables (Last dice el tamaño + 1 SIEMPRE)
    auto size() const -> size_t { return space_ - v_; }
    auto empty() const -> bool { return v_ == last_; }
    // const sirve para obligar a devolver bool, size_t, etc. Solo con auto.

    void print()
    {
        for (auto i = size_t{0}; i < size(); i++)
        {
            if (v_[i].alquilado == false)
            {
                cout << "Disco " << i << ":" << endl;
                cout << "Titulo: " << v_[i].titulo << endl;
                cout << "Precio: " << v_[i].precio << endl;
                cout << "El disco es: " << v_[i].dvdBluray << endl;
                cout << endl;
            }
        }
    }

    void printTrue()
    {
        for (auto i = size_t{0}; i < size(); i++)
        {
            if (v_[i].alquilado == true)
            {
                cout << "Disco " << i << ":" << endl;
                cout << "Titulo: " << v_[i].titulo << endl;
                cout << "Precio: " << v_[i].precio << endl;
                cout << "El disco es: " << v_[i].dvdBluray << endl;
                cout << endl;
            }
        }
    }

    void search(string titulo)
    {
        string alquilar;
        for (auto i = size_t{0}; i < size(); ++i)
        {

            if (v_[i].titulo == titulo)
            {

                if (v_[i].alquilado == false)
                {
                    cout << "El disco no esta alquilado" << endl;
                    cout << "El titulo del disco es: " << v_[i].titulo << endl;
                    cout << "El precio del disco es: " << v_[i].precio << endl;
                    cout << "El disco es: " << v_[i].dvdBluray << endl;
                    cout << "Quieres alquilarlo?" << endl
                         << "Responda Y o y para alquilarlo y N o n para no alquilarlo: ";
                    cin >> alquilar;
                    cout << endl;
                    if (alquilar == "y" || alquilar == "Y")
                    {
                        v_[i].alquilado = true;
                    }
                    else if (alquilar == "n" || alquilar == "N")
                    {
                        v_[i].alquilado = false;
                    }
                    else
                    {
                        cout << "Error";
                    }
                }
                else
                {
                    cout << "El disco esta alquilado" << endl;
                }
            }
        }
    }

    void returnMethod(string titulo)
    {
        string devolver;
        for (auto i = size_t{0}; i < size(); ++i)
        {

            if (v_[i].titulo == titulo)
            {

                if (v_[i].alquilado == true)
                {
                    cout << "Estas seguro de querer devolverlo?" << endl;
                    cout << "Responda Y o y para devolverlo y N o n para no devolverlo: ";
                    cin >> devolver;
                    cout << endl;
                    if (devolver == "y" || devolver == "Y")
                    {
                        v_[i].alquilado = false;
                    }
                    else if (devolver == "n" || devolver == "N")
                    {
                        v_[i].alquilado = true;
                    }
                    else
                    {
                        cout << "Error";
                    }
                }
                else
                {
                    cout << "Este disco no esta alquilado";
                }
            }
        }
    }

    auto begin() -> T * { return v_; }
    auto begin() const -> T const * { return v_; }
    auto end() -> T * { return space_; }
    auto end() const -> T const * { return space_; }

    //& es Referencia
    auto push_back(T const &valor)
    {
        // Escenario 1
        if (space_ == last_)
        {
            size_t cp = capacity(), new_cp = (cp == 0) ? 2 : 2 * cp;
            T *new_block = new T[new_cp];
            try
            {
                for (auto i = size_t{}; i < cp; ++i)
                {
                    new_block[i] = v_[i];
                }
                new_block[cp] = valor;
            }
            catch (...)
            {
                delete new_block;
                throw;
            }
            delete[] v_;
            v_ = new_block;
            space_ = new_block + cp + 1;
            last_ = new_block + new_cp;
        }
        // Escenario 2
        else
        {
            *space_ = valor;
            ++space_;
        }
    }
};

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

template <typename T>
class ListaEnlazada
{
private:
    Nodo<T> cabeza;
    class NodoLista
    {
    public:
        T elemento;
        NodoLista *siguiente;
        Nodolista(T x)
        {
            elemento = x;
            siguiente = 0;
        };
    };

    NodoLista *primero;

public:
    ListaPEL()
    {
        primero = 0;
    }

    // Funciones de inserción

    // Inserción cabeza
    void insert_head(T elemento)
    {
        NodoLista *nuevo = new NodoLista(elemento);
        nuevo->siguiente = primero;
        primero = nuevo;
    }

    // Inserción cola
    void insert_cola(T elemento)
    {
        NodoLista *aux = primero;
        NodoLista *nuevo = new NodoLista(elemento);
        bool existe_enlace = true;
        if (esVacia() == false)
        {
            while (existe_enlace == true)
            {
                if (aux->siguiente == NULL)
                {
                    aux->siguiente = nuevo;
                    existe_enlace = false;
                }
            }
        }
    }

    // Inserción entre dos nodos
    void insert_posicion(T elemento, int posicion)
    {
        if (posicion > size())
        {
            cout << "No se puede insertar en dicha posición";
        }
        else
        {
            NodoLista *aux = primero;
            for (int i = 0; i < posicion; ++i)
            {
                aux = aux->siguiente;
            }

            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }

    // Funciones de tamaño

    bool esVacia()
    {
        return primero == NULL;
    }

    int size()
    {
        bool existe_enlace = true;
        NodoLista *aux = primero;
        int contador = 0;
        while (existe_enlace == true)
        {
            if (aux->siguiente != NULL)
            {
                ++contador;
            }
            else
            {
                existe_enlace == false;
            }
        }
        return contador;
    }

    // Funciones de extracción

    // Extraccion por la cabeza
    void extract_cabeza()
    {
        NodoLista *aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    // Extracción por cola
    void extract_cola()
    {
        NodoLista *aux = primero;
        for (int i = 0; i < size(); ++i)
        {
            aux = aux->siguiente;
        }
        NodoLista *aux2 = aux->siguiente :: aux->siguiente = 0;
        delete aux2;
    }

    // Extracción de una posición concreta
    void extract_posicion(int pos)
    {
        NodoLista *aux = primero;
        if (pos > size() && pos <= 0)
        {
            cout << "No existen tantos elementos en la lista";
        }
        else
        {
            for (int i = 0; i < pos - 1; ++i)
            {
                aux = aux->siguiente;
            }
            NodoLista *aux2 = aux->siguiente :: aux->siguiente = aux2->siguiente;
            delete aux2;
        }
    }

    // Funciones de acceso
    // Funciones de búsqueda
    bool element_exist(T elemento)
    {
        NodoLista *aux = primero;
        int cont = 0;
        bool exist = false;
        while (cont < size())
        {
            if (aux->elemento == elemento)
            {
                exist = true;
                // cont = size();
            }
            else
            {
                ++cont;
            }
        }
        return exist;
    }

    // Funcion de busqueda posicional
    int element_posicion()
    {
    }

    // Función de obtención de dato por la cabeza
    // Función de obtención de dato por la cola
    // Función de obtención de dato por una posición concreta
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
};

class Id
{
private:
    int id;
    int valor;

public:
    Id(int idConst, int valorConst)
    {
        this->id = idConst;
        this->valor = valorConst;
    }

    Id() {}

    ~Id() {}
};

Id annadirDatoVector(){
    cout << "Introduce los valores que quieras meter en el vector. Primero tiene que ser un id, y despues el valor que quieras meter: " << endl;
    int idAdd, valorAdd = 0;
    cin >> idAdd;
    cout << " ";
    cin >> valorAdd;
    Id aux(idAdd, valorAdd);
    return aux;
}

int main(int, char **)
{
    VectorPEL<Id>* elementos = new VectorPEL<Id>;
    std::cout << "Clase examen de prueba\n";
    
    int op = 4;
    while (op != 0)
    {
        cout << "\n - QUE QUIERES HACER? - ";
        cout << "\n - [0] SALIR - ";
        cout << "\n - [1] PASAR DATOS - ";
        cout << "\n - [2] TRANSFERIR DATOS - ";
        cout << "\n - [3] MOSTRAR DATOS - ";
        cout << "\n Elija su opcion: " << endl;
        cin >> op;
        switch (op)
        {
        case (0):
            break;
        case (1):
        {
            Id aux = annadirDatoVector();
            elementos->push_back(aux);
            break;
        };
        case (2):
            break;
        case (3):
            break;
        }
    }
}
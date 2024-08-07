#include <iostream>
using namespace std;
// Datos en clave valor y quieren migrarlas en

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




    T get(size_t i) const
    {
        if (i >= size())
        {
            throw std::out_of_range("Fuera de rango");
        }
        return v_[i];
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

    T pop(){
        if(listaVacia()){
            cout << "La lista esta vacia" << endl;

        }else{
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
   

    bool listaVacia()
    {
        return primero == NULL;
    };
    bool nodoVacio(NodoGenerico<T> *nodo)
    {
        return nodo == NULL;
    };
    T get_dato_primero(){
        return primero->dato;
    }
};
class Num{
private:
    int id,num;
public:
    Num() {
        this->id=0;
        this->num=0;
    }
    Num(int id,int num) {
        this->id=id;
        this->num=num;
    }

    int getId(){
        return this->id;
    }
    int getNum(){
        return this->num;
    }
    void setId(int id){
        this->id=id;
    }
    void setNum(int num){
        this->num=num;
    }
    void toString(){
        cout<<"ID:"<<this->id<<" - NUM: "<<this->num<<endl;
    }
};

template <typename T>
void leerLista(ListaEnlazada<T> *l){
    ListaEnlazada<T> *l2 = new ListaEnlazada<T>();
    while(!l->listaVacia()){
        l2->push(l->pop());
    }
    while(!l2->listaVacia()){
        T aux= l2->pop();
        aux.toString();
        l->push(aux);
    }
}

int main(int, char **)
{
    Num *n1 = new Num(1,1);
    Num *n2 = new Num(2,2);
    Num *n3 = new Num(3,3);

    VectorPEL<Num> *v = new VectorPEL<Num>();
    v->push_back(*n1);
    v->push_back(*n2);
    v->push_back(*n3);

    ListaEnlazada<Num> *l = new ListaEnlazada<Num>();
    for (int i = 0; i < v->size(); i++)
    {
        l->push(v->get(i));
    }
    //hacer una copia de la lista
    leerLista(l);








    return 0;
};

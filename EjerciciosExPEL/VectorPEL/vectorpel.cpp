#include <iostream>
using namespace std;

//------------------------------------------------------------------------------------------CLASS VECTORPEL
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

    void set(size_t i, T valor)
    {
        if (i >= size())
        {
            throw std::out_of_range("Fuera de rango");
        }
        v_[i] = valor;
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

    void readvector()
    {
        for (auto i = size_t{0}; i < size(); ++i)
        {
            cout << v_[i] << endl;
        }
    }

    void readObjectsInVector()
    {
        for (auto i = size_t{0}; i < size(); ++i)
        {
            cout << v_[i].to_string() << endl;
        }
    }

//METODO PARA INVERTIR EL VECTOR
    void invertirVector()
    {
        for (auto i = size_t{0}; i < size() / 2; ++i)
        {
            T aux = v_[i];
            v_[i] = v_[size() - 1 - i];
            v_[size() - 1 - i] = aux;
        }
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
    string getNombre()
    {
        return this->nombre;
    }
    string to_string()
    {
        return "Nombre: " + this->nombre + " Edad: " + std::to_string(this->edad);
    }
};
//------------------------------------------------------------------------------------------FUNCIONES EXTERNAS

// METODOS DE ORDENAR

// Función para ordenar un vector de números de menor a mayor
void sortVectorByNumber(VectorPEL<int> *v)
{
    for (auto i = size_t{0}; i < v->size(); ++i)
    {
        for (auto j = size_t{0}; j < v->size() - 1; ++j)
        {
            // Cambiar aqui a < para ordenar de mayor a menor y > para ordenar de menor a mayor
            //____________!____________
            if (v->get(j) > v->get(j + 1))
            {
                int aux = v->get(j);
                v->set(j, v->get(j + 1));
                v->set(j + 1, aux);
            }
        }
    }
};

// Función para ordenar un vector de personas por edad de menor a mayor
void sortByAge(VectorPEL<Persona> *v)
{
    for (auto i = size_t{0}; i < v->size(); ++i)
    {
        for (auto j = size_t{0}; j < v->size() - 1; ++j)
        {
            // Cambiar aqui a < para ordenar de mayor a menor y > para ordenar de menor a mayor
            //____________!____________
            if (v->get(j).getEdad() > v->get(j + 1).getEdad())
            {
                Persona aux = v->get(j);
                v->set(j, v->get(j + 1));
                v->set(j + 1, aux);
            }
        }
    }
};

// METODOS DE BUSQUEDA
//___________________________________________________________________________BUSCAR NUMERO
//Metodo buscar numero (bool)
template <typename T>
bool buscarNumeroBool(VectorPEL<T> *v, T numero)
{
    for (auto i = size_t{0}; i < v->size(); ++i)
    {
        if (v->get(i) == numero)
        {
            return true;
        }
    }
    return false;
}

//Metodo buscar numero (int)
template <typename T>
T buscarNumeroInt(VectorPEL<T> *v, T numero)
{
    for (auto i = size_t{0}; i < v->size(); ++i)
    {
        if (v->get(i) == numero)
        {
            return i;
        }
    }
    return -1;
}


//___________________________________________________________________________BUSCAR PERSONA
//Metodo buscar persona por nombre (bool)
template <typename T>
bool buscarPersonaBool(VectorPEL<T> *v, string nombre)
{
    for (auto i = size_t{0}; i < v->size(); ++i)
    {
        if (v->get(i).getNombre() == nombre)
        {
            return true;
        }
    }
    return false;
}

//Metodo buscar persona por nombre devolver obj
template <typename T>
T buscarPersonaObj(VectorPEL<T> *v, string nombre)
{
    for (auto i = size_t{0}; i < v->size(); ++i)
    {
        if (v->get(i).getNombre() == nombre)
        {
            return v->get(i);
        }
    }
    return T();
}



int main()
{
//------------------------------------------------------------------------------------------CON INT
    VectorPEL<int> *v = new VectorPEL<int>();
    v->push_back(4);
    v->push_back(2);
    v->push_back(1);
    v->push_back(3);
    sortVectorByNumber(v);

    // v->invertirVector();

    v->readvector();


    bool encontrado1 = buscarNumeroBool(v, 3);

    cout<< ((encontrado1)? "Encontrado num" : "No encontrado num" )<<"\n\n"<< endl;


//------------------------------------------------------------------------------------------CON OBJETO PERSONA 
    VectorPEL<Persona> *v2 = new VectorPEL<Persona>();
    v2->push_back(Persona("Maria", 40));
    v2->push_back(Persona("Luis", 50));
    v2->push_back(Persona("Juan", 20));
    v2->push_back(Persona("Pedro", 30));

   

   
   sortByAge(v2);

    //v2->invertirVector();

    v2->readObjectsInVector();

    bool encontrado = buscarPersonaBool(v2, "Luis");

    cout<< ((encontrado)? "Encontrado" : "No encontrado" )<< endl;

    cout <<"\n\n"<< buscarPersonaObj(v2, "dth").to_string() << endl;
}
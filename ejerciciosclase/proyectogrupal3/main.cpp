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

class Disco
{
public:
    string titulo;
    int precio;
    string dvdBluray;
    bool alquilado;

    Disco(string titulo, int precio, string dvdBluray, bool alquilado)
    {
        this->titulo = titulo;
        this->precio = precio;
        this->dvdBluray = dvdBluray;
        this->alquilado = alquilado;
    }

    Disco() {}

    ~Disco() {}
};

int main(int, char **)
{
    VectorPEL<Disco> *discos = new VectorPEL<Disco>;
    Disco d1("Avatar", 20, "DVD", false);
    Disco d2("2012", 10, "Blu-Ray", false);
    Disco d3("Narnia", 15, "DVD", false);
    Disco d4("Cars", 25, "Blu-ray", false);
    Disco d5("Megamind", 20, "DVD", false);
    discos->push_back(d1);
    discos->push_back(d2);
    discos->push_back(d3);
    discos->push_back(d4);
    discos->push_back(d5);

    int op = 4;
    string cadenaBuscar;

    while (op != 0)
    {
        cout << "\n - QUE QUIERES HACER? - ";
        cout << "\n - [0] SALIR - ";
        cout << "\n - [1] LISTA DE DVD/BLU-RAY SIN ALQUILAR - ";
        cout << "\n - [2] BUSCAR/ALQUILAR UN DVD/BLU-RAY - ";
        cout << "\n - [3] DEVOLVER UN DVD/BLU-RAY - ";
        cout << "\n Elija su opcion: " << endl;
        cin >> op;
        switch (op)
        {
        case (0):
            break;
        case (1):
            discos->print();
            break;
        case (2):
            cout << "Que disco quieres buscar? ";
            cin >> cadenaBuscar;
            discos->search(cadenaBuscar);
            break;
        case (3):
            cout << "Los discos que estan alquilados son: " << endl;
            discos->printTrue();
            cout << "Cual es el nombre del disco a devolver? ";
            cin >> cadenaBuscar;
            discos->returnMethod(cadenaBuscar);
            break;
        }
    }

    return 0;

    // APUNTES (IMPRIMIR DISCOS)
    /*
    for (auto i = size_t{0}; i < discos->size(); ++i)
    {
        Disco *aux0 = discos->begin() + i;
        cout << "\n";
        cout << aux0->titulo << " // " << aux0->precio << " // " << aux0->dvdBluray << endl;
    }
    */
}
#include <iostream>
using namespace std;
/* EJERCICIO
 * Desarrolla un programa usando la clase VectorPEL, al que se le pida al usuario introducir
 * por terminal tantas palabras como deseee. La operación debe detenerse si se encuentra
 * la palabra end. Una vez recibida dicha palabra, se mostrará el vector por consola.
 */

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
                for (auto i = size_t{0}; i < cp; ++i)
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
	
    T showdata(int n) { return v_[n];}
};
    
int main(int, char **)
{
    VectorPEL<string>* ej = new VectorPEL<string>;
    string cadena;
    int c;
    cout << "Escribe lo que quieras. Si escribes end, se acaba, y verás todo lo que has escrito: ";

    while (cadena != "end")
    {
        cin >> cadena;
        ej->push_back(cadena);
        ++c;
    };

    cout << "Resultado: ";
    for (auto i = 0; i < c; i++) {
        cout << ej->showdata(i) + " ";
    }
    
    return 0;
}
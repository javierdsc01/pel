#include <iostream>
using namespace std;

class Armadura
{
private:
    int id;
    int legion;

public:
    Armadura()
    {
        id = 0;
        legion = 0;
    }

    Armadura(int i, int l)
    {
        id = i;
        legion = l;
    }

    void mostrar()
    {
        cout << "\nID: " << id << endl;
        cout << "Legion: " << legion << endl;
    }

    int get_id()
    {
        return id;
    }

    int get_legion()
    {
        return legion;
    }
};

class Container
{
private:
    Armadura almacen[5];
    int num_elem;
public:
    // Container(): num_elem(0) {}
    Container()
    {
        num_elem = 0;
    }

    void insertar(Armadura a)
    {
        if (num_elem < 5)
        {
            almacen[num_elem] = a;
            num_elem++;
        }
        else
        {
            cout << "No se pueden insertar mas elementos" << endl;
        }
    }

    int getNumElem()
    {
        return num_elem;
    }

    Armadura extraer()
    {
        if (num_elem > 0)
        {
            num_elem--;
            return almacen[num_elem];
        }
        else
        {
            cout << "No se pueden extraer mas elementos" << endl;
            return Armadura();
        }
    }

    // Ordenar de menor a mayor
    void ordenar()
    {
        for (int i = 0; i < num_elem; i++)
        {
            for (int j = i + 1; j < num_elem; j++)
            {
                if (almacen[i].get_id() > almacen[j].get_id())
                {
                    intercambiar(i, j);
                }
            }
        }
    }

    void intercambiar(int a1, int a2)
    {
        Armadura aux = almacen[a1];
        almacen[a1] = almacen[a2];
        almacen[a2] = aux;
    }

    int get_elem()
    {
        return num_elem;
    }

    void recorrer()
    {
        for (int i = 0; i < num_elem; i++)
        {
            almacen[i].mostrar();
        }
    }
};

// Lista enlazada
class ArmoredLinkedList
{
protected:
    class NodoArmadura
    {
    public:
        Armadura dato;
        NodoArmadura *enlace;
        NodoArmadura(Armadura a)
        {
            dato = a;
            enlace = 0;
        }
    };

private:
    NodoArmadura *primero;

public:
    ArmoredLinkedList()
    {
        primero = 0;
    }

    // Insertar al final
    void insertar(Armadura a)
    {
        NodoArmadura *nuevo = new NodoArmadura(a);
        NodoArmadura *aux = primero;
        primero = nuevo;
        nuevo->enlace = aux;
    }

    bool buscarId(int id)
    {
        NodoArmadura *aux = primero;
        while (aux != 0)
        {
            if (aux->dato.get_id() == id)
            {
                return true;
            }
            aux = aux->enlace;
        }
        return false;
    }

    void recorrer()
    {
        cout << "Recorriendo la lista enlazada" << endl;
        NodoArmadura *aux = primero;
        while (aux != 0)
        {
            aux->dato.mostrar();
            aux = aux->enlace;
        }
    }

    //Metodo nuevo
    void ordenarPorLegion(){
        NodoArmadura *aux = primero;
        NodoArmadura *aux2 = primero;
        while (aux != 0)
        {
            while (aux2 != 0)
            {
                if (aux->dato.get_legion() > aux2->dato.get_legion())
                {
                    intercambiar(aux, aux2);
                }
                aux2 = aux2->enlace;
            }
            aux = aux->enlace;
        }
    }

    //Metodo nuevo
    void intercambiar(NodoArmadura *a1, NodoArmadura *a2)
    {
        Armadura aux = a1->dato;
        a1->dato = a2->dato;
        a2->dato = aux;
    }

    int get_size(){
        NodoArmadura *aux = primero;
        int cont = 0;
        while (aux != 0)
        {
            cont++;
            aux = aux->enlace;
        }
        return cont;
    }
};

void migrarDatos(Container &c, ArmoredLinkedList &l)
{
    while (c.getNumElem() > 0){
        l.insertar(c.extraer());
    }
}

int main(int, char **)
{

    // Declaramos las armaduras
    Armadura *a1 = new Armadura(5, 502);
    Armadura *a2 = new Armadura(15, 502);
    Armadura *a3 = new Armadura(16, 52);
    Armadura *a4 = new Armadura(25, 32);
    Armadura *a5 = new Armadura(33, 443);

    Armadura *a6 = new Armadura(35, 88);
    Armadura *a7 = new Armadura(37, 43);
    Armadura *a8 = new Armadura(40, 342);
    Armadura *a9 = new Armadura(41, 324);
    Armadura *a10 = new Armadura(42, 324);

    Armadura *a11 = new Armadura(44, 342);
    Armadura *a12 = new Armadura(48, 456);
    Armadura *a13 = new Armadura(50, 53);
    Armadura *a14 = new Armadura(85, 34);

    Container *c1 = new Container();
    Container *c2 = new Container();
    Container *c3 = new Container();

    // Insertamos las armaduras en los contenedores
    c1->insertar(*a4);
    c1->insertar(*a2);
    c1->insertar(*a7);
    c1->insertar(*a4);
    c1->insertar(*a5);

    c2->insertar(*a7);
    c2->insertar(*a6);
    c2->insertar(*a8);
    c2->insertar(*a9);
    c2->insertar(*a11);

    c3->insertar(*a11);
    c3->insertar(*a12);
    c3->insertar(*a13);
    c3->insertar(*a14);

    // Ordenamos los contenedores
    c1->ordenar();
    c2->ordenar();
    c3->ordenar();

    // Mostrar
    c1->recorrer();

    ArmoredLinkedList *l1 = new ArmoredLinkedList();
    
    c1->ordenar();
    c2->ordenar();
    c3->ordenar();

    // Migrar datos
    migrarDatos(*c1, *l1);
    migrarDatos(*c2, *l1);
    migrarDatos(*c3, *l1);

    // Ordenar
    l1->ordenarPorLegion();

    // Mostrar
    l1->recorrer();


    cout << ((l1->buscarId(5)) ? "Si encontrado " : "No") << endl;
    
    return 0;
}
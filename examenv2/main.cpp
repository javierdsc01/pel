#include <iostream>
using namespace std;

class Poder{
private:
    int id;
    string nombre;
    string desc;
    int tipo; //Incremento = 1; Psionicas = 2; Aberrantes = 3;

public:
    Poder(){}

    Poder(int idConst, string nombreConst, string descConst, int tipoConst)
    {
        this->id = idConst;
        this->nombre = nombreConst;
        this->desc = descConst;
        this->tipo = tipoConst;
    }

    void mostrar()
    {
        cout << "\nID: " << id << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Descripcion: " << desc << endl;
        cout << "Tipo: (Incremento = 1; Psionicas = 2; Aberrantes = 3)" << tipo << endl;
    }
};

template <typename T>
class Grupo{
private:
    T grupoClasif[5];
    int num_elem;
public:
    Grupo(){
        num_elem = 0;
    }

    void insertar(T p){
        if(num_elem < 5){
            grupoClasif[num_elem] = p;
        }
        else
        {
            cout << "No se pueden meter más elementos" << endl;
        }
    }

    T extraer()
    {
        if (num_elem > 0)
        {
            num_elem--;
            return grupoClasif[num_elem];
        }
        else
        {
            cout << "No se pueden extraer mas elementos" << endl;
            return T();
        }
    }

    int get_num_elem()
    {
        return num_elem;
    }

    void recorrer() {
        for (int i = 0; i < 5; i++)
        {
            grupoClasif[i].mostrar();
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

    void recorrer()
    {
        cout << "Recorriendo la lista enlazada" << endl;
        T *aux = primero;
        while (aux != 0)
        {
            aux->dato.mostrar();
            aux = aux->enlace;
        }
    }
};

class Superhumano{
private:
    int id;
    string nombre;
    ListaEnlazada<Poder> poder;
    int virtuoso_perverso; //Virtuoso = 0, Perverso = 1;
public:
    Superhumano(){}

    Superhumano(int idConst, string nombreConst, ListaEnlazada<Poder> poderConst, int virtuoso_perversoConst){
        this->id = idConst;
        this->nombre = nombreConst;
        this->poder = poderConst;
        this->virtuoso_perverso = virtuoso_perversoConst;
    }

    string toString(){
        // cout << "Superhumano con ID: " << id << " con los poderes: " << poder << "es (Virtuoso 0 / Perverso 1): " << virtuoso_perverso;
    }
};

int main(int, char **) {
    cout << "Examen Final" << endl;

    Poder *p1 = new Poder(0, "Factor de curación","Capacidad de sanarse rápidamente y con mayor firmeza de cualquier lesión", 1);
    Poder *p2 = new Poder(1,"Zoomorfismo", "Habilidad de asumir la capacidad y la forma de ciertos animales", 1);
    Poder *p3 = new Poder(2, "Manipulación de los huesos", "Habilidad de manipular los huesos de su propio cuerpo", 1);
    Poder *p4 = new Poder(3, "Duplicación", "Capacidad de crear duplicados físicos de uno mismo", 1);
    Poder *p5 = new Poder(4, "Ecolocación", "Capacidad para determinar la ubicación de los objetos en el medio ambiente por el uso de ondas sonoras", 1);

    Poder *p6 = new Poder(5, "Invisibilidad", "Habilidad de hacer que el usuario sea invisible a simple vista", 2);
    Poder *p7 = new Poder(6, "Invulnerabilidad", "Capacidad de ser inmune a una o más formas de daño", 3);
    Poder *p8 = new Poder(7, "Ingestión de materia", "Capacidad de consumir cualquier tipo de materia sin que tenga ningún efecto negativo sobre la persona", 1);
    Poder *p9 = new Poder(8, "Generador de toxinas", "Habilidad de asaltar a otros con una o más variedades de toxinas", 1);
    Poder *p10 = new Poder(9, "Adaptación reactiva", "Capacidad para desarrollar una resistencia o inmunidad a cualquier cosa que resultara herida o este expuesto a herirse", 1);

    Poder *p11 = new Poder(10, "Grito sónico", "Capacidad para generar sonidos vocales de una amplitud mayor a la de un humano normal", 1);
    Poder *p12 = new Poder(11, "Resistencia sobrehumana", "Capacidad para tener una mayor resistencia a una o más formas de daño antes de ser herido o realizar actividades indefinidamente sin cansarse", 1);
    Poder *p13 = new Poder(12, "Agilidad sobrehumana", "Capacidad para reaccionar más rápido que un humano normal o poseer una mayor flexibilidad o tener la habilidad de saltar más alto", 1);
    Poder *p14 = new Poder(13, "Superfuerza", "Habilidad de tener un nivel de fuerza física mucho más alto que lo normalmente posible dada su calidad y cantidad muscular", 1);
    Poder *p15 = new Poder(14, "Visión de rayos X", "Capacidad de ver a través de materia sólida", 2);

    Poder *p16 = new Poder(15, "Visión caliente", "Capacidad de quemar objetos con la mirada", 2);
    Poder *p17 = new Poder(16, "Inmortalidad", "La capacidad de vivir para siempre", 3);
    Poder *p18 = new Poder(17, "Omnisciencia", "Habilidad de saberlo todo", 3);
    Poder *p19 = new Poder(18, "Proyección astral", "Capacidad para separar el cuerpo astral del cuerpo burdo y controlarlo", 2);
    Poder *p20 = new Poder(19, "Precognición", "Capacidad de percibir el futuro", 2);

    Poder *p21 = new Poder(20, "Telepatía", "Capacidad para leer los pensamientos de los demás", 2);
    Poder *p22 = new Poder(21, "Posesión", "Capacidad para tomar el control y habitar el cuerpo de un individuo.", 2);
    Poder *p23 = new Poder(22, "Armas psíquicas", "Capacidad para crear un arma de energía psíquica que no puede hacer daño físicamente pero si mentalmente.", 2);
    Poder *p24 = new Poder(23, "Umbraquinesis", "Capacidad de crear o manipular la oscuridad", 2);
    Poder *p25 = new Poder(24, "Velocidad sobrehumana", "Capacidad para moverse y sentir a una velocidad mucho más rápido que un humano normal", 1);

    Poder *p26 = new Poder(26, "Teleportación", "Capacidad de moverse de un lugar a otro de forma inmediata y sin ocupar el espacio en el medio", 2);
    Poder *p27 = new Poder(27, "Viaje a través del tiempo", "Capacidad para viajar adelante o atrás en el tiempo. En ocasiones puede permitir el viaje a realidades alternativas", 3);
    Poder *p28 = new Poder(28, "Creación de portales", "Capacidad de crear agujeros de gusano o similar", 2);
    Poder *p29 = new Poder(29, "Omnipresencia", "Capacidad de estar presente en cualquier lugar y simultáneamente al mismo tiempo", 3);
    Poder *p30 = new Poder(30, "Cronoquinesis", "Capacidad de afectar el flujo del tiempo", 3);

    Grupo<Poder> *g1 = new Grupo<Poder>();
    Grupo<Poder> *g2 = new Grupo<Poder>();
    Grupo<Poder> *g3 = new Grupo<Poder>();
    Grupo<Poder> *g4 = new Grupo<Poder>();
    Grupo<Poder> *g5 = new Grupo<Poder>();
    Grupo<Poder> *g6 = new Grupo<Poder>();

    g1->insertar(*p1);
    g1->insertar(*p2);
    g1->insertar(*p3);
    g1->insertar(*p4);
    g1->insertar(*p5);

    g2->insertar(*p6);
    g2->insertar(*p7);
    g2->insertar(*p8);
    g2->insertar(*p9);
    g2->insertar(*p10);

    g3->insertar(*p11);
    g3->insertar(*p12);
    g3->insertar(*p13);
    g3->insertar(*p14);
    g3->insertar(*p15);

    g4->insertar(*p16);
    g4->insertar(*p17);
    g4->insertar(*p18);
    g4->insertar(*p19);
    g4->insertar(*p20);

    g5->insertar(*p21);
    g5->insertar(*p22);
    g5->insertar(*p23);
    g5->insertar(*p24);
    g5->insertar(*p25);

    g6->insertar(*p26);
    g6->insertar(*p27);
    g6->insertar(*p28);
    g6->insertar(*p29);
    g6->insertar(*p30);

    ListaEnlazada<Poder> *sp1 = new ListaEnlazada<Poder>;
    ListaEnlazada<Poder> *sp2 = new ListaEnlazada<Poder>;
    ListaEnlazada<Poder> *sp3 = new ListaEnlazada<Poder>;
    ListaEnlazada<Poder> *sp4 = new ListaEnlazada<Poder>;
    ListaEnlazada<Poder> *sp5 = new ListaEnlazada<Poder>;
    ListaEnlazada<Poder> *sp6 = new ListaEnlazada<Poder>;
    ListaEnlazada<Poder> *sp7 = new ListaEnlazada<Poder>;
    ListaEnlazada<Poder> *sp8 = new ListaEnlazada<Poder>;
    ListaEnlazada<Poder> *sp9 = new ListaEnlazada<Poder>;
    ListaEnlazada<Poder> *sp10 = new ListaEnlazada<Poder>;

    sp1->push(*p1);
    sp1->push(*p14);
    sp1->push(*p12);

    sp2->push(*p2);

    sp3->push(*p3);

    sp4->push(*p4);
    sp4->push(*p20);
    sp4->push(*p21);
    sp4->push(*p22);
    sp4->push(*p19);
    sp4->push(*p26);
    sp4->push(*p28);

    sp5->push(*p7);
    sp5->push(*p10);
    sp5->push(*p14);
    sp5->push(*p12);
    sp5->push(*p13);

    sp6->push(*p7);
    sp6->push(*p10);
    sp6->push(*p14);
    sp6->push(*p12);
    sp6->push(*p13);
    sp6->push(*p16);
    sp6->push(*p15);

    sp7->push(*p17);

    sp8->push(*p18);
    sp8->push(*p29);

    sp9->push(*p25);
    sp9->push(*p27);
    sp9->push(*p30);

    sp10->push(*p4);
    sp10->push(*p20);
    sp10->push(*p21);
    sp10->push(*p22);
    sp10->push(*p19);
    sp10->push(*p26);
    sp10->push(*p28);
    sp10->push(*p23);
    sp10->push(*p27);
    sp10->push(*p30);


    Superhumano *s1 = new Superhumano(100, "Wolverine", *sp1, 0);
    Superhumano *s2 = new Superhumano(101, "Beastboy", *sp2, 0);
    Superhumano *s3 = new Superhumano(102, "Kimimaro", *sp3, 1);
    Superhumano *s4 = new Superhumano(103, "Scarlett Witch", *sp4, 1);
    Superhumano *s5 = new Superhumano(104, "BlackAdam", *sp5, 1);
    Superhumano *s6 = new Superhumano(105, "Superman", *sp6, 0);
    Superhumano *s7 = new Superhumano(106, "Jack Harness", *sp7, 0);
    Superhumano *s8 = new Superhumano(107, "Eternidad", *sp8, 1);
    Superhumano *s9 = new Superhumano(108, "Reverse Flash", *sp9, 1);
    Superhumano *s10 = new Superhumano(109, "Doctor Extrange", *sp10, 0);

    Grupo<Superhumano> *gsp1 = new Grupo<Superhumano>;
    Grupo<Superhumano> *gsp2 = new Grupo<Superhumano>;

    gsp1->insertar(*s1);
    gsp1->insertar(*s2);
    gsp1->insertar(*s3);
    gsp1->insertar(*s4);
    gsp1->insertar(*s5);

    gsp2->insertar(*s6);
    gsp2->insertar(*s7);
    gsp2->insertar(*s8);
    gsp2->insertar(*s9);
    gsp2->insertar(*s10);

    cout << " ---- MENU ----" << endl;
    cout << "\n[0] SALIR" << endl;
    cout << "\n[1] MOSTRAR PODERES" << endl;
    cout << "\n[2] CREAR PODERES" << endl;
    cout << "\n[3] CREAR GRUPO DE PODERES" << endl;
    cout << "\n[4] ALMACENAR PODERES" << endl;
    int iMenu;
    bool bRet;
    cin >> iMenu;
    Poder *p = new Poder();

    switch(iMenu){
        case 1:{
            g1->recorrer();
            g2->recorrer();
            g3->recorrer();
            g4->recorrer();
            g5->recorrer();
            g6->recorrer();
        }
        case 2:{
            string nombre, desc;
            int tipo;
            cout << "Inserta un nombre para el poder" << endl;
            cin >> nombre;
            cout << "Inserta una descripcion para el poder" << endl;
            cin >> desc;
            cout << "Inserta un tipo para el poder (Incremento = 1; Psionicas = 2; Aberrantes = 3)" << endl;
            cin >> tipo;

            Poder *p = new Poder(333, nombre, desc, tipo);
        }
        case 3:{
            Grupo<Poder> *g5 = new Grupo<Poder>;
        }
        case 4:{
            g5->insertar(*p);
        }
    }



}
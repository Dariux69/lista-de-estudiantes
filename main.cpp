#include <iostream>
#include <string>

using namespace std;

//clase estudiante
class Estudiante {
private:
    string nombre;
    float notaFinal;

public:
    Estudiante(string nombre, float notaFinal) {
        this->nombre = nombre;
        this->notaFinal = notaFinal;
    }

    float tomarNota() const {
        return notaFinal;
    }

    void imprimir() const {
        cout << "Nombre: " << nombre
             << "  Nota final: " << notaFinal << endl;
    }
};
//nodo
struct Nodo {
    Estudiante estudiante;
    Nodo* siguiente;

    Nodo(Estudiante e) : estudiante(e), siguiente(nullptr) {}
};

//lista enlazada
class ListaEnlazada {
private:
    Nodo* head;

public:
    ListaEnlazada() {
        head = nullptr;
    }

    void agregarEstudiante(string nombre, float nota) {
        Estudiante e(nombre, nota);
        Nodo* nuevo = new Nodo(e);

        if (head == nullptr) {
            head = nuevo;
        } else {
            Nodo* aux = head;
            while (aux->siguiente != nullptr) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
        }
    }

    void imprimirLista() {
        Nodo* aux = head;
        while (aux != nullptr) {
            aux->estudiante.imprimir();
            aux = aux->siguiente;
        }
    }
};




int main() {
    return 0;
}

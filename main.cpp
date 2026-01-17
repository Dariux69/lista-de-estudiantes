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

    float getNota() const {
        return notaFinal;
    }

    void imprimir() const {
        cout << "Nombre: " << nombre
             << " | Nota final: " << notaFinal << endl;
    }
};

//nodo de la lista
struct Nodo {
    Estudiante estudiante;
    Nodo* siguiente;

    Nodo(Estudiante e) : estudiante(e), siguiente(nullptr) {}
};

//lista enlazada
class ListaEnlazada {
private:
    Nodo* head;

    //funcion recursiva
    float sumarNotasRecursivo(Nodo* nodo, int& contador) {
        if (nodo == nullptr) {
            return 0;
        }

        contador++;
        return nodo->estudiante.getNota() +
               sumarNotasRecursivo(nodo->siguiente, contador);
    }

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

    //promedio usando recursividad 
    float calcularPromedioRecursivo() {
        int contador = 0;
        float suma = sumarNotasRecursivo(head, contador);

        if (contador == 0) {
            return 0;
        }

        return suma / contador;
    }
};

//main
int main() {
    ListaEnlazada lista;

    lista.agregarEstudiante("Ana", 8.5);
    lista.agregarEstudiante("Carlos", 7.8);
    lista.agregarEstudiante("Maria", 9.2);

    cout << "Lista de estudiantes:\n";
    lista.imprimirLista();

    cout << "Promedio de notas: "
         << lista.calcularPromedioRecursivo() << endl;

    return 0;
}


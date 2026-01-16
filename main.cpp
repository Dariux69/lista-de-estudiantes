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

int main() {
    return 0;
}

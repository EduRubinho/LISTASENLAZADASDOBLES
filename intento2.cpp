#include <thread>
#include <iostream>
using namespace std;

int turno = 0;
void P0() {
    while (true) {
        while (turno == 1) {}
        cout << "Entrando en la seccion critica de P0" << endl;
        turno = 1;
        cout << "Saliendo de la seccion critica de P0" << endl;
    }
}

void P1() {
    while (true) {
        while (turno == 0) {}
        cout << "Entrando en la seccion critica de P1" << endl;
        turno = 0;
        cout << "Saliendo de la seccion critica de P1" << endl;
    }
}

int main() {
    thread t0(P0);
    thread t1(P1);

    t0.join();
    t1.join();

    return 0;
}
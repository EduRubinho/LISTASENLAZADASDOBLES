#include <thread>
#include <iostream>
using namespace std;

bool C0 = false;
bool C1 = false;
int turno = 0;

void P0() {
    while (true) {
        C0 = true;
        turno = 1;
        while (C1 && turno == 1) {}
        cout << "P0 esta ejecutando su seccion critica" << endl;
        C0 = false;
    }
}

void P1() {
    while (true) {
        C1 = true;
        turno = 0;
        while (C0 && turno == 0) {}
        cout << "P1 esta ejecutando su seccion critica" << endl;
        C1 = false;
    }
}

int main() {
    thread t0(P0);
    thread t1(P1);

    t0.join();
    t1.join();

    return 0;
}
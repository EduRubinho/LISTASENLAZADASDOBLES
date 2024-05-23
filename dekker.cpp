#include <thread>
#include <iostream>
using namespace std;

bool C0 = false;
bool C1 = false;
int turno = 0;
void P0() {
    while (true) {
        C0 = true;
        while (C1) {
            if (turno == 1) {
                C0 = false;
                while (turno == 1) {}
                C0 = true;
            }
        }
        cout << "P0 esta ejecutando su seccion critica" << endl;
        turno = 1;
        C0 = false;
    }
}

void P1() {
    while (true) {
        C1 = true;
        while (C0) {
            if (turno == 0) {
                C1 = false;
                while (turno == 0) {}
                C1 = true;
            }
        }
        cout << "P1 esta ejecutando su seccion critica" << endl;
        turno = 0;
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
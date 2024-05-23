#include <thread>
#include <iostream>
using namespace std;

bool C0 = false;
bool C1 = false;

void P0() {
    while (true) {
        while (C1 == 1) {}
        C0 = 1;
        cout << "P0 esta ejecutando su seccion critica" << endl;
        C0 = 0;
    }
}

void P1() {
    while (true) {
        while (C0 == 1) {}
        C1 = 1;
        cout << "P1 esta ejecutando su seccion critica" << endl;
        C1 = 0;
    }
}

int main() {
    thread t0(P0);
    thread t1(P1);

    t0.join();
    t1.join();

    return 0;
}
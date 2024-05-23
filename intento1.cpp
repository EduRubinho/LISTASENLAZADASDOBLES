#include <thread>
#include <iostream>
using namespace std;    
bool v = false;

void P0() {
    while (true) {
        while (v == true) {}
        v = true;
        cout << "Seccion critica del proceso P0" << std::endl;
        v = false;
    }
}

void P1() {
    while (true) {
        while (v == true) {}
        v = true;
        cout << "Seccion critica del proceso P1" << std::endl;
        v = false;
    }
}

int main() {
    thread t0(P0);
    thread t1(P1);

    t0.join();
    t1.join();

    return 0;
}
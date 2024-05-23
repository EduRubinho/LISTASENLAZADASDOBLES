#include <iostream>
#include <thread>

using namespace std;

bool flag1 = false;
bool flag2 = false;
int turno = 1;
int suma = 0;

void P0() {
    while (true) {
        flag1 = true;
        while (turno != 1) {
            while (flag2) {
        }
        turno = 1;
        }   
        suma++;
        cout << "Turno1-" << suma << endl;
        flag1 = false;
    }
}

void P1() {
    while (true) {
        flag2 = true;
        while (turno != 2) {
            while (flag1) {
        }
        turno = 2;
        }
        suma++;
        cout << "Turno2-" << suma << endl;
        flag2 = false;
    }
}

int main() {
    thread t1(P0);
    thread t2(P1);

    t1.join();
    t2.join();

    return 0;
}
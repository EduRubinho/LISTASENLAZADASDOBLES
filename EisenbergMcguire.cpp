#include <iostream>
#include <thread>

using namespace std;

const int N = 2;
int S[N+1];
int turno;
int x;

void Proceso(int i) {
    int j;
    while (true) {
        S[i] = 1;
        j = turno;
        while (j != i) {
            if (S[j] != 3)
                j = turno;
            else
                j = (j + 1) % N;
        }
        S[i] = 2;
        j = 0;
        while ((j < N) && ((j == i) || (S[j] != 2)))
            j++;
        if ((j >= N) && ((turno == i) || (S[turno] == 3))) {
            turno = i;
            x = x + i;
            cout << "P" << i << " x = " << x << endl;
            j = (turno + 1) % N;
            while (S[j] == 3)
                j = (j + 1) % N;
            turno = j;
            S[i] = 3;
        }
    }
}

int main() {
    for (int i = 0; i <= N; i++)
        S[i] = 3;
    turno = rand() % N;
    x = 0;
    cout << "Turno inicial = " << turno << endl;
    thread threads[N+1];
    for (int i = 0; i <= N; i++)
        threads[i] = thread(Proceso, i);
    for (int i = 0; i <= N; i++)
        threads[i].join();
    return 0;
}
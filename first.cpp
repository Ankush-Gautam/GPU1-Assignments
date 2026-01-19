#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

#define N 1000

double get_time() {
    return chrono::duration<double>(chrono::high_resolution_clock::now().time_since_epoch()).count();
}

int main() {
    double **A, **B, **C;
    double start, end;

    A = new double*[N];
    B = new double*[N];
    C = new double*[N];

    for (int i = 0; i < N; i++) {
        A[i] = new double[N];
        B[i] = new double[N];
        C[i] = new double[N];
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 1.0;
            C[i][j] = 0.0;
        }

    start = get_time();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
    end = get_time();

    cout << "Serial Execution Time: " << end - start << " seconds\n";

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = 0.0;

    start = get_time();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
    end = get_time();

    cout << "OpenMP Static Scheduling Time: " << end - start << " seconds\n";

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = 0.0;

    start = get_time();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
    end = get_time();

    cout << "OpenMP Dynamic Scheduling Time: " << end - start << " seconds\n";

    return 0;
}

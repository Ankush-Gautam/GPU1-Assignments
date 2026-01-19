#include <iostream>
#include <chrono>

using namespace std;

double get_time() {
    return chrono::duration<double>(chrono::high_resolution_clock::now().time_since_epoch()).count();
}

int main() {
    double start, end;

    start = get_time();

    {
        int tid = 0;
        cout << "Thread " << tid << " printing series of 2:\n";
        for (int i = 2; i <= 20; i += 2) {
            cout << i << " ";
        }
        cout << endl;
    }

    {
        int tid = 0;
        cout << "Thread " << tid << " printing series of 4:\n";
        for (int i = 4; i <= 40; i += 4) {
            cout << i << " ";
        }
        cout << endl;
    }

    end = get_time();

    cout << "Total Execution Time: " << end - start << " seconds\n";

    return 0;
}

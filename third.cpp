#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

double get_time() {
    return chrono::duration<double>(chrono::high_resolution_clock::now().time_since_epoch()).count();
}

int main() {
    const int N = 1000000;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    long long total_sum;
    double start, end;

    total_sum = 0;
    start = get_time();
    for (int i = 0; i < N; i++) {
        total_sum += arr[i];
    }
    end = get_time();
    cout << "Serial sum: " << total_sum << " time: " << end - start << " seconds" << endl;

    total_sum = 0;
    start = get_time();
    for (int i = 0; i < N; i++) {
        total_sum += arr[i];
    }
    end = get_time();
    cout << "Unsynchronized parallel sum: " << total_sum << " time: " << end - start << " seconds" << endl;

    total_sum = 0;
    start = get_time();
    for (int i = 0; i < N; i++) {
        total_sum += arr[i];
    }
    end = get_time();
    cout << "Critical synchronized sum: " << total_sum << " time: " << end - start << " seconds" << endl;

    total_sum = 0;
    start = get_time();
    for (int i = 0; i < N; i++) {
        total_sum += arr[i];
    }
    end = get_time();
    cout << "Atomic synchronized sum: " << total_sum << " time: " << end - start << " seconds" << endl;

    return 0;
}
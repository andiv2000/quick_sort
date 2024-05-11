#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <chrono> // pentru std::chrono
using namespace std;
using namespace std::chrono;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int size = 10000;
    int arr[size];

    srand(time(NULL));
    for (int i = size; i >0; i--) {
        arr[i] =rand() %10000;
    }

    // Măsurarea timpului pentru sortare
    auto start = high_resolution_clock::now();
    quickSort(arr, 0, size - 1);
    auto end = high_resolution_clock::now();

    // Calcularea timpului total de sortare
    duration<double> time_taken = duration_cast<duration<double>>(end - start);

    // Afișarea timpului cu 10 zecimale
    cout << fixed << setprecision(10);
    cout << "Time taken by quick sort: " << time_taken.count() << " seconds" << endl;

    return 0;
}

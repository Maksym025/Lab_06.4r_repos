#include <iostream>
#include <time.h>
using namespace std;

void CreateArray(int* arr, const int size, const int Low, const int High, int index = 0) {
    if (index < size) {
        arr[index] = Low + rand() % (High - Low + 1);
        CreateArray(arr, size, Low, High, index + 1); 
    }
}

int FindMaxIndex(const int* arr, const int size, int index = 1, int maxIndex = 0) {
    if (index == size) {
        return maxIndex; 
    }
    if (arr[index] > arr[maxIndex]) {
        maxIndex = index; 
    }
    return FindMaxIndex(arr, size, index + 1, maxIndex);
}

int ProductBetweenZeros(const int* arr, const int size, int index = 0, int firstZero = -1, int product = 1) {
    if (index == size) {
        return (firstZero != -1 && product != 1) ? product : 0; 
    }
    if (arr[index] == 0) {
        if (firstZero == -1) {
            return ProductBetweenZeros(arr, size, index + 1, index, product);
        }
        else {
            return product;
        }
    }
    if (firstZero != -1) {
        product *= arr[index]; 
    }
    return ProductBetweenZeros(arr, size, index + 1, firstZero, product); 
}

void TransformArray(int* arr, int* temp, const int size, int index = 0, int oddIndex = 0, int evenIndex = 0) {
    if (index == size) {
        for (int i = 0; i < size; i++) {
            arr[i] = temp[i]; 
        }
        return; 
    }

    if (index % 2 == 0) {
        temp[size / 2 + evenIndex++] = arr[index];
    }
    else {
        temp[oddIndex++] = arr[index];
    }

    TransformArray(arr, temp, size, index + 1, oddIndex, evenIndex); 
}

int main() {
    srand((unsigned)time(NULL));

    int n;
    cout << "Enter the size of the array (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Size must be positive." << endl;
        return 1;
    }

    int* arr = new int[n];
    int Low = 0;
    int High = 10;

    CreateArray(arr, n, Low, High); 

    cout << "Original array:    ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 1.1. Знаходимо номер максимального елемента рекурсивно
    int maxIndex = FindMaxIndex(arr, n);
    cout << "Index of the maximum element: " << maxIndex << endl;

    // 1.2. Обчислюємо добуток елементів між першим і другим нулями рекурсивно
    int product = ProductBetweenZeros(arr, n);
    cout << "Product of elements between the first and second zeroes: " << product << endl;

    // 2. Перетворюємо масив рекурсивно
    int* temp = new int[n];
    TransformArray(arr, temp, n);

    cout << "Transformed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] temp;

    return 0;
}

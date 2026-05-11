#include "sorts.h"

void selectionSort(int* ar, unsigned int size, bool ascending) {
    for (unsigned int i = 0; i < size - 1; ++i) {
        unsigned int targetIndex = i;
        for (unsigned int j = i + 1; j < size; ++j) {
            if (ascending) {
                if (ar[j] < ar[targetIndex]) {
                    targetIndex = j;
                }
            }
            else {
                if (ar[j] > ar[targetIndex]) {
                    targetIndex = j;
                }
            }
        }
        // Swap ar[i] and ar[targetIndex]
        int temp = ar[i];
        ar[i] = ar[targetIndex];
        ar[targetIndex] = temp;
    }
}

int isSorted(const int* array, unsigned int size) {
    if (size <= 1) {
        return 1; // Массив из 0 или 1 элемента считается отсортированным по возрастанию
    }

    bool isI = true;
    bool isD = true;

    for (unsigned int i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            isI = false;
        }
        if (array[i] < array[i + 1]) {
            isD = false;
        }
    }

    if (isI) return 1;
    if (isD) return -1;
    return 0;
}
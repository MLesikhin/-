#include "sorts.h"
#include <algorithm>

// Реализация компараторов
bool defaultComp(int a, int b) {
    return a < b;
}

bool reverseComp(int a, int b) {
    return a > b;
}

// Вспомогательная функция обмена
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Пузырьковая сортировка (Bubble Sort) — O(n²)
void bubbleSort(int* ar, int size, bool (*comp)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (!comp(ar[j], ar[j + 1]) && ar[j] != ar[j + 1]) {
                swap(ar[j], ar[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // оптимизация: выход если массив отсортирован
    }
}

// Сортировка выбором (Selection Sort) — O(n²)
void selectionSort(int* ar, int size, bool (*comp)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        int extremum_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (!comp(ar[extremum_idx], ar[j])) {
                extremum_idx = j;
            }
        }
        if (extremum_idx != i) {
            swap(ar[i], ar[extremum_idx]);
        }
    }
}

// Сортировка вставками (Insertion Sort) — O(n²)
void insertionSort(int* ar, int size, bool (*comp)(int, int)) {
    for (int i = 1; i < size; i++) {
        int key = ar[i];
        int j = i - 1;
        while (j >= 0 && !comp(ar[j], key)) {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = key;
    }
}

// Сортировка слиянием (Merge Sort) — вспомогательные функции
void merge(int* ar, int left, int mid, int right, bool (*comp)(int, int)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int* L = new int[n1];
    int* R = new int[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = ar[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = ar[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (comp(L[i], R[j])) {
            ar[k] = L[i];
            i++;
        } else {
            ar[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        ar[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        ar[k] = R[j];
        j++;
        k++;
    }
    
    delete[] L;
    delete[] R;
}

void mergeSortHelper(int* ar, int left, int right, bool (*comp)(int, int)) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(ar, left, mid, comp);
        mergeSortHelper(ar, mid + 1, right, comp);
        merge(ar, left, mid, right, comp);
    }
}

// Сортировка слиянием — O(n log n)
void mergeSort(int* ar, int size, bool (*comp)(int, int)) {
    if (size <= 1) return;
    mergeSortHelper(ar, 0, size - 1, comp);
}

// Быстрая сортировка (Quick Sort / сортировка Хоара) — вспомогательные функции
int partition(int* ar, int left, int right, bool (*comp)(int, int)) {
    int pivot = ar[right];
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        if (comp(ar[j], pivot)) {
            i++;
            swap(ar[i], ar[j]);
        }
    }
    swap(ar[i + 1], ar[right]);
    return i + 1;
}

void quickSortHelper(int* ar, int left, int right, bool (*comp)(int, int)) {
    if (left < right) {
        int pi = partition(ar, left, right, comp);
        quickSortHelper(ar, left, pi - 1, comp);
        quickSortHelper(ar, pi + 1, right, comp);
    }
}

// Быстрая сортировка — O(n log n) в среднем, O(n²) в худшем
void quickSort(int* ar, int size, bool (*comp)(int, int)) {
    if (size <= 1) return;
    quickSortHelper(ar, 0, size - 1, comp);
}

// Сортировка Шелла (Shell Sort) — O(n log² n) до O(n^(4/3))
void sortShell(int* ar, int size, bool (*comp)(int, int)) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = ar[i];
            int j;
            for (j = i; j >= gap && !comp(ar[j - gap], temp); j -= gap) {
                ar[j] = ar[j - gap];
            }
            ar[j] = temp;
        }
    }
}

// Сортировка подсчётом (Counting Sort) — O(n + k)
void countSort(int* ar, int size, bool (*comp)(int, int)) {
    if (size <= 0) return;
    
    // Находим минимум и максимум
    int min_val = ar[0], max_val = ar[0];
    for (int i = 1; i < size; i++) {
        if (ar[i] < min_val) min_val = ar[i];
        if (ar[i] > max_val) max_val = ar[i];
    }
    
    int range = max_val - min_val + 1;
    int* count = new int[range]();
    int* output = new int[size];
    
    // Подсчёт элементов
    for (int i = 0; i < size; i++) {
        count[ar[i] - min_val]++;
    }
    
    // Модифицируем count в зависимости от направления сортировки
    if (comp(1, 2)) { // По возрастанию
        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }
        for (int i = size - 1; i >= 0; i--) {
            output[count[ar[i] - min_val] - 1] = ar[i];
            count[ar[i] - min_val]--;
        }
    } else { // По убыванию
        for (int i = range - 2; i >= 0; i--) {
            count[i] += count[i + 1];
        }
        for (int i = size - 1; i >= 0; i--) {
            int pos = count[ar[i] - min_val] - 1;
            output[pos] = ar[i];
            count[ar[i] - min_val]--;
        }
    }
    
    // Копируем результат обратно
    for (int i = 0; i < size; i++) {
        ar[i] = output[i];
    }
    
    delete[] count;
    delete[] output;
}

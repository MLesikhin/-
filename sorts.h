#ifndef SORTS_H
#define SORTS_H

// Функции-компараторы
bool defaultComp(int a, int b);   // по возрастанию
bool reverseComp(int a, int b);   // по убыванию

// Прототипы функций сортировок
void bubbleSort(int* ar, int size, bool (*comp)(int, int));      // пузырьковая сортировка
void selectionSort(int* ar, int size, bool (*comp)(int, int));   // сортировка выбором
void insertionSort(int* ar, int size, bool (*comp)(int, int));   // сортировка вставками
void mergeSort(int* ar, int size, bool (*comp)(int, int));       // сортировка слиянием
void quickSort(int* ar, int size, bool (*comp)(int, int));       // быстрая сортировка (Хоара)
void sortShell(int* ar, int size, bool (*comp)(int, int));       // сортировка Шелла
void countSort(int* ar, int size, bool (*comp)(int, int));       // сортировка подсчётом

// Вспомогательные функции для сортировок
void swap(int& a, int& b);
void merge(int* ar, int left, int mid, int right, bool (*comp)(int, int));
void mergeSortHelper(int* ar, int left, int right, bool (*comp)(int, int));
int partition(int* ar, int left, int right, bool (*comp)(int, int));
void quickSortHelper(int* ar, int left, int right, bool (*comp)(int, int));

#endif // SORTS_H

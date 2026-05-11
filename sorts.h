#ifndef SORTS_H
#define SORTS_H

// Сортировка выбором с возможностью задания направления
// ar - указатель на массив
// size - размер массива
// ascending - если true, сортировка по возрастанию; иначе по убыванию
void selectionSort(int* ar, unsigned int size, bool ascending);

// Проверка отсортированности массива
// Возвращает: 1 - по возрастанию, -1 - по убыванию, 0 - не отсортирован
int isSorted(const int* array, unsigned int size);

#endif // SORTS_H
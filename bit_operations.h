#ifndef BIT_OPERATIONS_H
#define BIT_OPERATIONS_H

// === ДЗ 2 ===
// Задача 1: Перестановка полуслов (2 байта) в слове (4 байта)
void swapHalfWord(unsigned int* words);

// Задача 2: Циклический сдвиг влево/вправо на N разрядов
void cycleShift(int* number, int N, int left);

// Задача 3: Поиск индекса неотрицательного числа с макс. числом единичных бит
int getMaxBit(const int* array, int N);

// Задача 4: Подсчёт числа единичных бит в числе
unsigned char getCount1Bit(int number);

// === ДЗ 3 ===
// Задача 1: Циклический сдвиг всех чисел в массиве на N бит влево/вправо
void cycleShiftArray(int* array, int size, int N, bool left);

// Задача 2: Установка единичного бита и сброс бита (установка 0)
void setBit(int* number, int numBit);
void clearBit(int* number, int numBit);

#endif // BIT_OPERATIONS_H

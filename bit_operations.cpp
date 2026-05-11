#include "bit_operations.h"

// ========== ДЗ 2 ==========

// Задача 1: Перестановка полуслов (2 байта) в слове (4 байта)
void swapHalfWord(unsigned int* words) {
    unsigned int value = *words;
    *words = ((value & 0xFFFF0000) >> 16) | ((value & 0x0000FFFF) << 16);
}

// Задача 2: Циклический сдвиг влево/вправо на N разрядов
void cycleShift(int* number, int N, int left) {
    unsigned int value = *(unsigned int*)number;
    N = N % 32;
    
    if (N == 0) return;
    
    if (left) {
        *number = (int)((value << N) | (value >> (32 - N)));
    } else {
        *number = (int)((value >> N) | (value << (32 - N)));
    }
}

// Задача 3: Поиск индекса неотрицательного числа с макс. числом единичных бит
int getMaxBit(const int* array, int N) {
    int maxIndex = -1;
    unsigned char maxBits = 0;
    
    for (int i = 0; i < N; i++) {
        if (array[i] >= 0) {
            unsigned char bits = getCount1Bit(array[i]);
            if (bits > maxBits) {
                maxBits = bits;
                maxIndex = i;
            }
        }
    }
    
    return maxIndex;
}

// Задача 4: Подсчёт числа единичных бит в числе
unsigned char getCount1Bit(int number) {
    unsigned char count = 0;
    unsigned int value = *(unsigned int*)&number;
    
    while (value) {
        count += (unsigned char)(value & 1);
        value >>= 1;
    }
    
    return count;
}

// ========== ДЗ 3 ==========

// Задача 1: Циклический сдвиг всех чисел в массиве на N бит влево/вправо
void cycleShiftArray(int* array, int size, int N, bool left) {
    for (int i = 0; i < size; i++) {
        cycleShift(&array[i], N, left ? 1 : 0);
    }
}

// Задача 2: Установка единичного бита (в 1)
void setBit(int* number, int numBit) {
    *number |= (1 << numBit);
}

// Задача 2: Установка нулевого бита (сброс в 0)
void clearBit(int* number, int numBit) {
    *number &= ~(1 << numBit);
}

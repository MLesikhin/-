#include "bit_operations.h"

// Задача 1: Перестановка полуслов (2 байта) в слове (4 байта)
void swapHalfWord(unsigned int* words) {
    unsigned int value = *words;
    // Старшие 16 бит сдвигаем вправо, младшие 16 бит сдвигаем влево
    *words = ((value & 0xFFFF0000) >> 16) | ((value & 0x0000FFFF) << 16);
}

// Задача 2: Циклический сдвиг влево/вправо на N разрядов
void cycleShift(int* number, int N, int left) {
    unsigned int value = *(unsigned int*)number;
    N = N % 32; // Нормализация сдвига
    
    if (N == 0) return;
    
    if (left) {
        // Циклический сдвиг влево
        *number = (int)((value << N) | (value >> (32 - N)));
    } else {
        // Циклический сдвиг вправо
        *number = (int)((value >> N) | (value << (32 - N)));
    }
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

// Задача 3: Поиск индекса неотрицательного числа с макс. числом единичных бит
int getMaxBit(const int* array, int N) {
    int maxIndex = -1;
    unsigned char maxBits = 0;
    
    for (int i = 0; i < N; i++) {
        if (array[i] >= 0) { // Рассматриваем только неотрицательные числа
            unsigned char bits = getCount1Bit(array[i]);
            if (bits > maxBits) {
                maxBits = bits;
                maxIndex = i;
            }
        }
    }
    
    return maxIndex;
}
#include "sorts.h"
#include "HW1.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

// Структура для хранения информации о сортировке
struct SortInfo {
    const char* name;                                    // название сортировки
    void (*sortFunc)(int*, int, bool (*)(int, int));    // указатель на функцию
    bool active;                                         // активна ли сортировка
};

// Функция измерения времени сортировки
double measureSortTime(void (*sortFunc)(int*, int, bool (*)(int, int)), 
                       int* ar, int size, bool (*comp)(int, int)) {
    int* temp = new int[size];
    std::copy(ar, ar + size, temp);
    
    double start = getTime(meas::milli);
    sortFunc(temp, size, comp);
    double end = getTime(meas::milli);
    
    delete[] temp;
    return end - start;
}

int main(int argc, char* argv[]) {
    // Параметры по умолчанию
    int minSize = 10;
    int maxSize = 5000000;
    int stepMultiplier = 5;  // множитель шага (10, 50, 250, 1250...)
    int maxTimeMs = 1000;    // максимальное время в мс (по умолчанию 1 сек)
    const char* outputFile = "sorting_times.txt";
    
    // Разбор аргументов командной строки
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--max_time") == 0 && i + 1 < argc) {
            maxTimeMs = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--min_size") == 0 && i + 1 < argc) {
            minSize = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--max_size") == 0 && i + 1 < argc) {
            maxSize = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--step_size") == 0 && i + 1 < argc) {
            stepMultiplier = atoi(argv[++i]);
        }
    }
    
    std::cout << "Параметры тестирования:" << std::endl;
    std::cout << "  Мин. размер: " << minSize << std::endl;
    std::cout << "  Макс. размер: " << maxSize << std::endl;
    std::cout << "  Множитель шага: " << stepMultiplier << std::endl;
    std::cout << "  Макс. время: " << maxTimeMs << " мс" << std::endl;
    
    // Инициализация массива сортировок
    SortInfo sorts[] = {
        {"Пузырьковая", bubbleSort, true},
        {"Выбором", selectionSort, true},
        {"Вставками", insertionSort, true},
        {"Слиянием", mergeSort, true},
        {"Быстрая", quickSort, true},
        {"Шелла", sortShell, true},
        {"Подсчётом", countSort, true}
    };
    int numSorts = sizeof(sorts) / sizeof(SortInfo);
    
    // Создаём/очищаем файл и записываем заголовок
    FILE* file = fopen(outputFile, "w");
    if (file) {
        fprintf(file, "Элементов\t");
        for (int i = 0; i < numSorts; i++) {
            fprintf(file, "%s", sorts[i].name);
            if (i < numSorts - 1) fprintf(file, "\t");
        }
        fprintf(file, "\n");
        fclose(file);
    }
    
    // Проходим по всем размерам массива
    for (int size = minSize; size <= maxSize; size *= stepMultiplier) {
        if (size > maxSize) size = maxSize;
        
        std::cout << "Тестирование для размера " << size << "..." << std::endl;
        
        // Записываем размер
        char* sizeStr = convertIntToStr(size);
        writeStringToFile(outputFile, sizeStr);
        writeStringToFile(outputFile, "\t");
        delete[] sizeStr;
        
        // Выделяем память и заполняем массив
        int* ar = new int[size];
        
        // Тестируем каждую сортировку
        for (int i = 0; i < numSorts; i++) {
            if (!sorts[i].active) {
                writeStringToFile(outputFile, "---");
            } else {
                // Предварительная оценка для O(n²) алгоритмов на больших размерах
                bool skipByComplexity = false;
                if (strcmp(sorts[i].name, "Пузырьковая") == 0 || 
                    strcmp(sorts[i].name, "Выбором") == 0 || 
                    strcmp(sorts[i].name, "Вставками") == 0) {
                    if (size > 100000) {
                        skipByComplexity = true;
                    }
                }
                
                if (skipByComplexity) {
                    sorts[i].active = false;
                    writeStringToFile(outputFile, "---");
                } else {
                    // Заполняем массив случайными числами
                    randomFillAr(ar, size, -1000, 1000);
                    
                    // Замеряем время
                    double time = measureSortTime(sorts[i].sortFunc, ar, size, defaultComp);
                    
                    if (time > maxTimeMs) {
                        sorts[i].active = false;
                        writeStringToFile(outputFile, "---");
                        std::cout << "  " << sorts[i].name << " превысила лимит времени (" 
                                  << time << " мс) - отключена" << std::endl;
                    } else {
                        char* timeStr = convertDoubleToStr(time);
                        writeStringToFile(outputFile, timeStr);
                        delete[] timeStr;
                        std::cout << "  " << sorts[i].name << ": " << time << " мс" << std::endl;
                    }
                }
            }
            
            if (i < numSorts - 1) {
                writeStringToFile(outputFile, "\t");
            }
        }
        
        writeStringToFile(outputFile, "\n");
        delete[] ar;
        
        // Если достигли maxSize, выходим (для случая когда size установлен в maxSize)
        if (size >= maxSize) break;
    }
    
    std::cout << "\nРезультаты сохранены в файл: " << outputFile << std::endl;
    return 0;
}

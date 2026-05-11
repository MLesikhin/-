#include "HW1.h"
#include <chrono>
#include <random>
#include <cstring>
#include <cstdio>

double getTime(meas unit) {
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = now.time_since_epoch();
    
    switch(unit) {
        case meas::milli:
            return std::chrono::duration<double, std::milli>(duration).count();
        case meas::micro:
            return std::chrono::duration<double, std::micro>(duration).count();
        case meas::nano:
            return std::chrono::duration<double, std::nano>(duration).count();
        case meas::pico:
            return std::chrono::duration<double, std::pico>(duration).count();
        default:
            return std::chrono::duration<double, std::milli>(duration).count();
    }
}

void writeStringToFile(const char* fileName, const char* data) {
    FILE* file = fopen(fileName, "a");
    if (file) {
        fprintf(file, "%s", data);
        fclose(file);
    }
}

char* convertDoubleToStr(double number) {
    char* str = new char[32];
    sprintf(str, "%.2f", number);
    return str;
}

char* convertIntToStr(int number) {
    char* str = new char[32];
    sprintf(str, "%d", number);
    return str;
}

void randomFillAr(int* ar, int size, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(min, max);
    
    for (int i = 0; i < size; i++) {
        ar[i] = dis(gen);
    }
}

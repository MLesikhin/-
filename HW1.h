#ifndef HW1_H
#define HW1_H

// Перечисление единиц измерения времени
enum class meas {
    milli = 1,  // миллисекунды (10^-3)
    micro = 2,  // микросекунды (10^-6)
    nano = 3,   // наносекунды (10^-9)
    pico = 4    // пикосекунды (10^-12)
};

// Прототипы вспомогательных функций
double getTime(meas unit);                                    // возвращает текущее время в указанных единицах
void writeStringToFile(const char* fileName, const char* data);  // запись строки в файл
char* convertDoubleToStr(double number);                     // конвертирование double в строку
char* convertIntToStr(int number);                           // конвертирование int в строку
void randomFillAr(int* ar, int size, int min = -100, int max = 100);  // заполнение массива случайными числами

#endif // HW1_H

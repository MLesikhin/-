#ifndef BOX_H
#define BOX_H

#include <iostream>

struct Box {
    int _len;    // длина
    int _width;  // ширина
    int _height; // высота
    int _color;  // цвет
    int volume;  // объём

    // Конструктор по умолчанию (РК_1)
    Box();
    
    // Конструктор с одним параметром (РК_1)
    Box(int val);
    
    // Конструктор с тремя параметрами: len, width, height (РК_1)
    Box(int len, int width, int height);
};

// Переопределение оператора вывода << (РК_1)
std::ostream& operator<<(std::ostream& os, const Box& box);

// Запись структуры в файл (ДЗ SW_4)
void writeToFile(const char* fileName, const Box& box);

// Чтение структуры из файла (ДЗ SW_4)
void readFromFile(const char* fileName, Box& box);

#endif // BOX_H

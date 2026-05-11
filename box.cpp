#include "box.h"
#include <fstream>

// Конструктор по умолчанию (РК_1)
Box::Box() : _len(10), _width(10), _height(10), _color(0), volume(1000) {}

// Конструктор с одним параметром (РК_1)
Box::Box(int val) : _len(val), _width(val), _height(val), _color(0), volume(val * val * val) {}

// Конструктор с тремя параметрами: len, width, height (РК_1)
Box::Box(int len, int width, int height) 
    : _len(len), _width(width), _height(height), _color(0), volume(len * width * height) {}

// Переопределение оператора вывода << (РК_1)
std::ostream& operator<<(std::ostream& os, const Box& box) {
    os << "len = " << box._len 
       << ", width = " << box._width 
       << ", height = " << box._height 
       << ", volume = " << box.volume;
    return os;
}

// Запись структуры в файл (ДЗ SW_4)
void writeToFile(const char* fileName, const Box& box) {
    std::ofstream outFile(fileName, std::ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char*>(&box), sizeof(Box));
        outFile.close();
    }
}

// Чтение структуры из файла (ДЗ SW_4)
void readFromFile(const char* fileName, Box& box) {
    std::ifstream inFile(fileName, std::ios::binary);
    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char*>(&box), sizeof(Box));
        inFile.close();
    }
}
